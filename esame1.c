#include <stdio.h>
#include <stdlib.h>

 typedef struct _node{
		int key;
		struct _node *left;
		struct _node *right;
}node;




 node* insert (int val, node *abr){
 
  if(abr==NULL){
	node *a=(node*)malloc(sizeof(node));
	a->key=val;
	a->left=NULL;
	a->right=NULL;
	return a;
       }

 if(val > abr->key) abr->right=insert(val, abr->right);
 
 if(val <= abr->key) abr->left=insert(val, abr->left);

 return abr;

 }
 
 
 
 
 
 void stampa_livello(node* abr, int lev, int i){
 
  if(lev==i && abr!=NULL) printf("%d\n", abr->key);
 	else if(abr!=NULL && i<lev){
  		i++;
		stampa_livello(abr->left, lev, i);
		
		stampa_livello(abr->right, lev, i);
		}
 }
 



int main(){


 
 int len;
 scanf("%d", &len);

 node *abr=NULL;

 int i, val;
 for(i=0; i<len; i++) {
			scanf("%d", &val);
			abr=insert(val, abr);

			}
			
			
 int livello=0;
 i=0;
 scanf("%d", &livello);
 
 stampa_livello(abr, livello, i);
 
 return 0;
}
