#include <stdio.h>
#include <stdlib.h>


int main(){

int len;

scanf("%d", &len);

int *a=(int*)malloc(sizeof(int)*len);

int i;
for (i=0; i<len; i++){
		
		scanf("%d", &a[i]);
		
			}

int j=1, key;

for(j=1; j<len; j++){
			key=a[j];
			i=j-1;
			while(i>=0 && a[i]> key){
					a[i+1]=a[i];
					i--;

				}
			a[i+1]=key;
			}

for (i=0; i<len; i++){
		
		printf("%d\n", a[i]);
		
			}


return 0;

}



