#include <stdlib.h>
#include <stdio.h>

int* FindVal(int a[], int len, int val){
int *p;
int i;
for (i=0; i<len; i++)
	if (a[i]==val) {
			p=&a[i];
			return p;
				}
return NULL;
}

int main(){
int a[9];
int n;
for(n=0; n<10; n++)
  scanf("%d", &a[n]);
int val;
scanf("%d", &val);

if (FindVal(a, 10, val) == NULL) 
	printf ("non trovato");
 else 
	printf ("trovato");

return 0;

}
