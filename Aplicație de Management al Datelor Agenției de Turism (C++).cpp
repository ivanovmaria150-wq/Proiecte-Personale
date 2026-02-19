//Sa se defineasca cu ajutorul unei structuri,tipul de date "excursie" cu atributele:'id' de tip intreg,'nume' de tip char[20],'n' de tip int(nr de participanti si 'test'vector de 3 elemente de tip string,reprezentand numele celor 3 orase care vor fi vizitate.
//Sa se implementeze:

#include <iostream>
#include <algorithm>
using namespace std;
struct excursie {
    int id;
    char nume[20];
    int n;//nr de participanti
    string test[3];//numele celor 3 orase care vor fi vizitate
    //a)Fct. care citeste inf despre excursiile organizate de o agentie.
    void citireExcursii(excursie excursii[], int& nrexcursii) {
        cout << "Introduceti nr de excursii: ";
        cin >> nrexcursii;
        for (int i = 0; i < nrexcursii; i++) {
            cout << "Introduceti detaliile excursiei: " << i + 1 << endl;
            cout << "Id: ";
            cin >> excursii[i].id;
            cout << "Nume excursie: ";
            cin >> excursii[i].nume;
            cout << "Numar participanti: ";
            cin >> excursii[i].n;
            cout << "Introduceti cele 3 orase de vizitat:\n";
            for (int j = 0; j < 3; j++) {
                cout << "Oras " << j + 1 << ":";
                cin >> excursii[i].test[j];
            }
        }

    }
    //b)o fct care afiseaza inf despre excursiile cu nr minim de participanti
    void afisareExcursiiMinParticipanti(excursie excursii[], int nrexcursii, int MinParticipanti) {
        cout << "\nExcursiile cu cel putin " << MinParticipanti << "participanti:\n";
        for (int i = 0; i < nrexcursii; i++) {
            if (excursii[i].n >= MinParticipanti) {
                cout << "ID: " << excursii[i].id << ",Nume: " << excursii[i].nume << ",Participanti:" << excursii[i].n << "\nOrase:";
                for (int j = 0; j < 3; j++) {
                    cout << excursii[i].test[j] << " ";
                }
                cout << "\n";
            }
        }

    }
    //c)o fct care afiseaza alfabetic toate destinatiile spre care se organizeaza excursiile
    void afisareOraseAlfabetic(excursie excursii[], int nrexcursii) {
        string orase[300],r;
        int k = 0;
        for (int i = 0; i < nrexcursii; i++) {
            for (int j = 0; j < 3; j++) {
                orase[k++] = excursii[i].test[j];
            }
        }
        for(int i=0;i<n*3-1;i++)
            for(int j=0;j<n*3-1;j++)
                if (orase[j] > orase[j + 1])
                {
                    r = orase[j];
                    orase[j] = orase[j + 1];//interschimbare(bubblesort)
                    orase[j + 1] = r;
               }

        cout << "\nLista oraselor vizitate(ordonate alfabetic):\n";
        for (int i = 0; i < k; i++) {
            if (i == 0 || orase[i] != orase[i - 1]) {
                cout << orase[i] << endl;
            }
        }
    }
    //d)o fct care primeste ca parametru numele a unui oras (char nu string) si afiseaza toate excursiile in care se viziteaza orasul
    void afisareExcursiiOras(excursie excursii[], int nrexcursii, char orasCautat[]) {
        cout << "\nExcursiile care viziteaza orasul" << orasCautat << ":\n";
        for (int i = 0; i < nrexcursii; i++) {
            for (int j = 0; j < 3; j++) {
                if (excursii[i].test[j] == orasCautat) {
                    cout << "Id:" << excursii[i].id << ",Nume:" << excursii[i].nume << ",Participanti:" << excursii[i].n << "\nOrase:";
                    for (int k = 0; k < 3; k++) {
                        cout << excursii[i].test[k] << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
        }
    }
    //e)pentru fiecare excursie sa se ordoneze alfabetic cele trei orase vizitate
    void sortareOraseExcursii(excursie excursii[], int nrexcursii) {
        string orase[3];
        for (int i = 0; i < nrexcursii; i++) {
            int k = 0;
               for(int j=0;j<3;j++){
                   orase[k++] = excursii[i].test[j];
                    }
               for (int y = 0; y < 2; y++) {
                   for (int g = 0; g < 2 - y - 1; g++) {
                       if (orase[g] > orase[g + 1]) {
                           string t;
                           t = orase[g];
                           orase[g] = orase[g + 1];
                           orase[g + 1] = t;
                       }
                   }
               }
        }
    }
};
int main() {
    int nrexcursii;
    excursie excursii[100];
    excursii[0].citireExcursii(excursii, nrexcursii);
    excursii[0].sortareOraseExcursii(excursii, nrexcursii);
    cout << "\nExcursiile introduse\n";
    for(int i=0;i<nrexcursii;i++) {
      cout << "ID: " << excursii[i].id << ", Nume: " << excursii[i].nume << ", Participanti: " << excursii[i].n << "\nOrase: ";
        for (int j = 0; j < 3; j++) {
            cout << excursii[i].test[j] << " ";
        }
        cout << "\n";
    }
    excursii[0].afisareExcursiiMinParticipanti(excursii, nrexcursii, 10);
    excursii[0].afisareOraseAlfabetic(excursii, nrexcursii);
    char orasCautat[20];
    cout << "\nIntroduceti un oras pentru a cauta excursii: ";
    cin >> orasCautat;
    excursii[0].afisareExcursiiOras(excursii, nrexcursii, orasCautat);
    return 0;
}
