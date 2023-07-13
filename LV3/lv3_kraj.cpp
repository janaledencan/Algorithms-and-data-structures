
#include<stdio.h>
#include<stdlib.h>
#include <time.h>


int povrhRek(int n, int m){
	
	int i;
	
	if(n == m || n == 1 || m == 0){
		return 1;
	}
	return povrhRek(n-1, m-1) + povrhRek(n-1, m);
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
    
    int isFullStack(stog* stack){
        return (stack->sp) >= (stack->velicina - 1);
    }
    
    
    void pushStack( int n, stog* stack){
        
        if(isFullStack(stack)){    
            printf("Stack overflow");
            return;
        }
        
            stack->sp= stack->sp + 1;
            stack->polje[stack->sp]=n;
            
    }
    
    int IsEmptyStack(stog* stack){
        
        if(stack->sp==-1){
            return 1;
        }
        return 0; 
        
    }
    
    int popStack(stog* stack){
        
        if(IsEmptyStack(stack)){
            printf("Greska");
            return -1;
        }
        else{
            
            int x = stack->polje[stack->sp];
            stack->sp--;
            return x; 
        }
        
    }
    
    int povrhStog(int n, int m){  
           
           stog* s1 = stvoriStog(1000);
           stog* s2 = stvoriStog(1000);
           
           int rez=0;
          
           pushStack(n, s1);
           pushStack(m, s2);
           
         do{
               n=popStack(s1);
               m=popStack(s2);
               
               if(n==m ||n==1 || m==0){  
                  rez++;
               }
               else{
                   pushStack(n-1, s1);
                   pushStack(m-1, s2);
                   pushStack(n-1, s1);
                   pushStack(m, s2);
               }
               
           }while(!IsEmptyStack(s1) && !IsEmptyStack(s2)); 
           
           return rez;
    }
    
//povezani popis

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

	OE* head1=NULL;
	OE* head2=NULL;
	
	
	
int povrhPP(OE* head1, OE* head2, int n, int m){
	    
	int rezPovrh=0;
	
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
	
	return rezPovrh;
}


	

int main()
{
    int n;
    time_t t1, t2;

    
    do{
        printf("Unesite n:\n");
        scanf("%d", &n);
        
    }while(n < 0);
    
    int m=n/2;
    	
    t1 = clock();
    printf("%d\n", povrhRek(n,m));
    t2 = clock();
    
    printf( "Vrijeme trajanja je %ldms\n",t2-t1 );  
    
    
    
    t1=clock();
    printf("%d\n", povrhStog(n,m));  
    t2=clock();
    
    printf( "Vrijeme trajanja je %ldms\n",t2-t1 );
    
    
     t1=clock();
    printf("%d\n", povrhPP(head1, head2, n, m));  
    t2=clock();
    
    printf( "Vrijeme trajanja je %ldms\n",t2-t1 );
    
    
    
    int brisi1,brisi2;
	
	while(!Is_empty(head1)){
	   head1=pop(head1);
	}
	while(!Is_empty(head2)){
	    head2=pop(head2);
	}
    
    return 0;
}
