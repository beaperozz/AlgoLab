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
