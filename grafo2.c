#include <stdio.h>
#include <stdlib.h>


typedef struct node{
			int size;
			int n_edges;
			int *edges;
} edge;




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
       

void recdfs(edge *e, int src, int *color){

int d;
int i;
for(i=0; i<e[src].n_edges; i++) {
				d=e[src].edges[i];
				if(!color[d]) {	
						color[d]=1;
						recdfs(e, d, color);
						}
				}
}



int *dfs(edge *e, int len, int src){
int i;

int *color=(int*)malloc(sizeof(int)*len);
for(i=0; i<len; i++) color[i]=0;

recdfs(e, src, color);

return color;
}



int collegato(edge *e, int len){
int i;
for(i=0; i<len; i++){
			if(e[i].n_edges==0) return 0;
			}
int *color=dfs(e, len, 0);

for(i=0; i<len; i++) if(!color[i]) return 0;

return 1;

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

	int x=collegato(e, len);
	printf("%d", x);

	return 0;
}
