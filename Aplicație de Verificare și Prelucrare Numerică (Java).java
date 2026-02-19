import javax.swing.JOptionPane;

public class ex1 {
    public static void main(String[] args) {
        String input = JOptionPane.showInputDialog("Introdu un număr care începe cu 9 și se termină în 0:");
        int nr = Integer.parseInt(input);
        String text = Integer.toString(Math.abs(nr));
        if (text.charAt(0) == '9' && text.charAt(text.length() - 1) == '0') {
            int abs = Math.abs(nr);
            int radInt = (int) Math.sqrt(abs);
            String rezultat = "Valoarea absolută: " + abs + "\n" +
                    "Partea întreagă a rădăcinii pătrate: " + radInt + "\n" +
                    "Divizorii lui " + radInt + " sunt: ";
            for (int i = 1; i <= radInt; i++) {
                if (radInt % i == 0) {
                    rezultat += i + " ";
                }
            }

            JOptionPane.showMessageDialog(null, rezultat);

        } else {
            JOptionPane.showMessageDialog(null,
                    "Numărul NU începe cu 9 și nu se termină în 0!");
        }
    }
}

