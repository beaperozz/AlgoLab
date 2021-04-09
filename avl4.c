#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
		int key;
		struct _node *left;
		struct _node *cent;
		struct _node *right;
}node;


node* insert (int val, node *arr){
if(arr==NULL){
	node *a=(node*)malloc(sizeof(node));
	a->key=val;
	a->left=NULL;
	a->cent=NULL;
	a->right=NULL;
	return a;
}


if(val%arr->key==0) arr->cent=insert(val, arr->cent);
	else if(val < arr->key) arr->left=insert(val, arr->left);
			else if(val > arr->key) arr->right=insert(val, arr->right);

return arr;

}


int find(node *arr){
int i=0;
if(arr==NULL) return 0;
if(arr->left!=NULL && arr->right!=NULL && arr->cent!=NULL) i++;
				
 
if(arr->left!=NULL) i+=find(arr->left);
if(arr->right!=NULL) i+= find(arr->right);
if(arr->cent!=NULL) i+= find(arr->cent);

return i;
			

  
}




int main(){

int len, k;
scanf("%d", &len);

node *arr=NULL;


int i, temp, s;
for(i=0; i<len; i++) {
			scanf("%d", &temp);
			arr=insert(temp, arr);

			}


printf("%d", find(arr));

return 0;

}
