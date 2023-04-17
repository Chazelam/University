package Sem4.lab6;

import java.awt.*;
import java.awt.event.*;
import java.lang.Math;

class Plot extends Frame {
    Plot(){
        setSize(450, 450);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        int x, y, A = 5, B = 11;
        double h = 15;
        for (int i = 1; i < 500; i++){
            double t = i*3.1415/250;
            x = (int)((A*Math.cos(t)*Math.cos(t) + B*Math.cos(t))*h)+200;
            y = (int)((A*Math.cos(t)*Math.sin(t) + B*Math.sin(t))*h)+250;
            g.drawOval(x, y, 1, 1);
        }
    }
}


class Program{
    public static void main(String[] args) {
        new Plot();
    }
}