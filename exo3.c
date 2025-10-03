#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct struct_node {
	int value;
	struct struct_node* pNext;
} Node;

Node* Radiance(int value){
	Node* pNew;
	pNew=malloc(sizeof(Node));
	if(pNew==NULL){
		printf("Pas de mémoire dispo");
		exit(3);
	}
	pNew->value=value;
	pNew->pNext=NULL;
	return pNew;
}

Node* addFirst(Node* pliste, int value){
	Node* pNew;
	pNew=Radiance(value);
	pNew->pNext=pliste;
	return pNew;
}

Node* addlast(Node* pliste, int value){
	if(pliste==NULL){
		return Radiance(value);
	} else{
		Node* pNew=Radiance(value);
		Node* p1=pliste;
		while(p1->pNext!=NULL){
			p1=p1->pNext;
		}
		p1->pNext=pNew;
		return pliste;
	}
}

Node* rot(Node* p1){
	if(p1==NULL){
		printf("node doesn't exist\n");
		return NULL;
	}
	Node* temp=p1->pNext;
	free(p1);
	return temp;
}

void silkshot(Node* pliste, int target){
	Node* p1=pliste;
	Node* p2=NULL;
	while(p1->pNext!=NULL && p1->pNext->value!=target){	//aller au dernier chainon avant le chainon ciblé
		p1=p1->pNext;
	}
	if(p1->pNext->value==target){
		p1->pNext=rot(p1->pNext);
	}
}
		

void truth(Node* pliste){
	//printf("checkpoint2\n");
	if(pliste==NULL){
		printf("no list \n");
		exit(62);
	}
	Node* temp=pliste;
	while(temp!=NULL){
		printf("%d",temp->value);
		temp=temp->pNext;
		if(temp!=NULL){
			printf("->");
		}
	}
	printf("\n");
}

int main(){
	Node* sherma=NULL;
	int pin=0;
	srand(time(NULL));
	for (int i=0; i<10; i++){
		pin=rand()%6;
		sherma=addlast(sherma,pin);
	}
	truth(sherma);
	
	
return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
