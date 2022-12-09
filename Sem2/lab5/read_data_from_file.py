import csv
from pathlib import Path

# Коды ошибок:
# -1 FileNotFoundError
# -2 PermissionError
# -3 Неверное расширие файла
# -4 Ошибка данных
# -5 Одна из колонок пуста

def read_data_from_file(path):
    data = []
    # Проверка на тип файла
    if Path(path).suffix != '.csv':
        return -3

    # Проверка исключений
    try:
        # Чтение файла
        with open(path) as file:
            data_reader = csv.reader(file)
            for i in data_reader:
                # Проверка на пустую колонку
                if len(i) != 2:
                    return -5

                data.append(i)
            data.pop(0)

    # Файлне существовует
    except FileNotFoundError:
        return -1

    # Проверка на возможность чтения
    except PermissionError:
        return -2

    result_array = []

    # Преобразование к типу float
    try:
        for i in range(len(data)):
            result_array.append(list(map(float, data[i])))
    except ValueError:
        return -4
    return result_array
