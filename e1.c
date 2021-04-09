#include <stdio.h>

int main(){
int i=1, sum;
while (i!=0){
	scanf("%d", &i);
	sum=sum+i;
}
printf("%d\n", &sum);
return 0;
}
