#include <stdio.h>
#include <stdlib.h>


typedef struct node{
			int val;
			struct node *min;
			struct node *max;


}nodo;


nodo *insert(nodo *root, int key) {
if (root == NULL) {
	nodo *new = malloc(sizeof(nodo));    
         new->val = key;
        new->min = NULL;
        new->max = NULL;
	return new; 
   }
if (key <= root->val) {
        root->min = insert(root->min, key);
    } else {
        root->max = insert(root->max, key);
    }

return root;

}

int findval(int a, nodo *arr){
if(arr==NULL) return -1;
if(a==arr->val) return 0;


int found=-1;
if(arr->val < a ) 
	found=findval(a, arr->max);
if (arr->val > a)
	found=findval(a, arr->min);

if(found>=0) return 1+found;
	else return -1;

}


nodo *addric(int a, nodo *arr){
	if(arr==NULL){
	nodo *pio=malloc(sizeof(nodo));
	pio->val=a;
	pio->max=NULL;
	pio->min=NULL;
	return pio;}

	if(a > arr->val) arr->max=addric(a, arr->max);
		else arr->min=addric(a, arr->min);
	
	return arr;
			}



int main( int argc, char *argv[]){

int a, len, i, m;

scanf("%d", &len);
nodo *arr=NULL;
for(i=0; i<len; i++){ 
		scanf("%d", &m);
		arr=insert( arr, m);
		}

while (1){
	scanf("%d", &a);
	if(a<0) break;
	int c=findval(a, arr);
	if(c==-1) printf("NO\n");
		else printf("%d\n", c);

	}


return 0;
}
