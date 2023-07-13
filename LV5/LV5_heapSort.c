
/*Zadatak 2. Napisati funkcije za sortiranje cjelobrojnog polja brojeva upotrebom heap sort i bubble sort algoritma. Prototip funkcija je :
void heap_sort(int *V, int n);
void bubble_sort(int *V, int n);
n je velièina polja
U glavnom programu generirati polje sluèajnih brojeva i pozivati funkcije za sortiranje.
Funkciju pozivati više puta za polja razlièita sadržaja, mjeriti vrijeme sortiranja te nacrtati odgovarajuæi graf.*/


//BEZ KOMENTARA JE DOLJE I ON JE BAŠ ONO ŠTO NAM TREBA - IMA RANDOM POPUNJAVANJE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//potreban za bubble i heap sort
void swap(int *a, int *b){
	
	int c = *a;
	*a = *b;
	*b = c;

}

//void merge_sort(int *V, int n);
void merge(int *V, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = V[l + i];
    for (j = 0; j < n2; j++)
        R[j] = V[m + 1 + j];
  
    /* Merge the temp arrays back into V[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            V[k] = L[i];
            i++;
        }
        else {
            V[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        V[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        V[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
sub-array of V to be sorted */
void mergeSort(int V[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(V, l, m);
        mergeSort(V, m + 1, r);
  
        merge(V, l, m, r);
    }
}

/* Function to print an array */
void printArray(int V[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", V[i]);
    printf("\n");
}
  
/////////////////////////////////////////////////////////////

//void heap_sort(int *V, int n);

// A heap has current size and array of elements
struct MaxHeap
{
    int n;
    int* V;
};

// A utility function to swap to integers  OBRISAN JER IMAMO OD BUBBLE s.


// The main function to heapify a Max Heap. The function
// assumes that everything under given root (element at
// index idx) is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;  // Initialize largest as root
    int left = (idx << 1) + 1;  // left = 2*idx + 1
    int right = (idx + 1) << 1; // right = 2*idx + 2

    // See if left child of root exists and is greater than
    // root
    if (left < maxHeap->n &&
        maxHeap->V[left] > maxHeap->V[largest])
        largest = left;

    // See if right child of root exists and is greater than
    // the largest so far
    if (right < maxHeap->n &&
        maxHeap->V[right] > maxHeap->V[largest])
        largest = right;

    // Change root, if needed
    if (largest != idx)
    {
        swap(&maxHeap->V[largest], &maxHeap->V[idx]);
        maxHeapify(maxHeap, largest);
    }
}

// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *V, int n)
{
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->n = n;   // initialize size of heap
    maxHeap->V = V; // Assign address of first element of array

    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (maxHeap->n - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

// The main function to sort an array of given size
void heapSort(int* V, int n)
{
    // Build a heap from the input data.
    struct MaxHeap* maxHeap = createAndBuildHeap(V, n);

    // Repeat following steps while heap size is greater than 1.
    // The last element in max heap will be the minimum element
    while (maxHeap->n > 1)
    {
        // The largest item in Heap is stored at the root. Replace
        // it with the last item of the heap followed by reducing the
        // size of heap by 1.
        swap(&maxHeap->V[0], &maxHeap->V[maxHeap->n - 1]);
        --maxHeap->n;  // Reduce heap size

        // Finally, heapify the root of tree.
        maxHeapify(maxHeap, 0);
    }
}


///////////////////////////////////////////////////////////


void bubble_sort( int *V, int n ){ 
	
	int i,j;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(V[j+1] < V[j])
				swap(&V[j],&V[j+1]);
		}
	}
	
}


int main(){
	
	int V1[] = { 12, 11, 13, 5, 6, 7 };
	int V2[] = { 12, 11, 13, 5, 6, 7 };
	int V3[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(V1) / sizeof(V1[0]);
	time_t t1, t2;
		
	srand((unsigned)time(NULL));
	
	printf("Pocetno polje: \n");
	printArray(V1, n);
	
	//bubble sort
	t1= clock();
	bubble_sort(V1, n);
	t2=clock();
	
	printf("\nSortirano polje: \n");
    printArray(V1, n);
    printf( "Vrijeme trajanja bubble sorta je %dms\n",t2-t1 );
	

  	//heap sort
  	t1= clock();
	heapSort(V2, n);
	t2=clock();
    
  	printf("\nSortirano polje: \n");
    printArray(V2, n);
    printf( "Vrijeme trajanja heap sorta je %dms\n",t2-t1 );


	//merge sort
	t1= clock();
	mergeSort(V3, 0, n - 1);
	t2=clock();
    
  	printf("\nSortirano polje: \n");
    printArray(V3, n);
    printf( "Vrijeme trajanja merge sorta je %dms\n",t2-t1 );
	
	
	
	return 0;
}


//BEZ KOMENTARA
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//potreban za bubble i heap sort
void swap(int *a, int *b){
	
	int c = *a;
	*a = *b;
	*b = c;

}

//void merge_sort(int *V, int n);
void merge(int *V, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    
    int L[n1], R[n2];
  
    
    for (i = 0; i < n1; i++)
        L[i] = V[l + i];
    for (j = 0; j < n2; j++)
        R[j] = V[m + 1 + j];
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            V[k] = L[i];
            i++;
        }
        else {
            V[k] = R[j];
            j++;
        }
        k++;
    }
  
    
    while (i < n1) {
        V[k] = L[i];
        i++;
        k++;
    }
  
    
    while (j < n2) {
        V[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int V[], int l, int r)
{
    if (l < r) {
        
        int m = l + (r - l) / 2;
  
        mergeSort(V, l, m);
        mergeSort(V, m + 1, r);
  
        merge(V, l, m, r);
    }
}


void printArray(int V[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", V[i]);
    printf("\n");
}
  
/////////////////////////////////////////////////////////////

//void heap_sort(int *V, int n);


struct MaxHeap
{
    int n;
    int* V;
};

// A utility function to swap to integers  OBRISAN JER IMAMO OD BUBBLE s.


void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;  
    int left = 2*idx + 1; //(idx << 1) + 1;  
    int right = 2*idx + 2; // (idx + 1) << 1;

    
    if (left < maxHeap->n &&
        maxHeap->V[left] > maxHeap->V[largest])
        largest = left;

    
    if (right < maxHeap->n &&
        maxHeap->V[right] > maxHeap->V[largest])
        largest = right;

 
    if (largest != idx)
    {
        swap(&maxHeap->V[largest], &maxHeap->V[idx]);
        maxHeapify(maxHeap, largest);
    }
}


struct MaxHeap* createAndBuildHeap(int *V, int n)
{
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->n = n;   
    maxHeap->V = V; 

  
    for (i = (maxHeap->n - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}


void heapSort(int* V, int n)
{
    struct MaxHeap* maxHeap = createAndBuildHeap(V, n);

    while (maxHeap->n > 1)
    {
        swap(&maxHeap->V[0], &maxHeap->V[maxHeap->n - 1]);
        --maxHeap->n;  

        maxHeapify(maxHeap, 0);
    }
}


///////////////////////////////////////////////////////////


void bubble_sort( int *V, int n ){ 
	
	int i,j;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(V[j] > V[j+1])    //V[j+1] < V[j]
				swap(&V[j],&V[j+1]);
		}
	}
	
}

void gen_arr( int V[], int n, int dg, int gg ){
	
	int i;
	for(i=0; i<n; i++){
		
		V[i]=dg + rand() %(gg-1);
	}
}

int main(){
    
    int n;
    int *V1=NULL, *V2=NULL, *V3=NULL;
    
    printf("Unesite br. elemenata: ");
	scanf("%d", &n);
	
	V1=(int*)calloc(n, sizeof(int));
		if(V1==NULL){
			return -4;
	    }
		
	V2=(int*)calloc(n, sizeof(int));
		if(V2==NULL){
			return -4;
	    }
		
	V3=(int*)calloc(n, sizeof(int));
		if(V3==NULL){
			return -4;
	    }
	
    gen_arr(V1, n, 1, 100);
    
    int i;
    for(i=0; i<n; i++){
        V2[i]=V1[i];
        V3[i]=V1[i];
    }
	
	//int V1[] = { 12, 11, 13, 5, 6, 7 };
    //int n = sizeof(V1) / sizeof(V1[0]);
    
	time_t t1, t2;
		
	srand((unsigned)time(NULL));
	
	printf("Pocetno polje: \n");
	printArray(V1, n);
	printArray(V2, n);   //za provjeru kopiranog
	printArray(V3, n);

	
	//bubble sort
	t1= clock();
	bubble_sort(V1, n);
	t2=clock();
	
	printf("\nSortirano polje: \n");
    printArray(V1, n);
    printf( "Vrijeme trajanja bubble sorta je %ldms\n",t2-t1 );
	

  	//heap sort
  	t1= clock();
	heapSort(V2, n);
	t2=clock();
    
  	printf("\nSortirano polje: \n");
    printArray(V2, n);
    printf( "Vrijeme trajanja heap sorta je %ldms\n",t2-t1 );


	//merge sort
	t1= clock();
	mergeSort(V3, 0, n - 1);
	t2=clock();
    
  	printf("\nSortirano polje: \n");
    printArray(V3, n);
    printf( "Vrijeme trajanja merge sorta je %ldms\n",t2-t1 );
	
	free(V1);
	free(V2);
	free(V3);
	
	
	return 0;
}




