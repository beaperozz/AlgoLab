#include <stdio.h>
#include <stdlib.h>

void minmax(int a[], int len, int *min, int *max){
int i;
*min=0;
*max=0;
for(i=0; i<len; i++){
		if(a[i]< a[*min] )*min=i;
		if (a[i]> a[*max]) *max=i;
			}

}

int main(){
int a[10];
int i, m, n;
for(i=0; i<10; i++){
		    scanf("%d", &a[i]);
			}
minmax(a, 10, &m, &n);
printf("%d\n", m);
printf("%d\n", a[m]);

printf("%d\n", n);
printf("%d\n", a[n]);



return 0;
}
