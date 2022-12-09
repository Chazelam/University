import read_data_from_file
import split_data
import calculate_statistics

original_file = []
splitted_to_intervals = []
read_data_from_file.read_data_from_file(original_file)
split_data.split_data(original_file, splitted_to_intervals)
calculate_statistics.calculate_statistics(splitted_to_intervals)