#include <stdio.h>                        //bibliothèques//
#include <string.h>
#include <stdlib.h>    //initialisation des variables et des fonctions //
#define N 100
int compt;
char nom[200];





typedef struct client{
    char ID[100];
    char nbf[100];
    char pre[20];
    char name[20];
    char ages[100];
    char country[20];
    char coded[100];
    char nbj[100];
}client;

typedef client tabClient[N];

void ecriture(client * r){
    int i=0;
    compt=26;
    int age,codedep,nbjours,nbpersonnes;
   FILE*fichier = fopen("myFile0.csv", "a");
       if (fichier != NULL) {
         printf(" prenom :\n");
         scanf("%s",client[i].pre);
         printf("\n nom :\n");             // on rentre les différentes données
         scanf("%s",client[i].name);
         printf("\n age :\n");
         scanf("%s",client[i].ages);
         printf("\n pays :\n");
         scanf("%s",client[i].country);
         printf("\n departement :\n");
         scanf("%s",client[i].coded);
         printf("\n nombre de jour passes :\n");
         scanf("%s",client[i].nbj);
         printf("\n nombres de personnnes :\n");
         scanf("%s",client[i].nbf);
         fprintf(fichier,"\n%s,%s,%s,%s,%s,%s,%s",client[i]->name,client[i]->pre,client[i]->ages,client[i]->country,client[i]->coded,client[i]->nbj,client[i]->nbf);
         compt=compt+1;
    // ecriture des données dans le fichier
    fclose(fichier);

    }

}


void afficher(){
    char ligne[255];
    FILE* fichier = fopen("myFile0.csv", "r");
    if (fichier == NULL){
     printf("Le fichier ne s'est pas ouvert");
    }

    while((fgets(ligne, 255, fichier)) != NULL) {

        printf("\n%s", ligne);
    }

    fclose(fichier);


}

void recherche(){
    int i;
    FILE *fichier = fopen("myFile0.csv", "r");
    char nomcli[200];
    printf("Rechercher en fonction de nom ou du pays ");
    if (!fichier)
         printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", "myFile0.csv");

    printf("Nom a chercher : \n");
    scanf("%s",nomcli);
    for (i=0;i<=compt;i++){
    while (fgets(nom,30,fichier) != NULL)
    {
      if (strstr(nom, nomcli) != NULL)
          printf("'%s' trouve dans '%s'\n", nomcli, nom);
    }
    fclose(fichier);
}

}

void suppr(int id) {
    FILE *csvFile = fopen("myFile0.csv", "r");
    FILE *csvwrite = fopen("database.txt", "w");
    int count = 1;
    char text[255];  // Initialisation d'une chaine de caractere qui va stocker le contenu d'une ligne du csv.

    if(!(csvFile || csvwrite)) exit(1) ;
    id++ ;

    while(!feof(csvFile)) {
        strcpy(text, "\0") ;
        fgets(text, 255, csvFile) ;
        if (!feof(csvFile)) {
            count++;
            if (count != id) fprintf(csvwrite, "%s", text);
        }
    }

    fclose(csvFile);
    fclose(csvwrite);
    remove("myFile0.csv");
    rename("database.txt","myFile0.csv");

}

int main(){
    int run ;           //Menu principal
    int choix;
    int supprid ;
    run = 1 ;
    while (run == 1 ) {
        printf("\nMenu :\n\n");
        printf("\nQue faire ?\n\n");
        printf("1 - Ajouter des donnees dans la base\n");
        printf("2 - Voir les donnees\n");
        printf("3 - Rechercher\n");
        printf("4 - Supprimer les donnees\n");
        //printf("45 - ordonnees les donnees\n");
        printf("5 - Quitter");
        printf("\n\nVotre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
            case 1 :
                ecriture();break;                  //choix des différentes fonctions
            case 2 :
                afficher(); break;
            case 3 :
                recherche(); break;
            case 4 :
                printf("donner id personne\n");
                scanf("%d", &supprid);
                suppr(supprid); break;
            case 5 :
                run = 0 ;
            default :
                if (run == 1) {
                    printf("\nJe n'ai pas compris votre demande.") ;
                }

        }
    }
    printf("\n\nAu revoir.\n\n") ;
}
