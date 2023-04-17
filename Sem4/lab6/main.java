package Sem4.lab6;

import java.awt.*;
import java.awt.event.*;
import java.lang.Math;

class Plot extends Frame implements ActionListener{
    TextField setA;
    TextField setB;
    Button MyDraw;
    int A = 0; //5
    int B = 0; //11

    Plot(){
        setSize(700, 450);
        setLayout(null);
        setA = new TextField(10);
        setA.setBounds(10, 38, 60, 25);
        add(setA);

        setB = new TextField(10);
        setB.setBounds(10, 63, 60, 25);
        add(setB);

        MyDraw = new Button("Старт");
        MyDraw.setBounds(10,138,60,25);
        MyDraw.addActionListener(this);
        add(MyDraw);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        int x, y;
        double h = 15;
        for (int i = 1; i < 500; i++){
            double t = i*3.1415/250;
            x = (int)((A*Math.cos(t)*Math.cos(t) + B*Math.cos(t))*h)+200;
            y = (int)((A*Math.cos(t)*Math.sin(t) + B*Math.sin(t))*h)+250;
            g.drawOval(x, y, 1, 1);
        }
    }

    public void actionPerformed(ActionEvent e){
        if (e.getActionCommand() == "Старт"){    
            A = Integer.parseInt(setA.getText());
            B = Integer.parseInt(setB.getText());
            repaint();
        }
    }

    public static void main(String args []) {
        new Plot();
    }
}
