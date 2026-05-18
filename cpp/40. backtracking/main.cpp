#include <iostream>
#include <array>
#include <cmath>

constexpr int rows = 8;
constexpr int cols = 8;

static std::array<int, cols> board;
static int solutionCount = 0;

bool canPlace(const int row, const int col) {
    // check if we can place a queen at the given position (row, col)
    // check the column
    for (auto i = 0; i < row; ++i) {
        if ( (board[i] == col) || (std::abs(row - i) == std::abs(col - board[i]))) {
            return false;
        }
    }

    return true;
}


void DisplayBoard(void) {
    solutionCount ++;
    std::cout << "Solution #" << solutionCount << std::endl;
    for (auto i = 0; i < rows; ++i) {
        for (auto j = 0; j < cols; ++j) {
            std::cout << (board[i] == j)?"X ":"- ";
        }
        std::cout << std::endl;
    }

    board.fill(0);

    return;
}


int main(int argc, char** argv) {
    int row = 0;
    int col = 0;
    bool solution = false;

    while (row >= 0 && row < rows) {
        col = 0;
        solution = false;
        while (col < cols && !solution) {
            if (canPlace(row, col)) {
                board[row] = col;

                if (row == rows - 1)
                {
                    solution = true;
                    row--;
                    DisplayBoard();
                    std::cout << std::endl;
                } else {
                    row++;
                }
            } else {
                col++;
                if (col >= cols) {
                    row--;
                }
            }
        }
    }

    return 0;
}
