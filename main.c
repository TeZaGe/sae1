#include <stdio.h>                        //bibliothèques//
#include <string.h>
#include <stdlib.h>
int age,codedep,nbjours,nbpersonnes;      //initialisation des variables et des fonctions //
char nom,prenom,pays;
int tmp;
int menu();
void ecriture();
void afficher();
void recherche();
void suppr();

int main () {
    menu();
    return 0;
}


int menu(){
                         //Menu principal
    int choix;
    printf("\n Menu :\n\n");
    printf("\n  Que faire ?\n\n");
    printf("1 - Ajouter des données dans la base\n");
    printf("2 - Voir les données\n");
    printf("3 - Rechercher\n");
    printf("4 - Supprimer les données\n");
    printf("5 - ordonnées les données\n");
    printf("6 - Quitter");
    printf("\n\nVotre choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
        case 1 : ecriture();break;                  //choix des différentes fonctions
        case 2 : afficher(); break;
        case 3 : recherche(); break;
        case 4 : suppr(); break;
        case 6 : return 0; break;
        default : printf("\nJe n'ai pas compris votre demande");
    }
    return 0;
}




void ecriture(){                                    // fonctions d'ecriture dans le fichier a finir
    int age,codedep,nbjours,nbpersonnes;
    char nom[20],prenom[20],pays[20];
    FILE* fichier = NULL;
 fichier = fopen("myFile0.csv", "a+");
 if (fichier != NULL) {
    printf("\n nom :");             // on rentre les différentes données
    gets(nom);
    printf("\n prenom :");
    gets(prenom);
    printf("\n age :");
    gets(age);
    printf("\n pays");
    gets(pays);
    printf("\n departement :");
    gets(codedep);
    printf("\n nombre de jour passé :");
    gets(nbjours);
    printf("\n nombres de personnnes :");
    gets(nbpersonnes);
    // ecriture des données dans le fichier
    fprintf(fichier,"%s ;%s ;%d ;%s ;%s ;%d ;%d ;%d," ,(nom,prenom,age,pays,codedep,nbjours,nbpersonnes));
    fclose(fichier);
    }
}


void afficher(){                        // fonction d'ouverture du fichier pour voir les données
    char ligne[255];
    FILE* fichier = fopen("myFile0.csv", "r");
    if (fichier == NULL){
     printf("Le fichier ne s'est pas ouvert");
    }

    while((fgets(ligne, 255, fichier)) != NULL) {

        printf("\n%s", ligne);
    }

    printf("%s", ligne);
    fclose(fichier);
}

void recherche(){                                           // a finir
    FILE *Fichier;
    char nomclient[30], nomcli[30];

    Fichier = fopen("myFile0.csv", "r");
    if (!Fichier)
         printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", "myFile0.csv");

    printf("Nom à chercher : ");
    scanf("%s",nomcli);

    while (fgets(nomclient,30,Fichier) != NULL)
    {
      if (strstr(nomclient, nomcli) != NULL)
          printf("'%s' trouvé dans '%s'", nomcli, nomclient);
    }
    fclose(Fichier);
    return 0;


}

 void suppr(int id) {
    FILE *csvFile = fopen("myFile0.csv", "r");
    FILE *csvwrite = fopen("database.txt", "w");
    int count = 0;
    char text[255];  // Initialisation d'une chaine de caractÃ¨re qui va stocker le contenu d'une ligne du csv.

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
    remove("myFile.csv");
    rename("database.txt", "database.csv");
}




