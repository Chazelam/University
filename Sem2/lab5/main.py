import read_data_from_file
import split_data
import calculate_statistics

if __name__ == "__main__":
    file_name = input('Введите название файла: ')
    data = read_data_from_file.read_data_from_file(file_name)
    if data == -1:
        print("Файл не найден")
    elif data == -2:
        print("Ошибка доступа к файлу")
    elif data == -3:
        print("Неверное расширие файла")
    elif data == -4 or data == -5:
        print("Ошибка данных")
    else:
        begin = int(input('Интервал разбиения с: '))
        end = int(input('до: '))
        splitted_to_intervals = split_data.split_data(data, begin, end)
        calculate_statistics.calculate_statistics(splitted_to_intervals)
