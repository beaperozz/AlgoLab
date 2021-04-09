#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
int c;
c=*a;
*a=*b;
*b=c;

}


int main(){
int a,b;
scanf("%d", &a);
scanf("%d", &b);
swap(&a, &b);
printf("%d\n", a);
printf("%d\n", b);

return 0;
}
