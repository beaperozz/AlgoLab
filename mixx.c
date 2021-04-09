#include <stdio.h>
#include <stdlib.h>


void mixa(int len1, int a[], int len2, int b[], int c[]){
int val=0;
int i=0, j=0, k=0;
for(i=0; i<len1+len2; i++){
			if(j<len1 && k<len2){
				if (a[j]<b[k]) {c[i]=a[j];
					j++;}
				else {c[i]=b[k];
						k++;}}
			else if(len1==j) {c[i]=b[k];
						k++;}
				else  {c[i]=a[j];
					j++;}
				}

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

int *c=(int *)malloc((len2+len1)*sizeof(int));
mixa(len1, a, len2, b, c);
for(i=0; i<len1+len2; i++) printf("%d\n", c[i]);

return 0;
}
