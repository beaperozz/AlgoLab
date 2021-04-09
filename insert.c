#include <stdio.h>
#include <stdlib.h>

void insertionsort ( int a[], int len){
int j, i;
int key;
for(j=1; j<len; j++){
		key=a[j];
		i=j-1;
		while (i>=0 && a[i]>key){
				a[i+1]=a[i];
				i=i-1;
				}
		 a[i+1]=key;
			}
}

int main(){
int len;
scanf("%d", &len);
int a[len];
int i;
for(i=0; i<len; i++)
	scanf("%d", &a[i]);
insertionsort(a,len);
for(i=0; i<len; i++)
	printf("%d\n", a[i]);
return 0;
}


