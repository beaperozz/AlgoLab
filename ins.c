#include <stdio.h>
#include <stdlib.h>

void ins_sort (int a[], int len){
int i, j, k;
for (i=1; i<len; i++)  {k=a[i];
			j=i-1;
			while (j>=0 && a[j]>k){a[j+1]=a[j];
						 j--;
							}
			a[j+1]=k;	
				}

}


int main(){
int len;
scanf("%d", &len);

int *a=(int*)malloc(len*sizeof(int));
int i;
for(i=0; i<len; i++) scanf("%d", &a[i]);
ins_sort(a, len);

for (i=0; i<len; i++) printf("%d\n", a[i]);

return 0;
}
