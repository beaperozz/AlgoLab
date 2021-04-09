#include <stdio.h>
#include <string.h>

int my_strlen(char *s){
int a=0, i=0;
while (s[i]){   i++;
		a++;
			}
return a;

}


int main(){
char s[10];
scanf ("%s", s);

int a = my_strlen(s);
printf("%d", a);
return 0;

}
