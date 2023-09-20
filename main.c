#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome[10];
    char cognome[15];
    char nTelefono[10];
    char email[20];
    int posizione;
    float budget;
}rubrica;

void stampaRubrica(int nPersone, rubrica dati[nPersone]){
    printf("STAMPA RUBRICA: \n");
    for(int i = 0; i < nPersone; i++){
        printf("Nome: %s\nCognome: %s\nNumero di telefono %s\nEmail: %s\nPosizione: %d\nBudget: %.2f\n\n", dati[i].nome, dati[i].cognome, dati[i].nTelefono, dati[i].email, dati[i].posizione, dati[i].budget);
    }
}

void stampaRubricaOrdinata(int nPersone, rubrica dati[nPersone]){
    int ordine[nPersone];
    for(int i = 0; i < nPersone; i++){
        ordine[i] = dati[i].posizione;
    }

    BoobleSort(nPersone, ordine);
    printf("STAMPA RUBRICA ORDINATA: \n\n");
    for(int i = 0; i < nPersone; i++){
        for(int j = 0; j < nPersone; j++){
            if(ordine[i] == dati[j].posizione){
                printf("Nome: %s\nCognome: %s\nNumero di telefono %s\nEmail: %s\nPosizione: %d\nBudget: %.2f\n\n", dati[j].nome, dati[j].cognome, dati[j].nTelefono, dati[j].email, dati[j].posizione, dati[j].budget);
            }
        }
    }
}

void BoobleSort(int nPersone, int vett[nPersone]){

    int temp;
    int minore;
    int i;
    int j;

   for(i = 0; i < nPersone; i++){
       minore = i;
      for (j = i + 1; j < nPersone; j++){
         if (vett[j] < vett[minore])
         minore = j;
      }
        temp = vett[minore];
        vett[minore] = vett[i];
        vett[i] = temp;
    }
}

int main()
{
    rubrica dati[20];
    int i = 0;
    int nPersone;
    char nome[10];
    int scelta;
    FILE *fp;
    fp = fopen("rubrica.txt","r");
    if(fp == NULL){
        printf("Il FILE non è stato trovato!!");
        fp = fopen("rubrica.txt","w");
        printf("\nIl FILE e' stato creato!!");
    }else{
        printf("FILE trovato!!");
        while(feof(fp) == 0){
            fflush(stdin);
            fscanf(fp, "%s", dati[i].nome);
            fscanf(fp, "%s", dati[i].cognome);
            fscanf(fp, "%s", dati[i].nTelefono);
            fscanf(fp, "%s", dati[i].email);
            fscanf(fp, "%d", &dati[i].posizione);
            fscanf(fp, "%f", &dati[i].budget);

            i++;
        }
    }
    fclose(fp);
    nPersone = i;
    system("pause");
    while(1){
        system("cls");
        printf("Inserisci\n1 per visualizzare la rubrica\n2 per visualizzare la rubrica ordinata per posizione\n3 per cercare un nome\n4 per inserire un nuovo numero\n5 per chiudere il programma\n");
        printf("Inserisci un comando: ");
        scanf("%d", &scelta);

        switch(scelta){

        case 1:
                stampaRubrica(nPersone, dati);
                system("pause");
            break;
        case 2:
            stampaRubricaOrdinata(nPersone, dati);
            system("pause");
            break;
        case 3:
            fflush(stdin);
            printf("Inserisci il nome di una persona: ");
            scanf("%[^\n]s", nome);

            for(i = 0; i < nPersone; i++){
                if(strcmp(dati[i].nome,nome) == 0){
                printf("Nome: %s\nCognome: %s\nNumero di telefono %s\nEmail: %s\nPosizione: %d\nBudget: %.2f\n", dati[i].nome, dati[i].cognome, dati[i].nTelefono, dati[i].email, dati[i].posizione, dati[i].budget);
                }
            }
            system("pause");
            break;
        case 4:
            fp = fopen("rubrica.txt","a");
            printf("Inserisci i dati: \n");
            fflush(stdin);
            printf("Nome: ");
            scanf("%s",dati[nPersone].nome);
            if(nPersone == 0){
                fprintf(fp, "%s\n", dati[nPersone].nome);
            }else fprintf(fp, "\n%s\n", dati[nPersone].nome);
            fflush(stdin);
            printf("Cognome: ");
            scanf("%s",dati[nPersone].cognome);
            fprintf(fp, "%s\n", dati[nPersone].cognome);
            fflush(stdin);
            printf("Numero di telefono: ");
            scanf("%s",dati[nPersone].nTelefono);
            fprintf(fp, "%s\n", dati[nPersone].nTelefono);
            fflush(stdin);
            printf("Indirizzo email: ");
            scanf("%s",dati[nPersone].email);
            fprintf(fp, "%s\n", dati[nPersone].email);
            fflush(stdin);
            printf("Posizione: ");
            scanf("%d", &dati[nPersone].posizione);
            fprintf(fp, "%d\n", dati[nPersone].posizione);
            fflush(stdin);
            printf("Budget: ");
            scanf("%f", &dati[nPersone].budget);
            fprintf(fp, "%d", dati[nPersone].budget);
            fclose(fp);
            nPersone++;
            break;
        case 5:
            exit(0);
        default:
            printf("Inserisci un camando valido!!");
            system("pause");
        }
    }

    return 0;
}
