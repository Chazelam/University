package Sem4.lab4;

import java.awt.*;
import java.awt.event.*;
import java.lang.Math;

class Rocket extends Frame {
    Rocket(){
        setSize(450, 300);
        setBackground(Color.lightGray);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        g.setColor(Color.black);
        g.fillRect(200, 100, 50, 150);
        g.setColor(Color.white);
        g.fillOval(210, 110, 30, 30);
        g.setColor(Color.white);
        int xRoof[] = {200, 225, 250};
        int yRoof[] = {100, 50, 100};
        g.fillPolygon(xRoof, yRoof, 3);
        int xStabilizer1[] = {200, 175, 200};
        int yStabilizer1[] = {200, 250, 250};
        g.fillPolygon(xStabilizer1, yStabilizer1, 3);
        int xStabilizer2[] = {250, 275, 250};
        int yStabilizer2[] = {200, 250, 250};
        g.fillPolygon(xStabilizer2, yStabilizer2, 3);
    }
}
class SquarRecursion extends Frame {
    SquarRecursion(){
        setSize(450, 300);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        g.setColor(Color.black);
        int x12[] = {100, 160, 160, 100};
        int y12[] = {100, 100, 160, 160};
        g.drawPolygon(x12, y12, 4);
        int newX12[] = new int[4];
        int newY12[] = new int[4];
        g.drawLine(50, 50, 50, 210);
        g.drawLine(40, 200, 200, 200);
        for (int j = 1; j<40;  j++){
            for (int i = 0; i<4; i++){
                int n;
                if (i != 3){
                    n = i + 1;
                } else{
                    n = 0;
                }
                double vector[] = {x12[n] - x12[i], y12[n] - y12[i]};
                vector[0] = vector[0] * 0.08;
                vector[1] = vector[1] * 0.08;
                newX12[i] = (int)vector[0] + x12[i];
                newY12[i] = (int)vector[1] + y12[i];
                System.out.print(newX12[i]);
                System.out.print("\n");
            }
            g.drawPolygon(newX12, newY12, 4);
            x12 = newX12.clone();
            y12 = newY12.clone();
        }
    }
}
class CircleRecursion extends Frame {
    CircleRecursion(){
        setSize(400, 400);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        int X = 100;
        int Y = 100;
        int W = 200;
        int H = 200;
        g.drawOval(X, Y, W, H);
        rec(X, Y, W, H, 4, g);
    }
    private void rec(int X, int Y, int W, int H, int n, Graphics g){
        if (n>0)
        {n--;
            int nX = (int)(X - H/4);
            int nY = (int)(Y + H/4);
            g.drawOval(nX, nY, W/2, H/2);
            rec(nX, nY, W/2, H/2, n, g);
            nX = (int)(X + H/4);
            nY = (int)(Y - H/4);
            g.drawOval(nX, nY, W/2, H/2);
            rec(nX, nY, W/2, H/2, n, g);
            nX = (int)(X + 3*H/4);
            nY = (int)(Y + H/4);
            g.drawOval(nX, nY, W/2, H/2);
            rec(nX, nY, W/2, H/2, n, g);
            nX = (int)(X + H/4);
            nY = (int)(Y + 3*H/4);
            g.drawOval(nX, nY, W/2, H/2);
            rec(nX, nY, W/2, H/2, n, g);
        }
    }
}

class SimpleGraphics {
    private Graphics g = null;
    private int x = 0, y = 0;

    public SimpleGraphics(Graphics g) {
        setGraphics(g);
    }

    public void setGraphics(Graphics g) {
        this.g = g;
    }

    public void goToXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void lineRel(char s, int deltaX, int deltaY) {
        g.drawLine(x, y, x + deltaX, y + deltaY);
        x += deltaX;
        y += deltaY;
    }
}
class SierpinskiСurve extends Frame {
    private SimpleGraphics sg = null;
    private int dist0 = 128, dist;
    private Image offscrBuf;
    private Graphics offscrGfx;

    SierpinskiСurve(){
        sg = new SimpleGraphics(getGraphics());
        setSize(700, 700);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g) {

        if (g == null)
            throw new NullPointerException();

        if (offscrBuf == null) {
            offscrBuf = createImage(this.getWidth(), this.getHeight());
            offscrGfx = offscrBuf.getGraphics();
            sg.setGraphics(offscrGfx);
        }

        int level = 1;
        dist = dist0;
        for (int i = level; i > 0; i--)
            dist /= 2;
        sg.goToXY(2 * dist, dist);
        sierpA(level); // start recursion
        sg.lineRel('X', +dist, +dist);
        sierpB(level); // start recursion
        sg.lineRel('X', -dist, +dist);
        sierpC(level); // start recursion
        sg.lineRel('X', -dist, -dist);
        sierpD(level); // start recursion
        sg.lineRel('X', +dist, -dist);

        g.drawImage(offscrBuf, 0, 0, this);

    }

    private void sierpA(int level) {
        if (level > 0) {
            sierpA(level - 1);
            sg.lineRel('A', +dist, +dist);
            sierpB(level - 1);
            sg.lineRel('A', +2 * dist, 0);
            sierpD(level - 1);
            sg.lineRel('A', +dist, -dist);
            sierpA(level - 1);
        }
    }

    private void sierpB(int level) {
        if (level > 0) {
            sierpB(level - 1);
            sg.lineRel('B', -dist, +dist);
            sierpC(level - 1);
            sg.lineRel('B', 0, +2 * dist);
            sierpA(level - 1);
            sg.lineRel('B', +dist, +dist);
            sierpB(level - 1);
        }
    }

    private void sierpC(int level) {
        if (level > 0) {
            sierpC(level - 1);
            sg.lineRel('C', -dist, -dist);
            sierpD(level - 1);
            sg.lineRel('C', -2 * dist, 0);
            sierpB(level - 1);
            sg.lineRel('C', -dist, +dist);
            sierpC(level - 1);
        }
    }

    private void sierpD(int level) {
        if (level > 0) {
            sierpD(level - 1);
            sg.lineRel('D', +dist, -dist);
            sierpA(level - 1);
            sg.lineRel('D', 0, -2 * dist);
            sierpC(level - 1);
            sg.lineRel('D', -dist, -dist);
            sierpD(level - 1);
        }
    }
}

class Atom extends Frame {
    Atom(){
        setSize(450, 450);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        int X, Y, nX, nY;
        int a = 150; int b = 40;
        int l1 = 40; int l2 = 130;
        for (int i = 0; i<360; i++){
            double t = i*3.1415/180;
            X = (int)(a*Math.cos(t));
            Y = (int)(b*Math.sin(t));
            nX = (int)(X*Math.cos(l1) + Y*Math.sin(l1)) + 200;
            nY = (int)(Y*Math.cos(l1) - X*Math.sin(l1)) + 200;
            g.drawOval(nX, nY, 1, 1);

            nX = (int)(X*Math.cos(l2) + Y*Math.sin(l2)) + 200;
            nY = (int)(Y*Math.cos(l2) - X*Math.sin(l2)) + 200;
            g.drawOval(nX, nY, 1, 1);
        }
        for (int t = 0; t<360; t++){
            X = (int)(a*Math.cos(t)) + 200;
            Y = (int)(b*Math.sin(t)) + 200;
            g.drawOval(X, Y, 1, 1);
        }
        for (int t = 0; t<360; t++){
            X = (int)(5*Math.cos(t)) + 200;
            Y = (int)(5*Math.sin(t)) + 200;
            g.fillOval(X, Y, 5, 5);
        }
    }
}
class Four extends Frame {
    Four(){
        setSize(450, 450);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        int x = 0, y = 0;
        double A = 110.3, B = 1.9, C = -42.1;
        for (int i = 0; i<20000; i++){
            x = (int)(y - Math.signum(x)*(Math.sqrt(Math.abs(B*x - C))));
            y = (int)(A - x);
            g.drawLine(x+200, y+200, x+200, y+200);
        }
    }
}

class Program{
    public static void main(String[] args) {
        // new Rocket();
        // new SquarRecursion();
        // new CircleRecursion();
        new SierpinskiСurve();
        // new Atom();
        // new Four();
    }
}