#main.py -- Текстовый редактор JSON файлов
#Copyright (c) 2021, Student Name <lyamzin@cs.karelia.ru>
#This code is licensed under a MIT-style license.

import tkinter  as tk
import json
from tkinter import filedialog

#Функция загрузки файла
def load_file(event):
    file = filedialog.askopenfilename(
        defaultextension = ".json",
        filetypes = [("Текстовые файлы", "*.json"), ("Все файлы", "*.*")],
    )
    if not file:
        return
    with open(file, 'r+') as f:
        jsondata = f.read()
    txt.delete(1.0, tk.END)
    txt.insert(1.0, jsondata)


#Функция сохранения файла
def save_file(event):
    new_file = filedialog.asksaveasfilename(
        defaultextension = ".json",
        filetypes = [("Текстовые файлы", "*.json"), ("Все файлы", "*.*")],
    )
    if not new_file:
        return
    new_jsondata = txt.get("1.0", tk.END)
    if json.load(new_jsondata):
        with open(new_file, "w") as nf:
            nf.write(new_jsondata)
    else:
        error = tk.Tk()
        error.geometry('70x45')
        error.title('Ошибка')
        error_text = tk.Label(text = 'JSON файл не корректен')
        error_text.pack()
        return

#Создание окна
window = tk.Tk()
window.geometry('700x450')
window.title('Редактор JSON')
window.columnconfigure(0, weight = 1, minsize = 300)
window.rowconfigure([0, 1], weight = 1, minsize = 30)

#Создание и размещение текстового поля
txt = tk.Text()
txt.grid(row = 1, column = 0, sticky = 'nsew')

#Создание и размещение кнопок
button_lf = tk.Button(text = "Выбрать файл")
button_lf.bind("<Button-1>", load_file)
button_lf.grid(row = 0, column = 0, sticky = 'w')

button_sf = tk.Button(text = "Сохранить файл")
button_sf.bind("<Button-1>", save_file)
button_sf.grid(row = 0, column = 0, sticky = 'e')

window.mainloop()
