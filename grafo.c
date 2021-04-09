#include <stdio.h>
#include <stdlib.h>


typedef struct node{
			int size;
			int n_edges;
			int *edges;
} edges;




edges* create(int n){

edges *e=(edges*)malloc(sizeof(edges)*n);

int i;
for(i=0; i<n; i++) e[i].n_edges=0;

return e;
}

 void edges_double(edges *es) {
if (es->size == 0) es->size = 1;    

es->edges = realloc(es->edges, sizeof(edges) * es->size * 2);
es->size *= 2;
}



  void graph_add_edge (edges* g, int from, int to) {

        if (g[from].n_edges + 1 > g[from].size) {        
				edges_double(g + from);    
					}
        g[from].edges[g[from].n_edges] = to;  
        g[from].n_edges++;
}
       


typedef struct _queue {
int * values ;
int capacity ;
int size ;
int head ;
int tail ;
} queue ;


void queue_init ( queue *q , int capacity ) {
if ( capacity <= 0) return ;
q - > capacity = capacity ;
q - > velues = ( int *) malloc ( capacity * sizeof ( int ) ) ;
q - > size = 0;
q - > head = 0;
q - > tail = capacity - 1;
}


void queue_pushBack ( queue *q , int value ) {
q - > tail = (q - > tail + 1) % q - > capacity ;
q - > elements [q - > tail ] = value ;
q - > size ++;
}



int queue_popFront ( queue * q ) {
int head = q - > head ;
q - > head = (q - > head + 1) % q - > capacity ;
q - > size - -;
return q - > elements [ head ];
}



int queue_isEmpty ( queue * q ) {
return (q - > size == 0) ;
}

int * bfs ( edges *E , int n , int s ) {
				int * colors = ( int *) malloc ( sizeof ( int ) * n ) ;
				int * distances = ( int *) malloc ( sizeof ( int ) * n ) ;
				queue q ;
				int u , v , i ;
// i n i z i a l i z z o i colori e le d i s t a n z e
				for ( i =0; i < n ; ++ i ) {
							colors [ i ] = 0;
							distances [ i ] = -1;
							}
				colors [ s ] = 1;
				distances [ s ] = 0;
// i n i z i a l i z z o la coda
				queue_init (&q , n ) ;
				queue_pushBack (&q , s ) ;
// loop fino a t e r m i n a z i o n e della coda
				while (!queue_isEmpty (&q ) ) {
						u = queue_popFront (&q ) ;
						for ( i =0; i < E [ u ].num_edges ; ++ i ) {
										v = E[u].edges[i];
										if (!colors[v]) {
												colors[v] = 1;
												distances [v] = distances [ u ] + 1;
												queue _pushBack (&q , v ) ;
												}
											}
								}
// libero la memoria
				queue_deinit (& q ) ;
return colors ;
}



int min(edges *e, int size, int src){

			int dist=-1;
			int 
			

}




int main(){

	int len;
	scanf("%d", &len);
	edges *e=create(len);

	int i, j, num;

	for(i=0; i<len; i++){
			scanf("%d", &num);
			e[i].size=num;
			e[i].edges=malloc(sizeof(int)*num);

			for (j=0; j < num; j++){int a;
							scanf("%d", &a);
							graph_add_edges(e, i, a);		
								
				}
		
			}


	int *color=bfs(e, len, 0);
	for(i=0; i<len; i++) if(color[i]==0) return -1;
	
	int max=-1;
	for(i=0; i<len; i++) {
				int a=min(e, len, i);
				if (a>max) max=a;}
	printf("%d", a);

	return 0;

}
