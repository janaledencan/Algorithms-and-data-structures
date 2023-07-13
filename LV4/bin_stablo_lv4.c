#include<stdio.h>
#include<stdlib.h>

/*Potrebno je napraviti program u kojem dodajemo èvorove (podatke) u poredano
binarno stablo (Koristiti algoritam DODAJ P s predavanja). Podaci u tom stablu
biti æe slova. Dodavati redom slova Vašeg imena i prezimena, a program ih mora
redom dodavati u predano binarno stablo. Nacrtati kako ovakvo stablo izgleda.
Napraviti funkcije koje æe raditi obilazak ovakvog stabla:
. preorder (NLD)
. inorder (LND)
. postorder (LDN)
Napisati redoljed obilaska èvorova za svaku od ovih funkcija, za stablo koje se
dobije od Vašeg imena i prezimena.*/
	

	typedef struct cvor_{
		
		char x;
		struct cvor_* lijevi;
		struct cvor_* desni;  //provjeri koji ide cvor_ ili cvor
		
	}cvor;
	
	int nadjen;
	cvor* nadreden;	
	cvor *root=NULL;
	
	void nadji( cvor* node, char p){
		
		if(node==NULL){
			return;
		}
		
		if(node->x == p){
			nadjen = 1;
			return;
		}
		nadreden=node;
		
		if(node->x > p){
			nadji(node->lijevi, p);
		}
		else{
			nadji(node->desni, p);
		}
	}
	
	void dodajP( cvor* c, char p){
	    
	    cvor* n;
		nadjen = -1;
		nadreden = NULL;
		
		nadji(c, p);
		if(nadjen == 1){
			return;
		}		
		else{
			n = (cvor*)malloc(sizeof(cvor));
			n->x = p;
			n->lijevi = n->desni = NULL;
			if(nadreden == NULL){
				root = n;
			}
			else{
				if(p<nadreden->x){
					nadreden->lijevi = n;
				}
				else{
					nadreden->desni = n;
				}
			}	
		}
	}
	
	void NLD( cvor* c){
		
		printf("%c ", c->x);
		if(c->lijevi != NULL){
			NLD(c->lijevi);
		}
		
		if(c->desni != NULL){
			NLD(c->desni);
		}
	}
	
	void LND(cvor* c){
		
		if(c==NULL) return;
        else{
            LND(c->lijevi);
            printf("%c ", c->x);
            LND(c->desni);
        }
	}
	
	void LDN(cvor* c){
		
		if(c==NULL) return;
        else{
            LDN(c->lijevi);
            LDN(c->desni);
            printf("%c ", c->x);
        }
		
	}
	
int main(){
	
	char JL[]="JANALEDENCAN";
	
	//struct cvor* root=(cvor*)malloc(sizeof(cvor));
	
	for(int i=0; i<12; i++){
		dodajP(root, JL[i]);
	}
	printf("\n LND: ");
	LND(root);
	printf("\n LDN: ");
	LDN(root);
	printf("\n NLD: ");
	NLD(root);
	
	
	return 0;
}
