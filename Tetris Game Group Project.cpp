#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <string>  // Login ID ke liye string use karne ke liye

using namespace std;

const vector<vector<vector<int>>> tetrominoes = {
    {{1, 1, 1, 1}}, // I - Cyan
    {{1, 1}, {1, 1}}, // O - Yellow
    {{0, 1, 0}, {1, 1, 1}}, // T - Purple
    {{0, 1, 1}, {1, 1, 0}}, // S - Green
    {{1, 1, 0}, {0, 1, 1}}, // Z - Red
    {{1, 0, 0}, {1, 1, 1}}, // J - Blue
    {{0, 0, 1}, {1, 1, 1}}  // L - Orange
};

class Tetris {
private:
    vector<vector<int>> grid;
    int rows, cols;
    int currentX, currentY;
    vector<vector<int>> currentPiece;
    int pieceType;
    int score;
    bool gameOver;
    HANDLE hConsole;
    string loginID;  // Login ID store karne ke liye

    void setCursorPosition(int x, int y) {
        COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(hConsole, pos);
    }

    void setColor(int color) {
        SetConsoleTextAttribute(hConsole, color);
    }

public:
    // Constructor mein login ID add kiya
    Tetris(const string& id, int r = 20, int c = 10) : loginID(id), rows(r), cols(c), score(0), gameOver(false) {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        grid.resize(rows, vector<int>(cols, 0));
        spawnPiece();
    }

    void spawnPiece() {
        pieceType = rand() % tetrominoes.size();
        currentPiece = tetrominoes[pieceType];
        currentX = cols / 2 - currentPiece[0].size() / 2;
        currentY = 0;
        if (!canFit(currentX, currentY, currentPiece)) {
            gameOver = true;
        }
    }

    bool canFit(int x, int y, const vector<vector<int>>& piece) {
        for (int i = 0; i < piece.size(); i++) {
            for (int j = 0; j < piece[i].size(); j++) {
                if (piece[i][j]) {
                    int newX = x + j;
                    int newY = y + i;
                    if (newX < 0 || newX >= cols || newY >= rows || (newY >= 0 && grid[newY][newX])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void placePiece() {
        for (int i = 0; i < currentPiece.size(); i++) {
            for (int j = 0; j < currentPiece[i].size(); j++) {
                if (currentPiece[i][j]) {
                    grid[currentY + i][currentX + j] = pieceType + 1;
                }
            }
        }
        clearLines();
        spawnPiece();
    }

    void clearLines() {
        int linesCleared = 0;
        for (int i = rows - 1; i >= 0; i--) {
            bool full = true;
            for (int j = 0; j < cols; j++) {
                if (!grid[i][j]) {
                    full = false;
                    break;
                }
            }
            if (full) {
                grid.erase(grid.begin() + i);
                grid.insert(grid.begin(), vector<int>(cols, 0));
                linesCleared++;
            }
        }
        if (linesCleared > 0) {
            score += linesCleared * 100;
        }
    }

    void rotatePiece() {
        vector<vector<int>> rotated(currentPiece[0].size(), vector<int>(currentPiece.size()));
        for (int i = 0; i < currentPiece.size(); i++) {
            for (int j = 0; j < currentPiece[i].size(); j++) {
                rotated[j][currentPiece.size() - 1 - i] = currentPiece[i][j];
            }
        }
        if (canFit(currentX, currentY, rotated)) {
            currentPiece = rotated;
        }
    }

    void movePiece(int dx, int dy) {
        if (canFit(currentX + dx, currentY + dy, currentPiece)) {
            currentX += dx;
            currentY += dy;
        } else if (dy > 0) {
            placePiece();
        }
    }

    void hardDrop() {
        while (canFit(currentX, currentY + 1, currentPiece)) {
            currentY++;
        }
        placePiece();
    }

    void draw() {
        setCursorPosition(0, 0);
        
        int colors[] = {11, 14, 13, 10, 12, 9, 6}; // Cyan, Yellow, Purple, Green, Red, Blue, Orange

        // Top border
        setColor(8); // Gray border
        cout << "##";
        for (int j = 0; j < cols; j++) cout << "##";
        cout << "##\n";

        // Game field
        vector<vector<int>> tempGrid = grid;
        for (int i = 0; i < currentPiece.size(); i++) {
            for (int j = 0; j < currentPiece[i].size(); j++) {
                if (currentPiece[i][j] && currentY + i >= 0) {
                    tempGrid[currentY + i][currentX + j] = pieceType + 1;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            setColor(8); // Gray border
            cout << "##";  // Left border
            for (int j = 0; j < cols; j++) {
                if (tempGrid[i][j]) {
                    setColor(colors[tempGrid[i][j] - 1]); // Piece ka color
                    cout << "[]";
                } else {
                    setColor(7); // Empty space white
                    cout << "  ";
                }
            }
            setColor(8); // Gray border
            cout << "##\n";  // Right border
        }

        // Bottom border
        cout << "##";
        for (int j = 0; j < cols; j++) cout << "##";
        cout << "##\n";

        // Login ID aur score display
        setColor(7); // White text
        cout << "Login ID: " << loginID << "  Score: " << score << "\n";
        cout << "Controls: A/D-Move, S-Drop, Space-HardDrop, W-Rotate, E-Escape, R-Restart\n" << flush;
    }

    void resetGame() {
        grid.assign(rows, vector<int>(cols, 0));
        score = 0;
        gameOver = false;
        spawnPiece();
        // loginID wahi rahega
    }

    char handleInput() {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'a': movePiece(-1, 0); break;
                case 'd': movePiece(1, 0); break;
                case 's': movePiece(0, 1); break;
                case 'w': rotatePiece(); break;
                case 'e': return 'e'; // Exit
                case 'r': return 'r'; // Restart
                case ' ': hardDrop(); break; // Hard drop
            }
        }
        return 0;
    }

    void run() {
        srand(time(0));
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        while (true) {
            while (!gameOver) {
                draw();
                char input = handleInput();
                if (input == 'e') {
                    setCursorPosition(0, rows + 3);
                    setColor(7);
                    cout << "Game Exited, " << loginID << "! Final Score: " << score << endl;
                    return;
                }
                if (input == 'r') {
                    resetGame();
                    continue;
                }
                movePiece(0, 1);
                Sleep(150);
            }
            draw();
            setCursorPosition(0, rows + 3);
            setColor(7);
            cout << "Game Over, " << loginID << "! Final Score: " << score << "\n";
            setCursorPosition(0, rows + 4);
            cout << "Press R to restart or E to exit\n";
            while (true) {
                char input = handleInput();
                if (input == 'r') {
                    resetGame();
                    break;
                }
                if (input == 'e') {
                    setCursorPosition(0, rows + 5);
                    cout << "Goodbye, " << loginID << "!\n";
                    return;
                }
                Sleep(101);
            }
        }
    }
};

// Login screen ke liye function
string showTitleScreen() {
    system("cls");
    cout << "==========================================\n";
    cout << "|            WELCOME TO TETRIS           |\n";
    cout << "==========================================\n";
    cout << "|   Prepare for the ultimate challenge!  |\n";
    cout << "==========================================\n\n";
    cout << "Enter your login ID: ";
    string loginID;
    getline(cin, loginID);
    if (loginID.empty()) {
        loginID = "Player";
    }
    cout << "\nHello, " << loginID << "!\n";
    cout << "Press any key to start the game...\n";
    _getch();
    system("cls");
    return loginID;
}

int main() {
    string loginID = showTitleScreen();  // Login ID lene ke liye
    Tetris game(loginID);  // Game object banaya login ID ke saath
    game.run();  // Game shuru
    return 0;
}
