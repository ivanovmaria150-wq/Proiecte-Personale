//Sa se defineasca cu ajutorul unei structuri, tipul de date "excursie" cu atributele: 'id' de tip intreg, 
// 'nume' de tip char[20], 'n' de tip int - nr de participanti,
// si 'test'-vector de 3 elemente de tip string, reprezentand numele celor 3 orase care vor fi vizitate. 
// Sa se implmeneteze:
//a)o functie care citeste informatiile despre excursiile organizate de o agentie
//b)o functie care afiseaza informatiile despre excursiile cu numarul minim de participanti
//c)o functie care afiseaza alfabetic toate destinatiile spre care se organizaeaza excursiile
//d)o functie care primeste ca parametru numele unui oras(char, nu string) si afiseaza toate excursiile in care se viziteaza orasul 
//e) o functie care: pentru fiecare excursie sa se ordoneze alfabetic cele 3 orase de vizitat. 
// obs. la afisare, toate informatiile despre excursie. 
//toate functiile implementate se vor testa in main
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct excursie {
    int id;
    char nume[20];
    int n;
    char test[3][20];
};

void citireExcursii(FILE* f, excursie v[], int& nr) {
    scanf("%d", &nr);
    for (int i = 0; i < nr; i++) {
        scanf("%d", &v[i].id);
        scanf("%s", v[i].nume);
        scanf("%d", &v[i].n);
        for (int j = 0; j < 3; j++) {
            scanf("%s", v[i].test[j]);
        }
    }
}

void creazaFisierText(const char* numeFisier, excursie v[], int nr) {
    FILE* fout = fopen(numeFisier, "wt");
    if (fout == nullptr) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nr; i++) {
        fprintf(fout, "%d %s %d %s %s %s\n", v[i].id, v[i].nume, v[i].n, v[i].test[0], v[i].test[1], v[i].test[2]);
    }
    fclose(fout);
}

void creazaFisierBinar(const char* numeFisier, excursie v[], int nr) {
    FILE* fbin = fopen(numeFisier, "wb");
    if (fbin == nullptr) {
        exit(EXIT_FAILURE);
    }
    fwrite(v, sizeof(excursie), nr, fbin);
    fclose(fbin);
}

void citesteDinFisierText(const char* numeFisier, excursie v[], int& nr) {
    FILE* fin = fopen(numeFisier, "rt");
    if (fin == nullptr) {
        exit(EXIT_FAILURE);
    }
    while (fscanf(fin, "%d %s %d %s %s %s", &v[nr].id, v[nr].nume, &v[nr].n, v[nr].test[0], v[nr].test[1], v[nr].test[2]) != EOF) {
        nr++;
    }
    fclose(fin);
}

void citesteDinFisierBinar(const char* numeFisier, excursie v[], int& nr) {
    FILE* fbin = fopen(numeFisier, "rb");
    if (fbin == nullptr) {
        exit(EXIT_FAILURE);
    }
    fread(v, sizeof(excursie), 100, fbin);
    fclose(fbin);
}

void afiseazaExcursii(const excursie v[], int nr) {
    for (int i = 0; i < nr; i++) {
        printf("ID: %d, Nume: %s, Participanti: %d, Orase vizitate: %s, %s, %s\n", v[i].id, v[i].nume, v[i].n, v[i].test[0], v[i].test[1], v[i].test[2]);
    }
}

void afiseazaExcursiiMinimParticipanti(const excursie v[], int nr) {
    int min = v[0].n;
    for (int i = 1; i < nr; i++) {
        if (v[i].n < min) {
            min = v[i].n;
        }
    }
    for (int i = 0; i < nr; i++) {
        if (v[i].n == min) {
            printf("ID: %d, Nume: %s, Participanti: %d, Orase vizitate: %s, %s, %s\n", v[i].id, v[i].nume, v[i].n, v[i].test[0], v[i].test[1], v[i].test[2]);
        }
    }
}

void afiseazaDestinatiiAlfabetice(const excursie v[], int nr) {
    char destinatii[100][20];
    int count = 0;
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < 3; j++) {
            bool exists = false;
            for (int k = 0; k < count; k++) {
                if (strcmp(destinatii[k], v[i].test[j]) == 0) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                strcpy(destinatii[count], v[i].test[j]);
                count++;
            }
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(destinatii[j], destinatii[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, destinatii[j]);
                strcpy(destinatii[j], destinatii[j + 1]);
                strcpy(destinatii[j + 1], temp);
            }
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%s\n", destinatii[i]);
    }
}

void afiseazaExcursiiCuOras(const excursie v[], int nr, const char* oras) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < 3; j++) {
            if (strcmp(v[i].test[j], oras) == 0) {
                printf("ID: %d, Nume: %s, Participanti: %d, Orase vizitate: %s, %s, %s\n", v[i].id, v[i].nume, v[i].n, v[i].test[0], v[i].test[1], v[i].test[2]);
                break;
            }
        }
    }
}

void ordoneazaOraseAlfabetic(excursie& e) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (strcmp(e.test[j], e.test[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, e.test[j]);
                strcpy(e.test[j], e.test[j + 1]);
                strcpy(e.test[j + 1], temp);
            }
        }
    }
}

int main() {
    excursie excursii[100];
    int nrExcursii = 0;

    citireExcursii(stdin, excursii, nrExcursii);

    creazaFisierText("excursii.txt", excursii, nrExcursii);
    creazaFisierBinar("excursii.bin", excursii, nrExcursii);

    excursie excursiiDinText[100], excursiiDinBinar[100];
    int nrText = 0, nrBinar = 0;
    citesteDinFisierText("excursii.txt", excursiiDinText, nrText);
    citesteDinFisierBinar("excursii.bin", excursiiDinBinar, nrBinar);

    afiseazaExcursii(excursiiDinText, nrText);
    afiseazaExcursiiMinimParticipanti(excursiiDinText, nrText);
    afiseazaDestinatiiAlfabetice(excursiiDinText, nrText);
    afiseazaExcursiiCuOras(excursiiDinText, nrText, "Oras1");

    for (int i = 0; i < nrText; i++) {
        ordoneazaOraseAlfabetic(excursiiDinText[i]);
    }

    printf("\nExcursii cu orase ordonate alfabetic:\n");
    afiseazaExcursii(excursiiDinText, nrText);

    return 0;
}