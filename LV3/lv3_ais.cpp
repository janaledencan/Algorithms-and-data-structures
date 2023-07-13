  
#include<stdio.h>
#include<stdlib.h>
#include <time.h>


/*int povrh(int n, int m){
	
	int i;
	
	if(n == m || n == 1 || m == 0){
		return 1;
	}
	return povrh(n-1, m-1) + povrh(n-1, m);
}


int main(){
	
	int n,m,i;
	time_t t1, t2;
	
	do{
		printf("Unesite br. n:");
		scanf("%d", &n);	
	}while(n < 0);
	
	t1 = clock();
	printf("%d\n", povrh(n, n/2));
	t2 = clock();
	
	printf( "Vrijeme trajanja je %dms\n",t2-t1 );
	
	return 0;
}
*/

/*
#define MAX 20
int sp;

void push(int x, int niz[]){  //stavljanje
	
	if(sp == MAX - 1){
		printf("Ne moze");
	}
	
	sp=sp+1;
	
	niz[sp] = x;	
}


int pop(int niz[]){  //izvadi   //mogli bi niz napraviti globalno
	
	if(sp == -1){
		printf("Ne moze");
		return  -1;
	}
	
	int temp=niz[sp];
	sp--;
		
	return temp;
}

void clear(){
	sp=0;
}

int is_empty() {
	return !sp;
}




int main(){
	
	int n,m,i;
	time_t t1, t2;
	int s1[MAX], s2[MAX];   //stogovi
	sp=0;
	
	do{
		printf("Unesite br. n:");
		scanf("%d", &n);	
	}while(n < 0);
	
	m=n/2;
	int rezPovrh=0;
	
	t1 = clock();
		
	push(n, s1);
	push(m, s2);
	
	int flag=1;
	
	do{
		flag=0;
		if(n==1 || m==0 || n==m){
			rezPovrh++;
		}
		else{
			m=pop(s2);
			n=pop(s1);
			push(n,s1);
			push(m,s2);
		}		
		
	}while(!is_empty()&& flag==0);
	
	
	printf("%d\n", rezPovrh);
	t2 = clock();
	
	printf( "Vrijeme trajanja je %ldms\n",t2-t1 );
	
	
	return 0;
}*/

// stog ostvaren nizom i rekurzijom

#include <stdio.h>
#include<stdlib.h>
#include<time.h>


//rekurzivno
    int rekPovrh(int n, int m){
        
        if(n==m || m==0 ||n==1){
            return 1;
        }
        
        return rekPovrh(n-1,m-1)+rekPovrh(n-1,m);
    }

//stog-niz

    typedef struct _stog{
      
      int sp;
      int velicina;
      int *polje;
      
    }stog; 

    stog* stvoriStog( int vel){
        
       stog* stack=(stog*)malloc(sizeof(stog));
       
        stack->sp=-1;
        stack->velicina=vel;
        stack->polje =(int*)malloc(vel*sizeof(int));
        
        return stack;
    }
    
    int isFull(stog* stack){
        return (stack->sp) >= (stack->velicina - 1);
    }
    
    
    void push( int n, stog* stack){
        
        if(isFull(stack)){    //stack->sp) >= (stack->velicina - 1)
            printf("Stack overflow hihihi");
            return;
        }
        
            stack->sp= stack->sp + 1;
            stack->polje[stack->sp]=n;
            
        //stack->polje[++stack->sp]= n;
    }
    
    int IsEmpty(stog* stack){
        
        if(stack->sp==-1){
            return 1;
        }
        return 0; 
        //return stack->sp == -1;
    }
    
    int pop(stog* stack){
        
        if(IsEmpty(stack)){
            printf("Greska");
            return -1;
        }
        else{
            
            int x = stack->polje[stack->sp];
            stack->sp--;
            return x; 
            //return stack->polje[stack->sp--];
        }
        
    }
    
    double povrhStog(int n, int m){  //stog* s1, stog* s2
           
           stog* s1 = stvoriStog(1000);
           stog* s2 = stvoriStog(1000);
           double rez=0;
          
           push(n, s1);
           push(m, s2);
           
           
           
         do{
               
               n=pop(s1);
               m=pop(s2);
               
               if(n==m ||n==1 || m==0){  
                  rez++;
               }
               else{
                   push(n-1, s1);
                   push(m-1, s2);
                   push(n-1, s1);
                   push(m, s2);
               }
               
           }while(!IsEmpty(s1) && !IsEmpty(s2)); 
           
           return rez;
    }
    

int main()
{
    int n;
    
    printf("Unesite n:\n");
    scanf("%d", &n);
    
    int m=n/2;
    
    //printf("%d", rekPovrh(n,m));
    
    
    //stog* s1 = stvoriStog(100);
    //stog* s2 = stvoriStog(100);
    printf("%f", povrhStog(n,m));  //s1, s2
    
    
    
    return 0;
}

//povezani popis


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct OE_{
	int x;
	struct OE_* next;
}OE;



OE* push(int x,OE* head){
	
	OE* s;
    	s=(OE*)malloc(1*sizeof(OE));
	if(s==NULL){
		printf("Error allocating.");
		exit;
	}
	
	
	s->x = x;
	s->next=head;
	head=s;
	return s;
}

int peek(OE* head){
    return head->x;
}

OE* pop(OE* head){
	
	if(head==NULL){
		printf("Stop");
		exit;
	}
	
	int x;
	OE* temp;
	
	x=head->x;
	temp=head;
	head=head->next;
	
	free(temp);
	temp=NULL;
	return head;
}

int Is_empty(OE* head){

	if(head==NULL){
		return 1;
	}
	else{
		return 0;	
	}
	
}

void clear(OE* head){
	
	
	while(!Is_empty(head)){
		pop(head);	
		head=head->next;	
	}		
}

	OE* head1=NULL;//s1
	OE* head2=NULL;//s2

 int main(){
	 	
 	int n,m,i;
	time_t t1, t2;

	
	//OE* s1=(OE*)malloc(sizeof(OE));
	//OE* s2=(OE*)malloc(sizeof(OE));   //stogovi
	
	//head1=(OE*)malloc(sizeof(OE));
	//head2=(OE*)malloc(sizeof(OE));
	//head1->next=NULL;
	//head2->next=NULL;
	//head1->x=0;
	//head2->x=0;
	
	do{
		printf("Unesite br. n:");
		scanf("%d", &n);	
	}while(n < 0);
	
	m=n/2;
	int rezPovrh=0;
	
	t1 = clock();
		
		
	//clear(s1);
	//clear(s2);
	
	head1=push(n, head1);
	head2=push(m, head2);
	
	
	
	do{
	    	m=peek(head2);
		    n=peek(head1);
		    
	    	head2=pop(head2);
			head1=pop(head1);
	    
		if(n==1 || m==0 || n==m){
			rezPovrh++;
		}
		else{
		
			head1=push(n-1,head1);
			head2=push(m-1,head2);
			head1=push(n-1, head1);
			head2=push(m, head2);
		}		
		
	}while(!Is_empty(head1));
	
	
	printf("%d\n", rezPovrh);
	t2 = clock();
	
	printf( "Vrijeme trajanja je %ldms\n",t2-t1 );
	
	int brisi1,brisi2;
	
	while(!Is_empty(head1)){
	   head1=pop(head1);
	}
	while(!Is_empty(head2)){
	    head2=pop(head2);
	}
	
//	free(s1);
//	free(s2);
	
 	return 0;
 }

//nepotpuno tocni
//POMOCU LISTE

typedef struct OE_{
	int x;
	struct OE_* next;
}OE;

void push(int x, OE* head){
	
	OE* s = NULL;
	s=(OE*)malloc(1*sizeof(OE));
	if(s==NULL){
		printf("Error allocating.");
		exit;
	}
	
	s->x = x;
	s->next=head;
	head=s;
}

int pop(OE* head){
	
	if(head==NULL){
		printf("Stop");
		exit;
	}
	
	int x;
	OE* temp;
	
	x=head->x;
	temp=head;
	head=head->next;
	
	free(temp);
	return x;
}

int Is_empty(OE* head){

	if(head==NULL){
		return 1;
	}
	else{
		return 0;	
	}
	
}

void clear(OE* head){
	
	int bris;
	
	while(!Is_empty(head)){
		bris=pop(head);		
	}		
}



 int main(){
	 	
 	int n,m,i;
	time_t t1, t2;
	OE* s1=NULL, s2=NULL;   //stogovi
	
	do{
		printf("Unesite br. n:");
		scanf("%d", &n);	
	}while(n < 0);
	
	m=n/2;
	int rezPovrh=0;
	
	t1 = clock();
		
		
	clear(s1);
	clear(s2);
	
	push(n, s1);
	push(m, s2);
	
	
	
	do{
		if(n==1 || m==0 || n==m){
			rezPovrh++;
		}
		else{
			m=pop(s2);
			n=pop(s1);
			push(n,s1);
			push(m,s2);
		}		
		
	}while(s1==!Is_empty());
	
	
	printf("%d\n", rezPovrh);
	t2 = clock();
	
	printf( "Vrijeme trajanja je %ldms\n",t2-t1 );
	
 	return 0;
 }


//2. pokusaj

#include <stdio.h>
#include<stdlib.h>

    typedef struct oe{
        
        int x;
        struct *oe next;
        
    }OE;
    
    void push(int value){
        
        OE* noviCvor= (OE*)malloc(1*sizeof(OE));
            if(noviCvor==NULL){
                perror("Error allocating novi cvor.");
                exit(EXIT_FAILURE);
            }
        
        noviCvor->x = value;
        noviCvor->next = head;
        head = noviCvor;
    }
    
    
    void pop(){
        
        int *temp=head;
        head = head->next;
        free(temp);
    }
    
    
    int isEmpty(){
        if(head==NULL){
            return 1;   //prazan je
        }
        else{
            return 0;
        }
    }
    
    void clear(){
        
        while(head != NULL){
            pop();
            head=head->next;
        }
    }
    
    
    

int main()
{

    OE* cvor=(OE*)malloc(n*sizeof(OE));
    if(cvor==NULL){
            perror("Error allocating novi cvor.");
            exit(EXIT_FAILURE);
    }
    
    
    

    return 0;
}


//zadnja verzija

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct OE_{
	int x;
	struct OE_* next;
}OE;



void push(int x,OE* head){
	
	OE* s;
    	s=(OE*)malloc(1*sizeof(OE));
	if(s==NULL){
		printf("Error allocating.");
		exit;
	}
	
	
	s->x = x;
	s->next=head;
	head=s;
}

int pop(OE* head){
	
	if(head==NULL){
		printf("Stop");
		exit;
	}
	
	int x;
	OE* temp;
	
	x=head->x;
	temp=head;
	head=head->next;
	
	free(temp);
	temp=NULL;
	return(x);
}

int Is_empty(OE* head){

	if(head==NULL){
		return 1;
	}
	else{
		return 0;	
	}
	
}

void clear(OE* head){
	
	
	while(!Is_empty(head)){
		pop(head);	
		head=head->next;	
	}		
}

	OE* head1=NULL;//s1
	OE* head2=NULL;//s2

 int main(){
	 	
 	int n,m,i;
	time_t t1, t2;

	
	//OE* s1=(OE*)malloc(sizeof(OE));
	//OE* s2=(OE*)malloc(sizeof(OE));   //stogovi
	
	//head1=(OE*)malloc(sizeof(OE));
	//head2=(OE*)malloc(sizeof(OE));
	//head1->next=NULL;
	//head2->next=NULL;
	//head1->x=0;
	//head2->x=0;
	
	do{
		printf("Unesite br. n:");
		scanf("%d", &n);	
	}while(n < 0);
	
	m=n/2;
	int rezPovrh=0;
	
	t1 = clock();
		
		
	//clear(s1);
	//clear(s2);
	
	push(n, head1);
	push(m, head2);
	
		m=pop(head2);
		n=pop(head1);
	
	do{
	    	m=pop(head2);
			n=pop(head1);
	    
		if(n==1 || m==0 || n==m){
			rezPovrh++;
		}
		else{
		
			push(n-1,head1);
			push(m-1,head2);
			push(n-1, head1);
			push(m, head2);
		}		
		
	}while(Is_empty(head1)==0 && Is_empty(head2)==0 );
	
	
	printf("%d\n", rezPovrh);
	t2 = clock();
	
	printf( "Vrijeme trajanja je %ldms\n",t2-t1 );
	
	int brisi1,brisi2;
	
	while(!Is_empty(head1)){
	    brisi1=pop(head1);
	}
	while(!Is_empty(head2)){
	    brisi2=pop(head2);
	}
	
//	free(s1);
//	free(s2);
	
 	return 0;
 }



