def split_data(original_file, begin, end):
    splitted_to_intervals = []
    split_begin = 0
    while begin > float(original_file[split_begin][0]):
        split_begin += 1
    split_end = 0
    while end > float(original_file[split_end][0]):
        split_end += 1
    split_end += 1
    for k in range(len(original_file)):
        b = []
        while float(original_file[split_begin][0]) < k*5:
            b.append(original_file[split_begin])
            split_begin +=1
            if split_begin >= split_end:
                break
        splitted_to_intervals.append(b)
        if split_begin >= split_end:
            break
    splitted_to_intervals.pop(0)
    return splitted_to_intervals
