import tkinter as tk

def button_click(number):
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(tk.END, current + str(number))

def button_clear():
    entry.delete(0, tk.END)

def button_equal():
    try:
        result = eval(entry.get())  # Evaluate the expression
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(result))  # Insert the result
    except:
        entry.delete(0, tk.END)
        entry.insert(tk.END, "Error")  # Show "Error" for invalid input

def button_backspace():
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(tk.END, current[:-1])  # Remove the last character

def on_key_press(event):
    char = event.char
    if char.isdigit() or char in "+-*/.":
        button_click(char)
    elif char == "\r":  # Enter key
        button_equal()
    elif char == "\x08":  # Backspace key
        button_backspace()

# Create the main window
window = tk.Tk()
window.title("Calculator")

# Create entry widget to display the numbers and results
entry = tk.Entry(window, width=16, font=('Arial', 24), borderwidth=5, justify='right')
entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# Define the buttons (text, row, column)
buttons = [
    ("7", 1, 0), ("8", 1, 1), ("9", 1, 2), ("/", 1, 3),
    ("4", 2, 0), ("5", 2, 1), ("6", 2, 2), ("*", 2, 3),
    ("1", 3, 0), ("2", 3, 1), ("3", 3, 2), ("-", 3, 3),
    ("0", 4, 0), (".", 4, 1), ("+", 4, 3)
]

# Create buttons and assign their respective functions
for button_text, row, col in buttons:
    button = tk.Button(window, text=button_text, padx=20, pady=20, font=('Arial', 18),
                       command=lambda text=button_text: button_click(text))
    button.grid(row=row, column=col, padx=5, pady=5)

# Create special buttons: Clear, Backspace, Equal
clear_button = tk.Button(window, text="Clear", padx=20, pady=20, font=('Arial', 18), command=button_clear)
clear_button.grid(row=5, column=0, padx=5, pady=5)

backspace_button = tk.Button(window, text="⌫", padx=20, pady=20, font=('Arial', 18), command=button_backspace)
backspace_button.grid(row=5, column=1, padx=5, pady=5)

equal_button = tk.Button(window, text="=", padx=20, pady=20, font=('Arial', 18), command=button_equal)
equal_button.grid(row=4, column=2, columnspan=2, padx=5, pady=5)

# Bind keyboard input to the calculator
window.bind("<Key>", on_key_press)

# Start the main loop
window.mainloop()
