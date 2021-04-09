#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
			int n_edges;
			int *edges;
} edges;



edges *read_graph (int len) {
	edges *e=(edges*)malloc(sizeof(edges)*len);

	int  ne, i, j;
	
	
	for (i=0; i < len; ++i) {
		scanf("%d", &(ne));
		e[i].n_edges = ne;
		e[i].edges = (int *) malloc(sizeof(int) * ne);

	for (j=0; j < ne; ++j) {
			scanf("%d", e[i].edges + j);
			}
		}

return e;

}

void look(edges *e, int i, int len,  int val, int a[], int l){

int i;

for(i=0; i<len; i++){
		e[i].edges[

}

}




int ciclico( edges *e, int len, int n){
	int i, k;
	int *a=(*int)malloc(sizeof(int)*len);
	for(i=0; i<len ; i++) a[len]=0;

	while(i!=-1){
			if(e[i].n_edges>0){
				int t=e[i].n_edges;
				while(t!=0){

				if(e[i].edges[t]==n) return 1;
				if(e[i].edges[t]>n) t--;
					else t=-1;
				
					}
				
			
				
			
				}			


			else {
				n++;
				i=n;

			}
		

			}



			
return 0;


}

t=0;
				while(t<e[i].n_edges){
				int c=ciclico(e, len, e[i].edges[t], n);
				if(c==1) return 1;
					else t++;

int main(){

	
	int len;
	scanf("%d", &len);
	edges *e=read_graph(len);	
	printf("%d", ciclico(e, len, 0, 0));

return 0;

}
