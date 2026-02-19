import java.util.Scanner;
public class Autoturism{
protected String producator;
protected boolean combustie;
protected byte locuri;

public Autoturism(){
    this.producator = "";
    this.combustie = false;
    this.locuri = 0;
}
public void Autotursim(String producator,boolean ccombustie,byte locuri){
    this.producator = producator;
    this.combustie = combustie;
    this.locuri = locuri;
}
public Autoturism(Autoturism a){
    this.producator = a.producator;
    this.combustie = a.combustie;
    this.locuri = a.locuri;
}
    public void setDateTastatura() {
        if (this.combustie) {
            Scanner sc = new Scanner(System.in);
            System.out.print("Introduceți producătorul: ");
            this.producator = sc.nextLine();
        } else {
            System.out.println("Setarea nu este permisă: autoturismul nu are combustie.");
        }
    }
@Override
    public String toString() {
    return "Producator: " + producator + ", Combustie: " + combustie + ", Locuri: " + locuri;
}
}
