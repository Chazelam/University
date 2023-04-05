from math import sin 

class equilateral_traingle:
    def __init__(self):
        self.a = 0

    def create(self):
        self.a = float(input("Введите расстояние между точками: "))

    def area(self):
        return (self.a**2)*(3**0.5)/4


class parallelogram:
    def __init__(self):
        self.a = 0
        self.b = 0
        self.l = 0 # угол

    def area(self):
        return self.a*self.b*sin(self.l)

# def fn(x):
#     return (2*5! + 3*8!)/(6! + 4!)
#     y = (2+sin 2)/(sin 5 +5) + (6+sin 6)/(sin 3 +3) + (1+sin 1)/(sin 4 +4)

ABC = equilateral_traingle()
ABC.create()
print(ABC.area())