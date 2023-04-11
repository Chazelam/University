import java.util.Scanner;
import java.lang.Math;


class calculate {
    public static void main(String[] args) {
        int x = (2 * calculate.factorial(5) + 3 * calculate.factorial(8)) / (calculate.factorial(6) + calculate.factorial(4));
        System.out.println(x);
        double y = (2+Math.sin(2))/(Math.sin(5) +5) + (6+Math.sin(6))/(Math.sin(3) +3) + (1+Math.sin(1))/(Math.sin(4) +4);
        System.out.println(y);
        // Найти пириметр ABCD по заданным сторонам AB, AC и DC
        // BAC, BCD - Прямоугольные треугольники
        Scanner in = new Scanner(System.in);
        System.out.print("Enter AB - ");  
        double AB = in.nextInt();  
        System.out.print("Enter AC - ");  
        double AC = in.nextInt(); 
        System.out.print("Enter DC - ");  
        double DC = in.nextInt();
        double BC = calculate.hypotenuse(AC, AB);
        double BD = calculate.hypotenuse(BC,DC);
        double Perimeter = AB + AC + DC + BD;
        System.out.println(Perimeter);
        // Треуголник
        double[] a = {1.9, 2.9};
        double[] b = {1, 2};
        double[] c = {3, 4};
        double Per2 = calculate.len(a, b) + calculate.len(b, c) + calculate.len(c, a);
        System.out.println(Per2);
        int f = 1;
        int g = 1;
        double z = (calculate.square(f)+calculate.square(g)) / calculate.square(f*g);
        System.out.println(z);
    }

    static int factorial(int n) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    static double hypotenuse(double a, double b) {
        return Math.sqrt(a*a + b*b);
    }

    static double len(double[] begin, double[] end) {
        return Math.sqrt((end[0] - begin[0])*(end[0] - begin[0]) + (end[1] - begin[1])*(end[1] - begin[1]));
    }

    static int square(int a){
        return a*a;
    }
}

// абстрактный класс фигуры
abstract class Figure{
     
    float x; // x-координата точки
    float y; // y-координата точки
  
    
    public abstract void create();
    public abstract double area();
}

class Equilateral_traingle extends Figure
{
    private float a;
    Equilateral_traingle() {
        this.a = 0;
    }
     
    public double area(){
        return (Math.sqrt(3)/4)*a*a;
    }
    public void create(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a - ");
        this.a = sc.nextInt();
    }
}

class Isosceles_trapezium extends Figure{
    private float a;
    private float b;
    private float c;
    Isosceles_trapezium() {
        this.a = 0;
        this.b = 0;
        this.c = 0;

    }
     
    public double area(){
        return ((a + b)/4)*Math.sqrt(4*c*c - (a - b)*(a - b));
    }
    public void create(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a - ");
        this.a = sc.nextInt();
        System.out.print("Enter b - ");
        this.b = sc.nextInt();
        System.out.print("Enter c - ");
        this.c = sc.nextInt();
    }
}

class Program{
    public static void main(String[] args) {
        Equilateral_traingle t = new Equilateral_traingle();
        t.create();
        System.out.println(t.area()); 

        Isosceles_trapezium tr = new Isosceles_trapezium();
        tr.create();
        System.out.println(tr.area()); 
    }
}