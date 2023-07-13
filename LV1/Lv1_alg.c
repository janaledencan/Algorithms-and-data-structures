/*opæenitu funkciju za generiranje polja s n pseudosluèajnih brojeva èija se
vrijednost nalazi izmeðu zadane donje i gornje granice. Prototip funkcije je:
void gen_arr( float V[], int n, float dg, float gg );*/

/*Naèiniti slijedeæe funkcije:
a) sekvencijalno pretraživanje
int sekv_pret( float V[], int n, float x );
Funkcija vraæa -1 ako se traženi broj x ne nalazi u V, u suprotnom vraæa prvo
mjesto u nizu na kojem se nalazi x.
b) Sortiranje
void sort( float V[], int n );
Upotrijebiti bilo koji algoritam za sortiranje niza V. Napraviti uzlazno sortiranje.
c) binarno pretraživanje
int bin_pret( float V[], int n, float x );
Ovdje V mora biti uzlazno sortirani niz. Funkcija vraæa -1 ako se traženi broj x ne
nalazi u V, u suprotnom vraæa prvo mjesto u nizu na kojem se nalazi x.
Korisnik programa sam odreðuje broj èlanova polja n.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void gen_arr( float V[], int n, float dg, float gg );
int sekv_pret( float V[], int n, float x );
void sort( float V[], int n );
int bin_pret( float V[], int n, float x );


int main(){
	
	int n,i;
	float *polje;
	float dg,gg;   //vjv mi trebamo zadati
	
	srand((unsigned)time(NULL));
	
	printf("Unesite br. elemenata: ");
	scanf("%d", &n);
	
	polje=(float*)calloc(n, sizeof(float));
		if(polje==NULL){
			return -4;
		}
	
	
	gen_arr(polje, n, 1, 100); //stavi neke br za dg i gg
	
  /*for(i=0; i<n; i++){
		printf("%.2f ", polje[i]);
	}*/
	
	
	time_t t1,t2;
	t1= clock();
	
	//printf("\n%d",sekv_pret(polje, n, 14.56));
	sort(polje, n);
	
	t2= clock();
	
	printf("\n%d",bin_pret(polje, n, 14.56));
	
	printf("\nVrijeme trajanja je %dms\n", t2-t1);
	free(polje);
	
	return 0;
}



void gen_arr( float V[], int n, float dg, float gg ){
	
	int i;
	for(i=0; i<n; i++){
		
		V[i]=dg + (float)rand() / RAND_MAX * (gg-dg);
	}
}


int sekv_pret( float V[], int n, float x ){
	
	int i;
	for(i=0; i<n; i++){
		if(V[i]==x){
			return i;
		}
	}
	return -1;
}

void swap(float *a, float *b){
	
	float c;
	*a = *b;
	*b = c;
	c = *a;
}

void sort( float V[], int n ){ //bubble
	
	int i,j;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(V[j+1] < V[j])
				swap(&V[j],&V[j+1]);
		}
	}
	
}


int bin_pret( float V[], int n, float x ){
	
	int dg = 0,gg = n-1;
	int s;
	
	while(dg<=gg){
		
		s=(dg+gg)/2;
		
		if(V[s]==x){
			return s;
		}
		else if(V[s]>x){
			gg=s-1;
		}
		else if(V[s]<x){
			dg=s+1;
		}
		else{
			return s;
			break;
		}
	}
	if(dg>gg)
		return -1;
		
}







