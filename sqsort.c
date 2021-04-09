#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int comp(const void *a, const void *b){
char *x=*(char**)a;
char *y=*(char**)b;
return -strcmp(x,y);
}





int main(){

int len,i;

scanf("%d", &len);

char **a=(char**)malloc(len*sizeof(char *));

for(i=0; i<len; i++){
		     a[i]=(char*)malloc(101*sizeof(char));
		     scanf("%s\n", a[i]);
			}


qsort(a, len, sizeof(char*), comp);

for(i=0; i<len; i++) 
	printf("%s\n", a[i]);

return 0;
}
