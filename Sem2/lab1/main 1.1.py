#Робот на вход принимает координаты следующей координаты в формате: X, Y.
#Верхний левый угол имеет координату (1,1).
#Робот начинает движение с верхнего левого угла.
#Размеры поля, по которому может перемещаться робот 100x100.

#Xn Yn X - перемещение по горизонтали, Y - перемащение по вертикали
#Возможные значения для X : L - влево, R - вправо
#Возможные значения для Y: U - вверх, D - вниз
#n - число клеток на которое должен переместиться робот
def Coord(a):
    if a == 'L' or a == 'U':
        return -1
    elif a == 'R' or a == 'D':
        return 1
    else:
        print('Некорректное направление')
        return 0

print('Введите команды для перемещения робота в формате Xn Yn:')
command = str(input())
command = command.upper()
command = command.split()
X, Y, y, a =  1, 1, 0, 1
x = int(command[0][1:len(command[0])])
if Coord(command[0][0]) == 0:
    a = 0
if len(command) == 2:
    y = int(command[1][1:len(command[1])])
    if Coord(command[1][0]) == 0:
        a = 0


if a != 0:
    for i in range(x):
        X += Coord(command[0][0])
        if 0 > X or X > 100:
            print('робот вышел за поле')
            break
        print(X, Y)
    
    if 0 <= X and X <= 100:
        for i in range(y):
            Y += Coord(command[1][0])
            if 0 > Y or Y > 100:
                print('робот вышел за поле')
                break
            print(X, Y)
