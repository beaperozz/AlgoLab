#include <stdio.h>
#include <stdlib.h>




typedef struct node{
			int n_edges;
			int *edges;
			int size;

} edge;





int color_g (edge *e, int len, int *color, int p, int c){

if(color[p]!=-1 && color[p]!=c )
	return 0;
color[p]=c;
int i;
for(i=0; i<e[p].n_edges; i++){
				int j=e[p].edges[i];
				if(color[j]==-1 && !color_g(e, len, color, j, !c)) return 0;
				if (color[j]!=-1 && color[j]==c) return 0;

				}
return 1;
}




int gbin(edge *e, int len){

	int color[len];
	int i, j;
	for(i=0; i<len; i++)
		color[i]=-1;
	
	for(i=0; i<len; i++){

			if(color[i]==-1 && !color_g( e, len, color, i, 0)) return 0;
				}

		
return 1;
}



edge* create(int n){

edge *e=(edge*)malloc(sizeof(edge)*n);

int i;
for(i=0; i<n; i++) e[i].n_edges=0;

return e;
}

 void edges_double(edge *es) {
if (es->size == 0) es->size = 1;    

es->edges = realloc(es->edges, sizeof(edge) * es->size * 2);
es->size *= 2;
}



  void graph_add_edge (edge* g, int from, int to) {

        if (g[from].n_edges + 1 > g[from].size) {        
				edges_double(g + from);    
					}
        g[from].edges[g[from].n_edges] = to;  
        g[from].n_edges++;
}
       


int main(){

	int len;
	scanf("%d", &len);
	edge *e=create(len);

	int i, j, num;

	for(i=0; i<len; i++){
			scanf("%d", &num);
			e[i].size=num;
			e[i].edges=malloc(sizeof(int)*num);

			for (j=0; j < num; j++){int a;
							scanf("%d", &a);
							graph_add_edge(e, i, a);		
								
				}
		
			}

	int x=gbin(e, len);
	printf("%d", x);

	return 0;
}
