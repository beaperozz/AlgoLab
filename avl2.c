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


void stampa(node *arr){
if(arr!=NULL){
		stampa(arr->left);
		
		printf("%d\n", arr->key);
		stampa(arr->right);
		}


}



int main(){

int len;
scanf("%d", &len);

node *arr=NULL;

int i, temp, s;
for(i=0; i<len; i++) {
			scanf("%d", &temp);
			arr=insert(temp, arr);

			}

stampa(arr);



return 0;

}
