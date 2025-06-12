import tkinter as tk
from tkinter import messagebox

# Initial Sudoku puzzle (0 = empty)
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
        self.root.minsize(500, 550)

        self.entries = [[None for _ in range(9)] for _ in range(9)]
        self.create_grid()
        self.create_buttons()

    def create_grid(self):
        # Parent frame to center everything
        self.center_frame = tk.Frame(self.root)
        self.center_frame.pack(expand=True, fill='both')

        # Actual game board frame
        self.board_frame = tk.Frame(self.center_frame, bg="black", bd=2)
        self.board_frame.place(relx=0.5, rely=0.5, anchor='center')  # Centering

        vcmd = (self.root.register(self.validate_entry), '%P')

        for block_row in range(3):
            for block_col in range(3):
                subgrid = tk.Frame(self.board_frame, bg="black", bd=2)
                subgrid.grid(row=block_row, column=block_col, padx=2, pady=2)

                for i in range(3):
                    for j in range(3):
                        row = block_row * 3 + i
                        col = block_col * 3 + j
                        entry = tk.Entry(subgrid, width=3, font=('Arial', 18), justify='center',
                                         validate='key', validatecommand=vcmd)
                        entry.grid(row=i, column=j, padx=1, pady=1)

                        if puzzle[row][col] != 0:
                            entry.insert(0, str(puzzle[row][col]))
                            entry.config(state='disabled', disabledforeground='black')

                        self.entries[row][col] = entry

    def create_buttons(self):
        button_frame = tk.Frame(self.root)
        button_frame.pack(pady=10)

        tk.Button(button_frame, text="Check", command=self.check_solution, width=10).pack(side='left', padx=10)
        tk.Button(button_frame, text="Solve", command=self.solve_puzzle, width=10).pack(side='left', padx=10)
        tk.Button(button_frame, text="Reset", command=self.reset_board, width=10).pack(side='left', padx=10)

    def validate_entry(self, new_value):
        if new_value == "":
            return True
        if new_value.isdigit() and 1 <= int(new_value) <= 9:
            return True
        self.root.bell()  # Sound alert
        return False

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
                    self.entries[i][j].config(state='normal')
                    self.entries[i][j].delete(0, tk.END)
                    self.entries[i][j].insert(0, str(board[i][j]))
                    if puzzle[i][j] != 0:
                        self.entries[i][j].config(state='disabled')
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
# Run the game

if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuGUI(root)
    root.mainloop()
