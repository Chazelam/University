package Sem4.lab4;

import java.awt.*;
import java.awt.event.*;

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

class Program{
    public static void main(String[] args) {
        new Rocket();
    }
}