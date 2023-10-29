#include <iostream>
#include <cmath>

using namespace std;

const int N = 9;

bool check_row(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool check_col(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool check_box(int grid[N][N], int row, int col, int num) {
    int box_x = floor(row / 3) * 3;
    int box_y = floor(col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + box_x][j + box_y] == num) {
                return false;
            }
        }
    }
    return true;
}

bool is_safe(int grid[N][N], int row, int col, int num) {
    return check_row(grid, row, num) && check_col(grid, col, num) && check_box(grid, row, col, num);
}

bool solve_sudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] != 0) {
        return solve_sudoku(grid, row, col + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
		{0, 0, 0, 2, 6, 0, 7, 0, 1},
		{6, 8, 0, 0, 7, 0, 0, 9, 0},
		{1, 9, 0, 0, 0, 4, 5, 0, 0},
		{8, 2, 0, 1, 0, 0, 0, 4, 0},
		{0, 0, 4, 6, 0, 2, 9, 0, 0},
		{0, 5, 0, 0, 0, 3, 0, 2, 8},
		{0, 0, 9, 3, 0, 0, 0, 7, 4},
		{0, 4, 0, 0, 5, 0, 0, 3, 6},
		{7, 0, 3, 0, 1, 8, 0, 0, 0}
		};
	if (solve_sudoku(grid, 0, 0)) {
		cout << "Solution:" << endl;
		print_grid(grid);
	} else {
		cout << "No solution exists." << endl;
	}
return 0;
}
