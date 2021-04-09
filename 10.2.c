#include <stdio.h>
#include <stdlib.h>


typedef struct node{
			int key;
			struct node *p;

} item;



int ash(int val, int a, int b, int size){
int p=999149;
return (((a*val )+ b) %p)  %size;
}




void add(item **hash, int val, int a, int b, int size){
int i=ash(val, a, b, size);

item *c=(item*)malloc(sizeof(item));
c->key=val;
c->p=hash[i];
hash[i]=c;

}





int alen(item *h){

if(h==NULL) return 0;
	else return 1 + alen(h->p);
}


int cercaval(item *h, int x){
if(h==NULL) return 0;
if(h->key==x) return 1;
	else return cercaval((h->p), x);

}



int cerca(item** h, int x, int size){

int i, r=0;
for(i=0; i<size; i++) r=r+cercaval(h[i], x);
			

return r;
}





int main(){

int len, a, b;
scanf("%d", &len);
scanf("%d", &a);
scanf("%d", &b);

item **hash=(item**)malloc(2*len*sizeof(item*));

int i, val;
int num=1;

scanf("%d", &val);
add(hash, val, a, b, 2*len);

for(i=1; i<len; i++){
			scanf("%d", &val);
			if( cerca(hash, val, 2*len)==0){
				add(hash, val, a, b, 2*len);
				num++;
				
							}

			}

int maxl=0, p, conf=0;
for(i=0; i<2*len; i++){
			p=alen(hash[i]);
			if(p!=0)conf=conf+p-1;
			if(p>maxl) maxl=p;
			}
printf("%d\n", conf);
printf("%d\n", maxl);
printf("%d\n", num);

return 0;
}
