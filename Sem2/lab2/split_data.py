def split_data(a, c):
    begin = int(input('Интервал разбиения с: '))
    end = int(input('до: '))
    split_begin = 0
    while begin > float(a[split_begin][0]):
        split_begin += 1
    split_end = 0
    while end > float(a[split_end][0]):
        split_end += 1
    for k in range(len(a)):
        b = []
        while float(a[split_begin][0]) < k*5:
            b.append(a[split_begin])
            split_begin +=1
            if split_begin >= split_end:
                break
        c.append(b)
        if split_begin >= split_end:
            break
    c.remove([ ])
    return 1