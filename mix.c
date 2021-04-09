#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b){
int c=a;
a=b;
b=c;
}


int mix(int len1, int a[], int len2, int b[]){
int val=0;
int i;
int j;
for(i=0; i<len1; i++){
		for(j=0; j<len2; j++){
			 if(a[i]==b[j]) val++;
		 			}
			}

return val;
}


int main(){
int len1;
int len2;
int i;

scanf("%d", &len1);
int *a=(int *)malloc(len1*sizeof(int));
for(i=0; i<len1; i++) {scanf("%d", &a[i]);}

scanf("%d", &len2);
int *b=(int *)malloc(len2*sizeof(int));
for(i=0; i<len2; i++) {scanf("%d", &b[i]);}

int occ= mix(len1, a, len2, b);
printf("%d", occ);

return 0;
}
