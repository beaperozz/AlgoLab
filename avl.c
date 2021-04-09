#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
		int key;
		struct _node *left;
		struct _node *right;
}node;


 node* insert (int val, node *arr){
 
  if(arr==NULL){
	node *a=(node*)malloc(sizeof(node));
	a->key=val;
	a->left=NULL;
	a->right=NULL;
	return a;
       }

 if(val > arr->key) arr->right=insert(val, arr->right);
 
 if(val <= arr->key) arr->left=insert(val, arr->left);

 return arr;

 }
 
 
 //altezza di un avl
 
 int altezza(node *arr){
	if(arr==NULL) return 0;
	int l, r;
	l=altezza(arr->left) +1;
	r=altezza(arr->right) +1;

if(l>r) return l;
	else return r;

}


//cammino massimo e chiave minima

 int max (node* avl, int* key_min){
 
 int camminol=0;
 int camminor=0;
 int max_c=0;
 	
 if(avl!=NULL) {  	int key_left=avl->key;
 
 			camminol=avl->key + max(avl->left, &key_left);
 			
 			camminor=avl->key + max(avl->right, key_min);
 			
 			if(camminor > camminol){ max_c=camminor;
 						 *key_min=avl->key;
 						 }
 				else{ 
 				     max_c=camminol;
 				      *key_min=key_left;
 				      }
 				     
 
 		} 
 
 return max_c;
 
 }


//stampa ordinata crescente

 void stampa(node *arr){
 if(arr!=NULL){
		stampa(arr->left);
		
		printf("%d\n", arr->key);
		stampa(arr->right);
		}


}




//confronto del cammino per la chiave k

void comp(int k, node *arr1, node *arr2){

if(arr1==NULL || arr2==NULL) printf("0");


if (arr1->key!=arr2->key) printf("0");
	else{
		if(arr1->key==k) printf("1");
		else { 
			if(arr1->key < k) comp(k, arr1->right, arr2->right);
			if(arr1->key > k) comp(k, arr1->left, arr2->left);
			}
	}


}

int main(){

 int len;
 scanf("%d", &len);

 node *avl=NULL;

 int i, temp, s;
 for(i=0; i<len; i++) {
			scanf("%d", &temp);
			avl=insert(temp, avl);

			}
			
 if(len>0){
 
 	int key=avl->key;
			
 	int camm_max=max(avl, &key);
 
			
 	printf("%d\n", key);
 	}
 	
 	else printf("0\n");






return 0;

}
