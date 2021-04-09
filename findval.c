#include <stdio.h>
#include <stdlib.h>

int* FindVal(int a[], int len, int val){
int i, *b;
for (i=0; i<len; i++){if(a[i]==val) 
			{b=&a[i];
			return b;}

			}
return NULL;
}

int main(){
int a[10];
int i, val;
for(i=0; i<10; i++){
		scanf("%d", &a[i]);
			}
scanf("%d", &val);
if(FindVal(a, 10, val)==NULL) printf("non trovato");
	else printf("trovato");

return 0;
}
