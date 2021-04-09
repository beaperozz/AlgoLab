#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

typedef struct nodo {
		int val;
		struct nodo* next;
		char* str;
		
} node;




 int hash_fun(char* str, int n){
 	
 	unsigned int sum=0;
 	int i=0;
 	while(str[i]){ sum=(unsigned int) str[i];
 			 i++;
 	
 		}
 		
 	return (sum)%n;
 	
 }

 
 int find_str(node* list, char* new, int new_val){
   
    while(list!=NULL && strcmp(list->str, new)!=0) list=list->next;
    if( list!=NULL && strcmp(list->str, new)==0){
    				if( list->val < new_val) list->val=new_val;
    				return 1;}
    
    return 0; 
 
 
 }
 
 
 
 void insert_node(node** table, char* str, int val, int len){
 
  int i=hash_fun(str, 2*len);
   
  int ok=find_str(table[i], str, val);

 
 if(ok==0){  
 	 	
  	node* new=malloc(sizeof(node));
  	new->val=val;
        new->str=malloc(sizeof(char)*100);
  	strcpy(new->str, str);
  	
  	new->next=table[i];
  	table[i]=new;    
  	
  	}   
    
 }
 
 
 
  node* search(node* list, node* best){
 
	node* curr=list;
	if(best==NULL) best=curr;
	
	
 	while(curr!=NULL){
 		if( curr->val>0 && curr->val> best->val)  best=curr;
 		
 		if( curr->val>0 && curr->val==best->val && strcmp(curr->str, best->str)<0 ) best=curr;	
 		curr=curr->next;
 	
 		}
 	
 	
 	
 	return best;
 	 
 }
 

 
 node* find_best(node** table, int len){
 
 int i=0;
 node* best=NULL;

 for(i=0; i<len*2; i++){
 			if(table[i]!=NULL){
 					best=search(table[i], best);
 			
 					}
 			}
  if(best->val==-1) return NULL;
  
  best->val=-1;
 
 return best;
 }




 int main(){

 int len, val;
 scanf("%d", &len);
 char* str=malloc(sizeof(char)*100); 


	node** table=malloc(sizeof(node*)*2*len);
	int i;
	for(i=0; i<len*2; i++) table[i]=NULL;
 	 
 	for(i=0; i<len; i++){
 	       scanf("%s", str);
 	       scanf("%d", &val);
               insert_node(table, str, val, len);
 	   
 	 }
 	 
 	
 	
     for(i=0; i<15 && len>0; i++) {
     			node* ok=find_best(table, len);
     			if(ok!=NULL) printf("%s\n", ok->str);
     			}

 return 0;
}
