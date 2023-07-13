#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Zadatak 1. Potrebno je generirati sluèajni Niz V od N elemenata. Nakon toga iz tog niza formirati povezani popis. 
Mjeriti i usporediti vrijeme potrebno za kreiranje niza i povezanog popisa. Nakon toga napraviti algoritam sekvencijalnog
pretraživanja nad nizom i nad povezanim popisom. Opet mjeriti vrijeme, što je brže?*/

	typedef struct OE_ {
		int x;
		struct OE_ *sljedeci;
	}OE;


	OE* insertNewNode(OE* headNode, int i) {
		
		OE *newHeadNode = (OE*)calloc(1, sizeof(OE));
			if (newHeadNode == NULL) {
				perror("Kreiranje");
				return headNode;
			}
			else {
				newHeadNode->x = v[i];
				newHeadNode->sljedeci = headNode;
			}
		return newHeadNode;
	}

//za ispis liste
	void traverse(OE* traverseNode) {
		
		if (traverseNode == NULL) {
			return -1;
		}
		else {
			while (traverseNode) {
	
				printf("number: %d\tcurrent node addr:\ %p\tnext node addr: %p\n", traverseNode->number, traverseNode, traverseNode->nextNode);
				traverseNode = traverseNode->nextNode;
			}
		}
	}


OE* search(OE* traverseNode, int criteria) {
	while (traverseNode) {
		if (traverseNode->number == criteria) {
			return traverseNode;
		}
		else {
			traverseNode = traverseNode->nextNode;
		}
	}
	return NULL;
}

//void deleteNode(OE** headNode, OE* targetNode) {
//	if (*headNode == targetNode) {
//		*headNode = (*headNode)->nextNode;
//		free(targetNode);
//		printf("Oslobodjen chvor: %p\n", targetNode);
//	}
//	else {
//		OE* traverseNode = *headNode;
//		while (traverseNode->nextNode) {
//			if (traverseNode->nextNode == targetNode) {
//				traverseNode->nextNode = targetNode->nextNode;
//				free(targetNode);
//				printf("Oslobodjen chvor: %p\n", targetNode);
//				break;
//			}
//		traverseNode = traverseNode->nextNode;
//		}
//	}
//}

OE* deleteWholeList(OE* traverseNode) {
	OE* deleteNode = NULL;
	while (traverseNode) {
		deleteNode = traverseNode;
		traverseNode = traverseNode->nextNode;
		free(deleteNode);
		printf("Oslobodjen chvor: %p\n", deleteNode);
	}
	return NULL;
}


int main(){
	
	int i,n;
	int *v;
	time_t t1, t2, t3, t4;
	
	printf("Unesite br. elemenata (n):");
	scanf("%d", &n);
	
	srand((unsigned)time(NULL));
	
	//kreiranje niza
	t1= clock();
	
	v= (int*)malloc(n*sizeof(int));
		if(v==NULL){
			exit(EXIT_FAILURE);
		}
	
	for(i=0; i<n; i++){
		v[i]= 1 + rand()%(100000+1);
	}
	
	t2= clock();
	
	printf( "Vrijeme trajanja je %dms\n",t2-t1 );
	
	
	//kreiranje povezanog popisa
	
	 t3= clock();
	
	 OE *headNode = NULL; 
	 headNode = (OE*)malloc(1* sizeof(OE));
	 	if(headNode=NULL){
	 		exit(EXIT_FAILURE);
		}
		
		else{
			headNode.x = v[0];
			headNode->sljedeci= NULL;
		}
		 
//	OE *newHeadNode=(OE*)malloc(1*sizeof(OE));
//		if(newHeadNode=NULL){
//	 		exit(EXIT_FAILURE);
//		}
//		else{
//			
//			newHeadNode->x = v[0];
//			newHeadNode->sljedeci= headNode;
//		}
		 
	//i = 0 vec imamo
	 for(i=1; i<n ; i++){
	 	headNode = insertNewNode(headNode, i);
	 }
	 
	 t4=clock();
	 printf( "Vrijeme trajanja je %dms\n",t4-t3 );
	 
	 traverse(headNode);
	 
	//sekvencijalno pretrazivanje niza
	t1= clock();
	 
	for(i=0; i<n; i++){
	 	if(v[i]==5){
	 	 	printf("Naden br.");
			break;
		}
	}
	
	 t2=clock();
	 printf( "Vrijeme trajanja je %dms\n",t2-t1 );
	 
	 
	//sekvencijalno pretrazivanje popisa
	
	 t3= clock();
	 
	 search(headNode, 5);
	 
	 t4=clock();
	 printf( "Vrijeme trajanja je %dms\n",t4-t3 );
	 
	 
	 //oslobadanje memorije

	free(v);
	headNode = deleteWholeList(headNode);
	 
	 
	return 0;
}



///////////////////////////////////////////////// ISPRAVLJENE GREŠKE sintaksne
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Zadatak 1. Potrebno je generirati sluèajni Niz V od N elemenata. Nakon toga iz tog niza formirati povezani popis. 
Mjeriti i usporediti vrijeme potrebno za kreiranje niza i povezanog popisa. Nakon toga napraviti algoritam sekvencijalnog
pretraživanja nad nizom i nad povezanim popisom. Opet mjeriti vrijeme, što je brže?*/

	typedef struct OE_ {
		int x;
		struct OE_ *sljedeci;
	}OE;


	OE* insertNewNode(OE* headNode, int i, int *v) {
		
		OE *newHeadNode = (OE*)calloc(1, sizeof(OE));
			if (newHeadNode == NULL) {
				perror("Kreiranje");
				return headNode;
			}
			else {
				newHeadNode->x = v[i];
				newHeadNode->sljedeci = headNode;
			}
		return newHeadNode;
	}

//za ispis liste
	void traverse(OE* traverseNode) {
	
			while (traverseNode) {
	
				printf("number: %d\tcurrent node addr: %p\tnext node addr: %p\n", traverseNode->x, traverseNode, traverseNode->sljedeci);
				traverseNode = traverseNode->sljedeci;
			}
	}


OE* search(OE* traverseNode, int criteria) {
	while (traverseNode) {
		if (traverseNode->x == criteria) {
			return traverseNode;
		}
		else {
			traverseNode = traverseNode->sljedeci;
		}
	}
	return NULL;
}



OE* deleteWholeList(OE* traverseNode) {
	OE* deleteNode = NULL;
	while (traverseNode) {
		deleteNode = traverseNode;
		traverseNode = traverseNode->sljedeci;
		free(deleteNode);
		printf("Oslobodjen chvor: %p\n", deleteNode);
	}
	return NULL;
}



int main(){
	
	int i,n;
	int *v;
	time_t t1, t2, t3, t4;
	
	printf("Unesite br. elemenata (n):");
	scanf("%d", &n);
	
	srand((unsigned)time(NULL));
	
	//kreiranje niza
	t1= clock();
	
	v= (int*)malloc(n*sizeof(int));
		if(v==NULL){
			//exit(EXIT_FAILURE);
			return -2;
		}
	
	for(i=0; i<n; i++){
		v[i]= 1 + rand()%(100000+1);
		printf("%d ", v[i]);
	}
	
	t2= clock();
	
	printf( "Vrijeme trajanja kreiranja niza je %ld\n",t2-t1 );
	
	
	//kreiranje povezanog popisa
	
	 t3= clock();
	
	 OE *headNode = NULL; 
	 headNode = (OE*)malloc(1* sizeof(OE));
	 	if(headNode=NULL){
	 		//exit(EXIT_FAILURE);
	 		return -3;
		}
		
		else{
			headNode->x = v[0];
			headNode->sljedeci= NULL;
		}
		 

		 
	//i = 0 vec imamo
	 for(i=1; i<n ; i++){
	 	headNode = insertNewNode(headNode, i, v);
	 }
	 
	 t4=clock();
	 printf( "Vrijeme trajanja kreiranja povezanog popisa je %ld\n",t4-t3 );
	 
	 traverse(headNode);
	 
	//sekvencijalno pretrazivanje niza
	t1= clock();
	 
	for(i=0; i<n; i++){
	 	if(v[i]==5){
	 	 	printf("Naden br.");
			break;
		}
	}
	
	 t2=clock();
	 printf( "Vrijeme trajanja sekv. pret. niza je %ld\n",t2-t1 );
	 
	 
	//sekvencijalno pretrazivanje popisa
	
	 t3= clock();
	 
	 search(headNode, 5);
	 
	 t4=clock();
	 printf( "Vrijeme trajanja pretrazivanja popisa je %ld\n",t4-t3 );
	 
	 
	 //oslobadanje memorije

	free(v);
	headNode = deleteWholeList(headNode);
	 
	 
	return 0;
}


////////////////////////////////ISPRAVLJEN
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



	typedef struct OE_ {
		int x;
		struct OE_ *sljedeci;
	}OE;

    OE* makeList(int value){
        
        OE *headNode = (OE*)malloc(1* sizeof(OE));
    	 	if(headNode==NULL){
    	 		//exit(EXIT_FAILURE);
    	 		return NULL;
    		}
    		
    		else{
    			headNode->x = value;
    			headNode->sljedeci= NULL;
    		}
    	return headNode;
    }
    
	OE* insertNewNode(OE* headNode, int value) {
		
		OE *newHeadNode = (OE*)calloc(1, sizeof(OE));
			if (newHeadNode == NULL) {
				perror("Kreiranje");
				return headNode;
			}
			else {
				newHeadNode->x = value;
				newHeadNode->sljedeci = headNode;
			}
		return newHeadNode;
	}

//za ispis liste
	void traverse(OE* traverseNode) {
	
			while (traverseNode) {
	
				printf("number: %d\tcurrent node addr: %p\tnext node addr: %p\n", traverseNode->x, traverseNode, traverseNode->sljedeci);
				traverseNode = traverseNode->sljedeci;
			}
	}


OE* search(OE* traverseNode, int criteria) {
	while (traverseNode) {
		if (traverseNode->x == criteria) {
			return traverseNode;
		}
		else {
			traverseNode = traverseNode->sljedeci;
		}
	}
	return NULL;
}



OE* deleteWholeList(OE* traverseNode) {
	OE* deleteNode = NULL;
	while (traverseNode) {
		deleteNode = traverseNode;
		traverseNode = traverseNode->sljedeci;
		free(deleteNode);
		printf("Oslobodjen chvor: %p\n", deleteNode);
	}
	return NULL;
}



int main(){
	
	int i,n;
	int *v;
	time_t t1, t2, t3, t4;
	
	printf("Unesite br. elemenata (n):");
	scanf("%d", &n);
	
	srand((unsigned)time(NULL));
	
	//kreiranje niza
	t1= clock();
	
	v= (int*)malloc(n*sizeof(int));
		if(v==NULL){
			//exit(EXIT_FAILURE);
			return -2;
		}
	
	for(i=0; i<n; i++){
		v[i]= 1 + rand()%(100000+1);
		printf("%d ", v[i]);
	}
	
	t2= clock();
	
	printf( "Vrijeme trajanja kreiranja niza je %ld\n",t2-t1 );
	
	
	//kreiranje povezanog popisa
	
	 t3= clock();
	
	 OE *headNode = makeList(v[0]); 
	

	//i = 0 vec imamo
	 for(i=1; i<n ; i++){
	 	headNode = insertNewNode(headNode, v[i]);
	 }
	 
	 t4=clock();
	 printf( "Vrijeme trajanja kreiranja povezanog popisa je %ld\n",t4-t3 );
	 
	 traverse(headNode);
	 
	//sekvencijalno pretrazivanje niza
	t1= clock();
	 
	for(i=0; i<n; i++){
	 	if(v[i]==5){
	 	 	printf("Naden br.");
			break;
		}
	}
	
	 t2=clock();
	 printf( "Vrijeme trajanja sekv. pret. niza je %ld\n",t2-t1 );
	 
	 
	//sekvencijalno pretrazivanje popisa
	
	 t3= clock();
	 
//	 search(headNode, 5);
	 
	 t4=clock();
	 printf( "Vrijeme trajanja pretrazivanja popisa je %ld\n",t4-t3 );
	 
	 
	 //oslobadanje memorije

	free(v);
	headNode = deleteWholeList(headNode);
	 
	 
	return 0;
}
