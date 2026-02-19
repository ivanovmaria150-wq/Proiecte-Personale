import javax.swing.JOptionPane;
public class Divizori {
    public static int cmmdc(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    public static int cmmdcTreiNumere(int a, int b, int c) {
        return cmmdc(a, cmmdc(b, c));
    }

    public static void main(String[] args) {
        int varstaMea = 20;
        int varstaTata = 51;
        int varstaMama = 50;

        int rezultatCMMDC = cmmdcTreiNumere(varstaMea, varstaTata, varstaMama);

        String mesaj = "Vârstele sunt: " + varstaMea + " ani (eu), "
                + varstaTata + " ani (tata) și "
                + varstaMama + " ani (mama).\n\n"
                + "Cel mai mare divizor comun (CMMDC) al acestor trei vârste "
                + "se calculează iterativ: CMMDC(" + varstaMea + ", CMMDC(" + varstaTata + ", " + varstaMama + ")).\n"
                + "Pasul 1: CMMDC(" + varstaTata + ", " + varstaMama + ") = CMMDC(50, 51) = 1.\n"
                + "Pasul 2: CMMDC(" + varstaMea + ", 1) = CMMDC(20, 1) = 1.\n\n"
                + "CMMDC-ul final al celor trei vârste este: " + rezultatCMMDC + ".";

        JOptionPane.showMessageDialog(null, mesaj, "Calcul CMMDC Vârste", JOptionPane.INFORMATION_MESSAGE);
    }
}

