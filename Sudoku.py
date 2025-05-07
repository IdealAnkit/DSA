import tkinter as tk
from tkinter import messagebox

# Sample Sudoku puzzle (0 represents empty cells)
puzzle = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9],
]

class SudokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Sudoku Game")
        self.entries = []

        self.build_grid()
        self.create_buttons()

    def build_grid(self):
        for i in range(9):
            row = []
            for j in range(9):
                entry = tk.Entry(self.root, width=3, font=('Arial', 18), justify='center')
                entry.grid(row=i, column=j, padx=1, pady=1)

                if puzzle[i][j] != 0:
                    entry.insert(0, str(puzzle[i][j]))
                    entry.config(state='disabled', disabledforeground='black')
                row.append(entry)
            self.entries.append(row)

    def create_buttons(self):
        tk.Button(self.root, text="Check", command=self.check_solution).grid(row=9, column=0, columnspan=3)
        tk.Button(self.root, text="Solve", command=self.solve_puzzle).grid(row=9, column=3, columnspan=3)
        tk.Button(self.root, text="Reset", command=self.reset_board).grid(row=9, column=6, columnspan=3)

    def get_board(self):
        board = []
        for i in range(9):
            row = []
            for j in range(9):
                val = self.entries[i][j].get()
                row.append(int(val) if val.isdigit() else 0)
            board.append(row)
        return board

    def check_solution(self):
        board = self.get_board()
        if self.is_valid_sudoku(board):
            messagebox.showinfo("Success", "Correct solution!")
        else:
            messagebox.showerror("Error", "Incorrect solution!")

    def is_valid_sudoku(self, board):
        def is_valid_unit(unit):
            unit = [i for i in unit if i != 0]
            return len(unit) == len(set(unit))

        for i in range(9):
            if not is_valid_unit(board[i]) or not is_valid_unit([board[j][i] for j in range(9)]):
                return False

        for box_i in range(0, 9, 3):
            for box_j in range(0, 9, 3):
                block = [board[i][j] for i in range(box_i, box_i+3) for j in range(box_j, box_j+3)]
                if not is_valid_unit(block):
                    return False

        return True

    def solve_puzzle(self):
        board = self.get_board()
        if self.solve(board):
            for i in range(9):
                for j in range(9):
                    self.entries[i][j].delete(0, tk.END)
                    self.entries[i][j].insert(0, str(board[i][j]))
        else:
            messagebox.showerror("Error", "No solution exists!")

    def solve(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == 0:
                    for num in range(1, 10):
                        if self.is_safe(board, i, j, num):
                            board[i][j] = num
                            if self.solve(board):
                                return True
                            board[i][j] = 0
                    return False
        return True

    def is_safe(self, board, row, col, num):
        for i in range(9):
            if board[row][i] == num or board[i][col] == num:
                return False

        box_start_row, box_start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(box_start_row, box_start_row + 3):
            for j in range(box_start_col, box_start_col + 3):
                if board[i][j] == num:
                    return False

        return True

    def reset_board(self):
        for i in range(9):
            for j in range(9):
                self.entries[i][j].config(state='normal')
                self.entries[i][j].delete(0, tk.END)
                if puzzle[i][j] != 0:
                    self.entries[i][j].insert(0, str(puzzle[i][j]))
                    self.entries[i][j].config(state='disabled')


# Start GUI
if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuGUI(root)
    root.mainloop()
