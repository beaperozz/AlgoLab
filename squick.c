#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int distribuzione(char **a, int sx, int px, int dx) { 
int i=sx-1;
int j;
char *b=(char*)malloc(101*sizeof(char));

for(j=sx; j<dx; j++){	
			if (strcmp(a[j], a[px])<0) {i++;
					  b=a[i];
					  a[i]=a[j];
					  a[j]=b;
					}

		}

b=a[px];		
a[px]=a[i+1];
a[i+1]=b;

return i+1;
}

void quicksort( char **a, int sx, int dx ) {
  
  int perno, pivot;
  if( sx < dx ) {
 
    pivot = dx;

    perno = distribuzione(a, sx, pivot, dx); 

    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
    
  }

}




int main() {
  
  int i, n;
int len;
scanf("%d", &len);

char **a=(char**)malloc(len*sizeof(char *));

for(i=0; i<len; i++){
		     a[i]=(char*)malloc(101*sizeof(char));
		     scanf("%s", a[i]);		}

  quicksort(a, 0, len-1);
 

  for( i = 0; i < len; i++ ) 
    printf("%s\n", a[i]);
	
  return 0;
}
