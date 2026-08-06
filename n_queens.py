class NQueens:
    def __init__(self, n):
        self.n = n
        self.solutions = []

    def is_safe(self, board, row, col):
        # Check this row on left side
        for i in range(col):
            if board[row][i] == 1:
                return False

        # Check upper diagonal on left side
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        # Check lower diagonal on left side
        for i, j in zip(range(row, self.n), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        return True

    def solve_n_queens_util(self, board, col):
        if col >= self.n:
            self.solutions.append(self.create_solution(board))
            return

        for i in range(self.n):
            if self.is_safe(board, i, col):
                board[i][col] = 1  # Place queen

                self.solve_n_queens_util(board, col + 1)  # Recur

                board[i][col] = 0  # Backtrack

    def create_solution(self, board):
        return [''.join('Q' if cell == 1 else '.' for cell in row) for row in board]

    def solve_n_queens(self):
        board = [[0] * self.n for _ in range(self.n)]
        self.solve_n_queens_util(board, 0)
        return self.solutions


if __name__ == "__main__":
    n = 4
    n_queens = NQueens(n)
    solutions = n_queens.solve_n_queens()
    for solution in solutions:
        for row in solution:
            print(row)
        print()
