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

void gen_arr( float V[], int n, float dg, float gg ){
	
	int i;
	for(i=0; i<n; i++){
		V[i]=dg + (float)rand()/ RAND_MAX*(gg-dg);
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

void swap(float *a, float *b ){
	float c;
	c=*a;
	*a=*b;
	*b=c;
}

void sort( float V[], int n ){  //selection
	
	int i,j,min;
	
	for(i=0; i<n; i++){
		min=i;
		for(j=i+1; j<n; i++ ){
			if(V[j]<V[min]){
				min=j;	
			}
			swap(&V[i], &V[min]);
		}
	}
}

int bin_pret( float V[], int n, float x ){
	
	int i,dg=0,gg=n-1,s;
	
	while(dg<=gg){
		
		s=(dg+gg)/2;
		
		if(V[s]==x){
			return i;			
		}
		else if(V[s]>x){
			gg= s-1;
		}
		else if(V[s]< x){
			dg= s+1;
		}
	}
	
	if(dg > gg) return -1;
	
}



int main(){
	
	srand((unsigned)time(NULL));
	
	int n, i;
	float *V;
	time_t t1,t2;
	
	printf("Unesite br. elemenata(n):");
	scanf("%d", &n);
	
	V= (float*)calloc(n, sizeof(float));
	if(V==NULL)
		return -3;
		
		
	gen_arr( V, n, 1, 100);	
	
	t1= clock();
	
	printf("%d",sekv_pret( V, n, 14.33 ));
	//sort( V, n );
	//printf("%d",bin_pret( V, n, 14.33));
	
	t2= clock();
	
	printf("Vrijeme trajanja je %dms\n", t2-t1);
	
	free(V);
	
			
	return 0; 
}
