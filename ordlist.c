#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
		int key;
		struct nodo *next;

	} node;



void insert(node *arr, int val){

	node *new=(node*)malloc(sizeof(node));
	printf("ok");
	new->key=val;
	new->next=NULL;
	while(arr->next!=NULL) 
		arr=arr->next;
	arr->next=new;

}




void print (node* head){
	if(head==NULL) {
		printf("/");
		return;
		}
	while(head!=NULL){

		printf("%d  ", head->key);
		head=head->next;
			}

}






void split(node *head, node **a, node **b ){

node* testa=head->next;
node* coda=head;


	while(testa!=NULL){

		testa=testa->next;
		if(testa!=NULL){

			testa=testa->next;
			coda=coda->next;
				}
	
			}	

	*a=head;
	*b=coda->next;
	coda->next=NULL;

}





void merge (node **a, node**b){

	if((*a)->next==NULL && (*b)->next==NULL){

			if(((*a)->key) <=((*b)->key))
					(*a)->next=*b;
				else (*b)->next=*a;

			return;
		}

	node* preca=*a;
	node* precb=*b;

	node* nexta=(*a)->next;
	node* nextb=(*b)->next;

  while(preca!=NULL && precb!=NULL){


	if (preca->key <= precb->key ){

		if( nexta->key >= precb->key){
		
			preca->next=precb;
			precb->next=nexta;
			precb=nextb;
			nextb=nextb->next;
			preca=nexta;		 
			nexta=nexta->next;

			}
		else {
			preca=nexta;
			nexta=nexta->next;

				}


		}



 	else {
		if( nextb->key >= preca->key){
		
			precb->next=preca;
			preca->next=nextb;
			preca=nexta;
			nexta=nexta->next;
			precb=nextb;		 
			nextb=nextb->next;

			}
		else {
			precb=nextb;
			nextb=nextb->next;

				}

		}

	}


}




node* mergesort (node **head){

	if ((*head)->next==NULL || head==NULL) return *head;

	node *a, *b;
	
	split(*head, &a, &b);

	mergesort(&a);
	mergesort(&b);

	merge(&a, &b);

return *head;
}





int main(){

int len;

scanf("%d", &len);


node** hasht=(node**)malloc(sizeof(node*)*100); 

int i;
int val;
int a;

for(i=0; i<len; i++){
		scanf("%d", &a);
		val= (a%11);
		hasht[val]=NULL;
		insert(hasht[val], a);

		}

for(i=0; i<100; i++){
			hasht[i]=mergesort(&(hasht[i]->next));
			print(hasht[i]);
			
		}


return 0;

}
