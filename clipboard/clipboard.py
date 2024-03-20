import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk

class ClipboardApp:
    def __init__(self, root):
        self.root = root
        self.root.title("CLIPBOARD APP")
        self.root.geometry("")

        self.copy_icon = ImageTk.PhotoImage(Image.open("copy.png").resize((32, 32)))
        self.paste_icon = ImageTk.PhotoImage(Image.open("paste.png").resize((32, 32)))
        self.clear_icon = ImageTk.PhotoImage(Image.open("clear.png").resize((32, 32)))

        self.text = tk.Text(self.root, wrap="word", font=("Arial", 12))
        self.text.pack(fill="both", expand=True, padx=20, pady=(20, 10))

        self.copy_button = ttk.Button(self.root, image=self.copy_icon, command=self.copy)
        self.copy_button.pack(side="left", padx=(20, 5), pady=(0, 20))
        self.paste_button = ttk.Button(self.root, image=self.paste_icon, command=self.paste)
        self.paste_button.pack(side="left", padx=5, pady=(0, 20))
        self.clear_button = ttk.Button(self.root, image=self.clear_icon, command=self.clear)
        self.clear_button.pack(side="left", padx=5, pady=(0, 20))

    def copy(self):
        try:
            text = self.text.get("sel.first", "sel.last")
            self.root.clipboard_clear()
            self.root.clipboard_append(text)
        except tk.TclError:
            pass

    def paste(self):
        try:
            text = self.root.clipboard_get()
            self.text.insert("insert", text)
        except tk.TclError:
            pass

    def clear(self):
        self.text.delete("1.0", "end")

def main():
    root = tk.Tk()
    app = ClipboardApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
