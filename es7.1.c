// LISTA BIDIREZIONALE CON RICERCA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

typedef struct nodo {
		int val;
		struct nodo* next;
		struct nodo* prec;
		int cont;
		
} node;


 node* swap_prec(node* list, node* curr){
 
 	if(curr->prec==NULL)
 		return curr; //è il primo elemento
 	
 	if(curr->next==NULL && curr->prec->cont>= curr->cont) return list;
 		
 	node* new=curr->prec;
 	
 	while( new!=NULL && new->cont < curr->cont) { new=new->prec;  //cerca l'elemento con conteggio minore stretto
 						
 							}	
 	
 	curr->prec->next=curr->next;
 	if(curr->next!=NULL) curr->next->prec=curr->prec;
 	
 	curr->prec=new;
 	if(new!=NULL){
 		new->next->prec=curr;
 		curr->next=new->next;
 		new->next=curr;
 		return list;
 		}
 		else { curr->next=list;
 		     list->prec=curr;
 		    
 		     return curr;
 		     }
 	
 
 }




 node* search(node* list, int val, int* posizione){
 
	node* curr=list;
	int i=0;
 	while(curr!=NULL && curr->val!=val){
 		
 		curr=curr->next;
 		i++;
 	
 	}
 	if(curr==NULL){
 			*posizione=-1;
 			return list;
 			
 			}
 	*posizione=i;
 	
 	
	curr->cont=curr->cont+1;		
 	list=swap_prec(list, curr);
 	
 	return list;
 	 
 }





node* add_tail (node* b, int val){

 node* t=(node*)malloc(sizeof(node));
 t->val=val;
 t->next=NULL;
 t->prec=b;
 t->cont=0;
 
 b->next=t;
 return b->next;

}


 int main(){

 int len;
 scanf("%d", &len);
 int val;
 
 
 if(len!=0){
 	node* list=(node*)malloc(sizeof(node));
 	scanf("%d", &val);
 	list->val=val;
 	list->next=NULL;
	list->prec=NULL;
	list->cont=0;
 
 	node* a=list;
 	int i;
 
 
 	for(i=0; i<len-1; i++){
 
 	       scanf("%d", &val);
        
 	       a=add_tail(a, val);
 	   
       
 	 }
 	
 	int posizione=0;
 	
 	while(posizione!=-1){
 		scanf("%d", &val);
 	
 		list=search(list, val, &posizione);
 		printf("%d\n", posizione);
 
 	}




	node* temp;
 
 	while(list!=NULL){
        	temp=list;
        	list=list->next;
        	free(temp);
 
       	}
       
}


 return 0;
}






//LISTA MONODIREZIONALE CON RICERCA


#include <stdio.h>
#include <stdlib.h>

typedef struct  pissi{
			int key;
			struct pissi *p;
} node;


void *add(node *a, int val){
node *b=a;
while(b->p!=NULL) b=b->p;


node *l=(node*)malloc(sizeof(node));

b->p=l;
l->key=val;
l->p=NULL;


}



node* swap(node *a, int i){
int n;
node *b=a;
for(n=0; n<i-1; n++){
		b=b->p;
			}
node *c=b->p;
if(c->p==NULL) b->p=NULL;
	else b->p=c->p;
c->p=a;
return c;
}


int cerca(node *a, int val){

int i=0;

while(a!=NULL){
		if(a->key==val) return i;	
		i++;
		a=a->p;
			
		}
return -1;
}



int main(){
int len;
scanf("%d", &len);

node *a=(node*)malloc(sizeof(node));
int val;
scanf("%d", &val);
a->key=val;
a->p=NULL;
int i;
for(i=1; i<len; i++){
			scanf("%d", &val);
			add(a, val);
			}



while(i!=-1){ 
		scanf("%d", &val);
		
		i=cerca(a, val);

		if(i>0) a=swap(a,i);
		printf("%d\n", i);
		}

return 0;
}


