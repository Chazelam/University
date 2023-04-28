package Sem4.lab6;

import java.awt.*;
import java.awt.event.*;
import java.lang.Math;

class PlotButterfly extends Frame implements ActionListener{
    TextField setA, setB, setC, setD;
    int A = 0, B = 0, C = 0, D = 0;
    Button MyDraw;

    PlotButterfly(){
        setLayout(null);
        setFont(new Font("Serif", Font.PLAIN, 14));

        // Название графика
        Label label = new Label("Butterfly", Label.RIGHT);
        label.setBounds(100, 40, 70, 25); add(label);

        // Формула
        Label lX = new Label("x = sin(A*t + B) * cos(C*t)", Label.RIGHT);
        lX.setBounds(300, 80, 200, 25); add(lX);
        Label lY = new Label("y = sin(A*t + B) * sin(D*t)", Label.RIGHT);
        lY.setBounds(300, 105, 200, 25); add(lY);

        // Поля ввода
        // Ввод А
        Label l1 = new Label("Enter A:", Label.RIGHT);
        l1.setBounds(5, 80, 70, 25); add(l1);
        setA = new TextField(10);
        setA.setBounds(80, 80, 60, 25); add(setA);

        // Ввод В
        Label l2 = new Label("Enter B:", Label.RIGHT);
        l2.setBounds(5, 105, 70, 25); add(l2);
        setB = new TextField(10);
        setB.setBounds(80, 105, 60, 25); add(setB);

        // Ввод C
        Label l4 = new Label("Enter C:", Label.RIGHT);
        l4.setBounds(5, 130, 70, 25); add(l4);
        setC = new TextField(10);
        setC.setBounds(80, 130, 60, 25); add(setC);

        // Ввод D
        Label l3 = new Label("Enter D:", Label.RIGHT);
        l3.setBounds(5, 155, 70, 25); add(l3);
        setD = new TextField(10);
        setD.setBounds(80, 155, 60, 25); add(setD);

        // Кнопка
        MyDraw = new Button("Plot");
        MyDraw.setBounds(160, 80,60,25);
        MyDraw.addActionListener(this); add(MyDraw);

        setSize(700, 450);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent ev) {
                System.exit(0);
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        // Ось Х
        g.drawLine(80, 300, 530, 300);
        g.drawLine(530, 300, 510, 290);
        g.drawLine(530, 300, 510, 310);
        for (int i = 80; i < 500; i+=20){
            g.drawLine(i, 305, i, 295);
            String s = String.valueOf((i - 80)/20 - 11);
            g.drawString(s, i,320);
        }

        // Ось Y
        g.drawLine(300, 150, 300, 500);
        for (int i = 160; i < 500; i+=20){
            g.drawLine(295, i, 305,  i);
            String s = String.valueOf((i - 60)/20 - 12);
            g.drawString(s, 305, i);
        }

        int x = 400, y = 300;
        int xShift = 300;
        int yShift = 300;
        double h=350/3.1415;
        for (int i = 1; i < 1500; i++){
            double t = i*3.1415/350;
            int x1 = (int)(Math.sin(A*t + B)*Math.cos(C*t)*h) + xShift;
            int y1 = (int)(Math.sin(A*t + B)*Math.sin(D*t)*h) + yShift;
            g.drawLine(x, y, x1, y1);
            x = x1; y = y1;
        }
    }

    public void actionPerformed(ActionEvent e){
        if (e.getActionCommand() == "Plot"){
            A = Integer.parseInt(setA.getText());
            B = Integer.parseInt(setB.getText());
            C = Integer.parseInt(setC.getText());
            D = Integer.parseInt(setD.getText());
            repaint();
        }
    }

    public static void main(String args []) {
        new PlotButterfly();
    }
}
