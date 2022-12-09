def way(a):
    global direction, axis
    if a == 'L':
        direction = -1
        axis = 0
        return 1
    elif a == 'R':
        direction = 1
        axis = 0
        return 1
    elif a == 'D':
        direction = 1
        axis = 1
        return 1
    elif a == 'U':
        direction = -1
        axis = 1
        return 1
    else:
        print('Некорректное направление')
        return 0

print('Введите команды для перемещения робота в формате Xn Yn:')
command = str(input())
command = command.replace(',', ' ')
command = command.upper()
command = command.split()
axis, direction, y, a = 0, 0, 0, 1
coord = [1, 1]
x = int(command[0][1:len(command[0])])
if (command[0][0]) == 0:
    a = 0
if len(command) == 2:
    y = int(command[1][1:len(command[1])])
    if way(command[1][0]) == 0:
        a = 0
        
if a != 0:
    for i in range(x):
        way(command[0][0])
        coord[axis] += direction
        if 0 > coord[axis] or coord[axis] > 100:
            print('робот вышел за поле')
            break
        print(coord[0], coord[1])
    
    if 0 <= coord[axis] or coord[axis] <= 100:
        for i in range(y):
            way(command[1][0])
            coord[axis] += direction
            if 0 > coord[axis] or coord[axis] > 100:
                print('робот вышел за поле')
                break
            print(coord[0], coord[1])
else:
    print('команда написана не верно')