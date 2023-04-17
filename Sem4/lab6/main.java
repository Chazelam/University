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
        setLayout(null);
        setFont(new Font("Serif", Font.PLAIN, 14));

        Label label = new Label("Pascal sanil", Label.RIGHT);
        label.setBounds(100, 40, 70, 25);
        add(label);
            
        Label lX = new Label("x = A*cos(t)^2 + B*cos(t)", Label.RIGHT);
        lX.setBounds(300, 80, 200, 25);
        add(lX);

        Label lY = new Label("y = A*cos(t)*sin(t) + B*sin(t)", Label.RIGHT);
        lY.setBounds(300, 105, 200, 25);
        add(lY);

        Label l1 = new Label("Enter A:", Label.RIGHT);
        l1.setBounds(5, 80, 70, 25);
        add(l1);

        setA = new TextField(10);
        setA.setBounds(80, 80, 60, 25);
        add(setA);

        Label l2 = new Label("Enter B:", Label.RIGHT);
        l2.setBounds(5, 105, 70, 25);
        add(l2);
        
        setB = new TextField(10);
        setB.setBounds(80, 105, 60, 25);
        add(setB);

        MyDraw = new Button("Plot");
        MyDraw.setBounds(160, 80,60,25);
        MyDraw.addActionListener(this);
        add(MyDraw);

        setSize(700, 450);
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
        int xShift = 30;
        int yShift = 300;
        for (int i = 1; i < 500; i++){
            double t = i*3.1415/250;
            x = (int)((A*Math.cos(t)*Math.cos(t) + B*Math.cos(t))*h)+xShift;
            y = (int)((A*Math.cos(t)*Math.sin(t) + B*Math.sin(t))*h)+yShift;
            g.drawOval(x, y, 1, 1);
        }
    }

    public void actionPerformed(ActionEvent e){
        if (e.getActionCommand() == "Plot"){    
            A = Integer.parseInt(setA.getText());
            B = Integer.parseInt(setB.getText());
            repaint();
        }
    }

    public static void main(String args []) {
        new Plot();
    }
}
