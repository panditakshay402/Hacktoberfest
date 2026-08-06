class SudokuSolver:
    def __init__(self, board):
        self.board = board

    def is_safe(self, row, col, num):
        # Check if num is not in current row
        for x in range(9):
            if self.board[row][x] == num:
                return False

        # Check if num is not in current column
        for x in range(9):
            if self.board[x][col] == num:
                return False

        # Check if num is not in current 3x3 box
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if self.board[i + start_row][j + start_col] == num:
                    return False
        return True

    def solve_sudoku(self):
        empty_cell = self.find_empty_cell()
        if not empty_cell:
            return True  # Puzzle solved

        row, col = empty_cell

        for num in range(1, 10):
            if self.is_safe(row, col, num):
                self.board[row][col] = num

                if self.solve_sudoku():
                    return True

                self.board[row][col] = 0  # Backtrack

        return False  # Trigger backtracking

    def find_empty_cell(self):
        for i in range(9):
            for j in range(9):
                if self.board[i][j] == 0:
                    return (i, j)  # Row, col
        return None


if __name__ == "__main__":
    board = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]

    sudoku_solver = SudokuSolver(board)
    if sudoku_solver.solve_sudoku():
        for row in sudoku_solver.board:
            print(row)
    else:
        print("No solution exists.")
