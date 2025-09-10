
#include <stdio.h>
#include <string.h>

struct Joueur {
    char Nom[50];
    char Prenom[50];
    int NumMaillot;
    char post[50];
    int age;
    int but;
};

void afficheJoueur(struct Joueur joueur[], int n, int choix) {
    switch (choix) {
        case 1: // trier par age
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n-1-i; j++){
                    if(joueur[j].age > joueur[j+1].age){
                        struct Joueur temp = joueur[j];
                        joueur[j] = joueur[j+1];
                        joueur[j+1] = temp;
                    }
                }
            }
            break;

        case 2: 
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n-1-i; j++){
                    if(strcmp(joueur[j].Nom, joueur[j+1].Nom) > 0){
                        struct Joueur temp = joueur[j];
                        joueur[j] = joueur[j+1];
                        joueur[j+1] = temp;
                    }
                }
            }
            break;

        case 3: // trier par poste
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n-1-i; j++){
                    if(strcmp(joueur[j].post, joueur[j+1].post) > 0){
                        struct Joueur temp = joueur[j];
                        joueur[j] = joueur[j+1];
                        joueur[j+1] = temp;
                    }
                }
            }
            break;
    }

    for(int i = 0 ; i<n ; i++){
        printf("------ Joueur %d ------\n", i+1);
        printf("Nom : %s\nPrenom: %s\nNumero Maillot: %d\nPoste: %s\nAge: %d\nButs: %d\n\n",
              joueur[i].Nom, joueur[i].Prenom, joueur[i].NumMaillot,
              joueur[i].post, joueur[i].age, joueur[i].but);
    }
}

void modifContact(struct Joueur joueur[], int n, char searchNom[], int choix) {
    for(int i = 0 ; i < n ; i++){
        if(strcmp(joueur[i].post , searchNom) == 0){   // هنا ممكن تغيرها بـ joueur[i].Nom
            printf("Le joueur %s est trouvé\n", joueur[i].Nom);
            
            switch (choix) {
                case 1: {
                    char newPost[50];
                    printf("Entrer nouveau poste : ");
                    scanf("%s", newPost);
                    strcpy(joueur[i].post, newPost);
                    break;
                }
                case 2: {
                    int newAge;
                    printf("Entrer nouvel age : ");
                    scanf("%d", &newAge);
                    joueur[i].age = newAge;
                    break;
                }
                case 3: {
                    int newBut;
                    printf("Entrer nouveau nombre de buts : ");
                    scanf("%d", &newBut);
                    joueur[i].but = newBut;
                    break;
                }
                default:
                    printf("Choix invalide!\n");
                    break;
            }
        }
    }
}

int main(){
    struct Joueur joueur[50];
    int n = 0, choix, choixe;
    char searchN[50];

    do{  
        printf("=========== Menu ===========\n");
        printf("1) Ajouter des joueurs\n2) Afficher les joueurs\n3) Modifier un joueur\n0) Quitter\n");
        printf("Entrer le choix : ");
        scanf("%d",&choix);

        switch (choix)
        {
        case 1:
            printf("Entrer le nombre de joueurs : ");
            scanf("%d",&n);
            for (int i = 0; i < n; i++){
                printf("\n--- Joueur %d ---\n",i+1);

                printf("Nom : ");
                scanf("%s",joueur[i].Nom);

                printf("Prenom : ");
                scanf("%s",joueur[i].Prenom);

                printf("Numero du Maillot : ");
                scanf("%d",&joueur[i].NumMaillot);

                printf("Poste (gardien, defenseur, milieu, attaquant) : ");
                scanf("%s",joueur[i].post);

                printf("Age : ");
                scanf("%d",&joueur[i].age);

                printf("Nombre de buts : ");
                scanf("%d",&joueur[i].but);
            }
            break;

        case 2:
            if (n == 0) {
                printf("Aucun joueur enregistré!\n");
            } else {
                printf("Trier par: 1) Age  2) Nom  3) Poste : ");
                scanf("%d", &choixe);
                afficheJoueur(joueur, n, choixe);
            }
            break;

        case 3:
            if(n == 0){
                printf("Aucun joueur à modifier!\n");
            } else {
                printf("Entrer le Nom du joueur à modifier : ");
                scanf("%s", searchN);
                printf("Modifier: 1) Poste  2) Age  3) Buts : ");
                scanf("%d", &choixe);
                modifContact(joueur,n,searchN,choixe);
            }
            break;

        default:
            break;
        }
    } while(choix != 0);

    return 0;
}
