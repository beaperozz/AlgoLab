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



void comp(int k, node *arr, node *arra){

if(arr==NULL || arra==NULL) printf("0");


if (arr->key!=arra->key) printf("0");
	else{
		if(arr->key==k) printf("1");
		else { 
			if(arr->key < k) comp(k, arr->right, arra->right);
			if(arr->key > k) comp(k, arr->left, arra->left);
			}
	}


}



int main(){

int len, k;
scanf("%d", &len);
scanf("%d", &k);

node *arr=NULL;
node *arra=NULL;

int i, temp, s;
for(i=0; i<len; i++) {
			scanf("%d", &temp);
			arr=insert(temp, arr);

			}

for(i=0; i<len; i++) {
			scanf("%d", &temp);
			arra=insert(temp, arra);

			}


comp(k, arr, arra);


return 0;

}
