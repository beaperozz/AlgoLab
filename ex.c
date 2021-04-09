#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _list_elem {

	int key ;
	int val ;
	struct _list_elem * next ;
	int len;

	} list_elem_t ;



typedef struct {
	list_elem_t ** table ; /* Tabella Hash ( array di liste ) */
	int m ; /* D i m e n s i o n e della tabella */
} chained_hash_t ;





int hash1(int x, int len2){

return x*(13%len2);

}




int hash2(int x, int len2){

return x*(37%len2);

}




chained_hash_t *new_hash_table ( int m ) {
	int i ;
	chained_hash_t*T = malloc( sizeof (chained_hash_t ) ) ;
	T->table = malloc(m*sizeof(list_elem_t*)) ;
	T->m = m;
	for ( i =0; i < m ; i ++) {
	T->table[i] = NULL ;
	}
return T ;
}





int max( int p1, int p2, chained_hash_t *T){

	if(((T->table[p1])->len ) > ( (T->table[p2])->len) ) return p2;
		else return p1;

return 0;
}






void chained_hash_insert( chained_hash_t * T , int k , int elem, int *a) {
/* Calcolo dell ’ hash */
	int posizione1= hash1(k , 2*(T->m) );
	int posizione2= hash2(k , 2*(T->m) );
	list_elem_t * new_elem = malloc (sizeof(list_elem_t));
	new_elem-> key = k ;
	new_elem-> val = elem;

	int posizione=-1;

	if(a[posizione1] > a[posizione2]) posizione=posizione2;
		else posizione=posizione1;

	new_elem->next = T->table[posizione]; // NULL se la lista era vuota
	T->table[posizione] = new_elem;
	a[posizione]++;



}


void orderhash (chained_hash_t *T, int len, int *a){

int i=0;
for(i=0; i<len && a[i]!=0; i++) {
	
	T->table[i]=orderlist(T->table[i], a[i]);

		}


}



void swap(list_elem_t *prec, list_elem_t *occ, list_elem_t *next){

prec->next=occ->next;
occ->next=next->next;
next->next=occ;


}






list_elem_t *orderlist(list_elem_t *t, int len){


if(t->next==NULL) return t;


t->next=orderlist(t->next, len-1);

if(t->val >= (t->next)->val) return t;

	else{
		list_elem_t *prec=t;
		list_elem_t *occ=t;
		list_elem_t *next=t->next;


		 while(t->val < (t->next)->val && t->next!=NULL){	
								
		swap(prec, occ, next);

			} 


}



void printhash(chained_hash_t *T, int len, int *a){

	int i=0;
	for( i=0; i<len && i%2!=0; i++){

		if(a[i]!=0) {

				printf("%d: ", i);
				list_elem_t *t=T->table[i];
				while(t!=NULL) printf("%d ", t->val);
				}

		}


}



int main(){
	
	int len;
	scanf("%d", &len);
	
	chained_hash_t *T=new_hash_table(len);
	
	int i=0, el;
	int *a=(int*)malloc(sizeof(int)*len);

	for(i=0; i<len; i++) a[i]=0;

	for(i=0; i<len; i++) {		
			scanf("%d", &el);
			chained_hash_insert(T, el, el, a);
			}

	orderhash(T, len, a);

	printhash(T, len, a);



return 0;
}
