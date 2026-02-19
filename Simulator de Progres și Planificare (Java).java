//M-am apucat de sala.In prima sap am fost de 3 ori iar in a 2 a de 4 ori.In fiecare sap vreau sa cresc nr de antrenamente
//cu 1 dar fara sa depasesc 6 pe sap .De cate ori voi merge in a 3 a sap si cate antrenamente voi avea in total dupa 4 sap?
import javax.swing.JOptionPane;
public class ex2 {
    public static void main(String[] args) {
        int sap1=3;
        int sap2=4;
        int r=1;
        int max=6;
        int sap3=Math.min(sap2+r,max);
        int sap4=Math.min(sap3+r,max);
        int total=sap1+sap2+sap3+sap4;
        JOptionPane.showMessageDialog(null,
                "În a 3-a săptămână voi merge " + sap3 + " ori\n" +
                        "Total antrenamente în 4 săptămâni: " + total);
    }
}
