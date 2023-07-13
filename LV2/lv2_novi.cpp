/*Potrebno je generirati sluèajni Niz V od N elemenata. Nakon toga iz tog niza formirati povezani popis. Mjeriti i usporediti
 vrijeme potrebno za kreiranje niza i povezanog popisa. Nakon toga napraviti algoritam sekvencijalnog pretraživanja nad nizom
  i nad povezanim popisom. Opet mjeriti vrijeme, što je brže?*/
  
#include<stdio.h>
  #include<stdlib.h>
  #include<time.h>
  
  typedef struct OE_{
  		int x;
  		struct OE_* next;
  }OE;
  
  
  OE* kreirajPrvi (int value){
  		
  	OE*	headNode= (OE*)malloc(1* sizeof(OE));
		if(headNode==NULL){
			return NULL;
		}	
		else{
			headNode->x = value;
			headNode->next=NULL;
		}
		return headNode;
  }
  
  
 /* OE* insertNewNode(OE* headNode, int val){
  	
  	OE* newNode= (OE*)malloc(1*sizeof(OE));
	  	if(headNode==NULL){
	  		perror("Error allocating.");
		}
	
	newNode->x= val ;
	newNode->next= headNode;
	headNode= newNode;
	
	return headNode;
  }
  */
  
  void search( OE* headNode, int criteria){
  	
  	OE *tempNode = headNode;
  	
  	for(tempNode; tempNode != NULL; tempNode=tempNode->next){
  		if(tempNode->x == criteria){
  			printf("Pronaden element");
  			break;
		}
	}	
  }
  
  
  
  int main(){
  	
  	int *V;
  	int n;
  	time_t t1,t2,t3,t4;
  	
  	
  	printf("Unesite broj elemenata:\n");
  	scanf("%d", &n);
  	
  	t1= clock();
  	
  	V= (int*)malloc(n*sizeof(int));
  		if(V==NULL){
  			perror("Error allocating.");
		  }

	srand((unsigned)time(NULL));
	
	for(int i=0; i<n; i++){
		V[i]= 1 + rand()%(10000-1);  
	}
	
	t2= clock();
	printf("Vrijeme formiranja niza:%ld\n", t2-t1);
	
	t3= clock();
	
	OE* headNode = kreirajPrvi(V[0]);  //stvaranje glave i postavljanje njene vrijednosti
	OE* tempNode=headNode;
	
	for(int i=1; i<n; i++){    //i=1 jer imamo vec glavu
		tempNode->next = (OE*) malloc(1*sizeof(OE));
			//provjera zauzimanja
		tempNode = tempNode->next;
		tempNode->x = V[i];
	}
		
	tempNode->next=NULL;  //jer zadnjem nismo pridruzili vrijednost
	
	t4= clock();
	printf("Vrijeme kreiranja povezane liste:%ld\n", t4-t3);
	
	
	int criteria= -1;
	
	t1= clock();
		for(int i=0; i<n; i++){
			if(V[i]==criteria){
				printf("Nadjen br.");
				break;
			}
		}
	t2= clock();
	printf("Vrijeme sortiranja niza:%ld\n", t2-t1);
	
	
	t3= clock();
		search(headNode, -1);  	
	t4= clock();
	printf("Vrijeme pretrazivanja povezane liste:%ld\n", t4-t3);
	
	
	//oslobadanje memorije
	free(V);
	
	OE* d= NULL;
	
	while(tempNode){
		d= tempNode;
		tempNode= tempNode->next;
		free(d);
	}
  	
  	tempNode=NULL;
  	
 	return 0; 
 }
