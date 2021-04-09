#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

typedef struct nodo {
		int val;
		struct nodo* next;
		
} node;




 int hash_fun(int x, int a, int b, int n){
 	int p= 999149;
 	return ( (a*x+b)%p )%n;
 	
 }






 void insert (node** table, int val, int a, int b, int n){
	
	int x=hash_fun(val,a,b,n);
	
	node* new=(node*)malloc(sizeof(node));
 	new->val=val;
 	new->next=table[x];
 	table[x]=new;

 }




//INSERIMENTO SENZA DUPLICATI

 
 int findval(node* list, int val){
    
    while(list!=NULL && list->val!=val) list=list->next;
    
    if(list==NULL) return 0;
    
    return 1; 
 
 
 }
 
 
 
 void insert_node(node** table, int val, int a, int b, int len, int* uguali){
 
  int i=hash_f(val, a, b, len);
  
  int ok=findval(table[i], val);
  
  if(!ok) {
        node* new=malloc(sizeof(node));
        new->val=val;
        new->next=table[i];
        table[i]=new;
        
     }
     
     else *uguali= *uguali +1;
      
 }
 
 
 int len_list(node* list){
 
 if(list==NULL) return 0;
  else return 1+len_list(list->next);
 
 }
 
//fine





 int length (node* list){
 
  if(list==NULL) return 0;
 	else return (1+length(list->next));
 }



 int main(){

 int len, val, a, b;
 scanf("%d", &len);
 scanf("%d", &a);
 scanf("%d", &b);

 


	node** table=malloc(sizeof(node*)*2*len);
	int i;
	for(i=0; i<len*2; i++) table[i]=NULL;
 	 
 	for(i=0; i<len; i++){
 
 	       scanf("%d", &val);
               insert(table, val, a, b, len*2);
 	   
 	 }
 	 
 	 
 	 
 	int max=0;
 	int x=0;
 	int conflitti=0;
 
 
 	for(i=0; i<len*2; i++){

 		x=length(table[i]);
 		if(x>max) max=x;
 		if(x!=0) conflitti=conflitti + x-1;
 		
 		}
 	
 
 
 printf("%d\n", max);
 printf("%d\n", conflitti);
 	
 	
 	
 	

 return 0;
}
