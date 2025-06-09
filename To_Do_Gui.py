# to do list gui
import tkinter as tk
from tkinter import messagebox

tasks = []

def add_task():
    task = entry.get()
    if task:
        tasks.append({"title": task, "done": False})
        update_tasks()
        entry.delete(0, tk.END)
    else:
        messagebox.showwarning("Input Error", "Please enter a task.")

def mark_done():
    selected = listbox.curselection()
    if selected:
        index = selected[0]
        tasks[index]["done"] = True
        update_tasks()
    else:
        messagebox.showwarning("Selection Error", "Select a task to mark as done.")

def delete_task():
    selected = listbox.curselection()
    if selected:
        index = selected[0]
        tasks.pop(index)
        update_tasks()
    else:
        messagebox.showwarning("Selection Error", "Select a task to delete.")

def update_tasks():
    listbox.delete(0, tk.END)
    for task in tasks:
        status = "✅" if task["done"] else "❌"
        listbox.insert(tk.END, f"{task['title']} [{status}]")

# GUI setup
root = tk.Tk()
root.title("To-Do List")
root.geometry("400x400")

frame = tk.Frame(root)
frame.pack(pady=10)

entry = tk.Entry(frame, width=30)
entry.pack(side=tk.LEFT, padx=5)

add_btn = tk.Button(frame, text="Add Task", command=add_task)
add_btn.pack(side=tk.LEFT)

listbox = tk.Listbox(root, width=50, height=15)
listbox.pack(pady=10)

btn_frame = tk.Frame(root)
btn_frame.pack()

done_btn = tk.Button(btn_frame, text="Mark Done", command=mark_done)
done_btn.grid(row=0, column=0, padx=5)

delete_btn = tk.Button(btn_frame, text="Delete Task", command=delete_task)
delete_btn.grid(row=0, column=1, padx=5)

root.mainloop()
