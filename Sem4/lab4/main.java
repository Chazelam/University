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

class MachineGraf extends Frame {
    MachineGraf(){
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
        // int x12[] = {100, 160, 160, 100};
        // int y12[] = {100, 100, 160, 160};
        int x12[] = {0, 60, 60, 0};
        int y12[] = {0, 0, 60, 60};
        int newX12[] = new int[4];
        int newY12[] = new int[4];
        g.drawLine(50, 50, 50, 210);
        g.drawLine(40, 200, 200, 200);
        
        for (int t =0; t<=1;  t++){
            // double cos = Math.cos(t*10);
            // double sin = Math.sin(t*10);
            int k = (int)((x12[0] - (x12[1]*Math.pow(0.9, t)))/2);
            for (int i = 0; i<4; i++){
                int newX = (int)((x12[i]*Math.pow(0.9, t)));//(int)((x12[i]*cos + y12[i]*sin)*k + 100);
                int newY = (int)((y12[i]*Math.pow(0.9, t)));//- (int)((y12[i]*cos - x12[i]*sin)*k + 300);
                // System.out.print(k);
                // System.out.print("\n");
                newX12[i] = newX +100 + k;
                newY12[i] = newY +100 + k;
                x12[i] = newX;
                y12[i] = newY;
                
            }
            g.drawPolygon(newX12, newY12, 4);
        }

    }
}

class Program{
    public static void main(String[] args) {
        new Rocket();
        new MachineGraf();
    }
}