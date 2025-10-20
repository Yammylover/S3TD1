#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char* nom;
    char* prenom;
    int notes[10];
    int groupe;
} Etudiant;

typedef struct struct_node{
    struct struct_node* pNext;
    Etudiant stud;
}Node;

void saisiretudiant(Node* pnode){
    if(pnode==NULL){    //vérification paramètres
        printf("Erreur 69\n");
        exit(69);
    }
    //locals
    char* string=malloc(sizeof(char)*50);
    Node* pNew=malloc(sizeof(Etudiant));
    int a;
    if(string==NULL || pNew==NULL){
        printf("Erreur 65\n");
        exit(60);
    }
    pNew->pNext=NULL;
    //nom
    printf("Entrez le nom de l'étudiant:\n");
    while(scanf("%s",string)!=1){
        printf("Erreur de saisie, veuillez recommencer\n");
    }
    pNew->stud.nom=malloc(sizeof(char)*strlen(string));
    if(pNew->stud.nom==NULL){
        printf("Erreur 65\n");
        exit(65);
    }
    strcpy(pNew->stud.nom,string);
    //prenom
    printf("Entrez le prénom de l'étudiant:\n");
    while(scanf("%s",string)!=1){
        printf("Erreur de saisie, veuillez recommencer\n");
    }
    pNew->stud.prenom=malloc(sizeof(char)*strlen(string));
    if(pNew->stud.prenom==NULL){
        printf("Erreur 66\n");
        exit(65);
    }
    strcpy(pNew->stud.prenom,string);
    //groupe
    printf("Rentrez le numéro de groupe de l'étudiant:\n");
    while(scanf("%d",&a)!=1){
        printf("Erreur de saisie. Veuillez recommencer:\n");
    }
    pNew->stud.groupe=a;
    //notes
    for(int i=0;i<10;i++){
        pNew->stud.notes[i]=rand()%21;
    }
    //ajout de pNew à la fin de la liste
    Node* temp=pnode;
    while(temp->pNext!=NULL){
        temp=temp->pNext;
    }
    temp->pNext=pNew;
}

void listepargroupe(Node* pliste, int groupe){
    if(pliste==NULL || groupe<0){
        printf("Erreur 43\n");
        exit(43);
    }
    Node* temp=pliste;
    do){
        temp=temp->pnext;
    }while(temp->pnext!=NULL)
}

int main()
{
    srand(time(NULL));
    printf("Hello World");

    return 0;
}
