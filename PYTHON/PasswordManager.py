import os.path
import random
import pyperclip
import tkinter as tk
from tkinter import ttk


def generate_password():
    length = length_var.get()
    strength = strength_var.get()
    if strength == 1:
        chars = "abcdefghijklmnopqrstuvwxyz"
    elif strength == 2:
        chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    elif strength == 3:
        chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !@#$%^&*()-_"
    else:
        return "Please choose a strength"
    password = ''.join(random.choice(chars) for _ in range(length))
    password_entry.delete(0, tk.END)
    password_entry.insert(0, password)


def copy_password():
    random_password = password_entry.get()
    pyperclip.copy(random_password)


def save_password():
    username = username_entry.get()
    website = website_entry.get()
    password = password_entry.get()
    with open("info.txt", "a") as file:
        file.write("---------------------------------\n")
        file.write(f"UserName: {username}\n")
        file.write(f"Password: {password}\n")
        file.write(f"Website: {website}\n")
        file.write("---------------------------------\n\n")


def read_passwords():
    try:
        with open("info.txt", "r") as file:
            content = file.read()
        print(content)
    except FileNotFoundError:
        print("Password file not found.")


root = tk.Tk()
root.title("Python Password Manager")

length_var = tk.IntVar(value=8)
strength_var = tk.IntVar(value=1)

length_label = tk.Label(root, text="Password Length")
length_label.grid(row=0, column=0, padx=10, pady=10)

length_combo = ttk.Combobox(root, textvariable=length_var, values=list(range(8, 33)))
length_combo.grid(row=0, column=1, padx=10, pady=10)
length_combo.current(0)

strength_label = tk.Label(root, text="Password Strength")
strength_label.grid(row=1, column=0, padx=10, pady=10)

strength_combo = ttk.Combobox(root, textvariable=strength_var, values=[1, 2, 3])
strength_combo.grid(row=1, column=1, padx=10, pady=10)
strength_combo.current(0)

generate_button = tk.Button(root, text="Generate Password", command=generate_password)
generate_button.grid(row=2, column=0, columnspan=2, pady=10)

password_label = tk.Label(root, text="Generated Password")
password_label.grid(row=3, column=0, padx=10, pady=10)

password_entry = tk.Entry(root, width=40)
password_entry.grid(row=3, column=1, padx=10, pady=10)

copy_button = tk.Button(root, text="Copy Password", command=copy_password)
copy_button.grid(row=4, column=0, columnspan=2, pady=10)

username_label = tk.Label(root, text="Username")
username_label.grid(row=5, column=0, padx=10, pady=10)

username_entry = tk.Entry(root, width=40)
username_entry.grid(row=5, column=1, padx=10, pady=10)

website_label = tk.Label(root, text="Website")
website_label.grid(row=6, column=0, padx=10, pady=10)

website_entry = tk.Entry(root, width=40)
website_entry.grid(row=6, column=1, padx=10, pady=10)

save_button = tk.Button(root, text="Save Password", command=save_password)
save_button.grid(row=7, column=0, pady=10)

show_button = tk.Button(root, text="Show All Passwords", command=read_passwords)
show_button.grid(row=7, column=1, pady=10)


root.mainloop()
