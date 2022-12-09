import pytest
import read_data_from_file as rd
import split_data as sd
import calculate_statistics as cs

# Тест на отсутсвие передаваемого файла
def test_no_file():
    assert rd.read_data_from_file("files/nofile.csv") == -1

# файл не имеет прав на чтение
def test_no_permition():
    assert rd.read_data_from_file("files/no_permition.csv") == -2

# Файл не формата csv
def test_not_csv():
    assert rd.read_data_from_file("files/1.jpg") == -3

# В какой-то из строк файла только одна колонка
def test_one_column():
    assert rd.read_data_from_file("files/one_column.csv") == -5

# данные не заданного типа
def test_not_float():
    assert rd.read_data_from_file("files/not_float_or_int.csv") == -4

#файл делится на нужные интервалы по времени
def test_time_split():
    file = [[1, 3], [4, 5], [6, 14], [7, 23]]
    assert sd.split_data(file, 0, 7) == [[[1, 3], [4, 5]], [[6, 14], [7, 23]]]

#количество интервалов правильное
def test_right_splits():
    file = [[1, 3], [4, 5], [6, 14], [7, 23]]
    assert len(sd.split_data(file, 0, 7)) == 2

#статистики подсчитываются верно
def test_right_statisticks():
    data = [[
      [301.0703125, 234.0],
      [301.984375, 234.0],
      [302.953125, 248.0],
      [303.953125, 256.0],
      [304.93359375, 251.0],
      [305.91796875, 253.0],
    ]]

    statisticks = [246.0, 234.0, 249.5]
    assert cs.calculate_statistics(data) == statisticks
