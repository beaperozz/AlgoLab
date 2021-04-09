#include <stdio.h>
#include <stdlib.h>


 typedef struct nodo {
		int val;
		struct nodo* next;
		int num;
		
} node;




 
 int hash_fun1(int x, int n){
 	
 	return (x*13)%(2*n);
 	
 }


 int hash_fun2(int x, int n){
 	
 	return (x*37)%(2*n);
 	
 }



 void insert (node** table, int val, int n, int *a){
	
	int x=0;
	x=hash_fun1(val, n);
	int y=0;
	y=hash_fun2(val, n);
	
	
	
	if(a[x] > a[y] ) x=y;

	node* new=malloc(sizeof(node));
 	new->val=val;
 	new->next=table[x];
 	table[x]=new;
 	a[x]++;

 }
 
 
 
 
 node* find_min(node* list){
 int x;
 
 node* min=list;
 
 while(list!=NULL) {
 
 	x=list->val;
 	if(min->val >= x) min=list;
 	list=list->next; 
 	}
 	
 return min;
 
 }
 
 
 node* swap(node** table, int i, node* prec, node* testa, node* min){
 
 node* prec_min=testa;
 while(prec_min->next!=min) prec_min=prec_min->next;
 

 
 prec_min->next=min->next;
 
 min->next=testa;
 
 
 if(prec==NULL) { table[i]=min;
 		testa=min;
 		}
  
 if(prec!=NULL){ 
 		prec->next=min;
 		testa=min;
 		 }
return table[i];
 }



 void sort(node** table, int len, int* a){
 
  int i=0;
  for(i=0; i<len*2; i++){
  		int max=a[i];
		
  		if(max>1 && (i%2)==1){
  			node* pos=table[i];
  			node* prec=NULL;
  			
  			while(pos->next!=NULL){
  			
  				node* min=find_min(pos->next);
  			
  				if(pos->val > min->val) table[i]=swap(table, i, prec, pos, min);
  				pos=min;
  				prec=pos;
  				pos=pos->next;
  			

					}
					
			
  					
  				}
  
 				
 			}
 
 
 }


 
 void stampa_dispari(node** table, int len){
 
 int i;
 
 for(i=0; i<len*2; i++){
 		
 			if((i%2)==1 && table[i]!=NULL) {
 					
 					printf("%d: ", i);
 					while(table[i]!=NULL){ printf("%d ", table[i]->val);
 								table[i]=table[i]->next;}
 		
 					
 					printf("\n");
 					
 			
 			}
 
 	}
 
 
 }
 
 
 
 
 int main(){
 
 int len;
 scanf("%d", &len);
 
 node** table=malloc(sizeof(node*)*2*len);
 int i, val;
 
 int* array=(int*)malloc(sizeof(int)*len*2);
 
 for(i=0; i<len*2; i++){
 		table[i]=NULL;
 		array[i]=0;
 		}
 
 	 
 for(i=0; i<len; i++){
 
 	       scanf("%d", &val);
               insert(table, val, len, array);
 	   
 	 }
 	 


 if(i!=0){ sort(table, len, array);
 
 	stampa_dispari(table, len);
 	}
 
 
 return 0;

 
 }
 
 
 
 
 
 
