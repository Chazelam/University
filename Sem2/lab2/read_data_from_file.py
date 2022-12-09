import csv

def read_data_from_file(a):
    file_name = input('Введите название файла: ')
    with open(file_name) as csv_file:
        read = csv.reader(csv_file, delimiter=',')
        for i in read:
            a.append(i)
    return 1