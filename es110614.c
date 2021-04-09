#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
			int val;
			char *s;
			struct node *next;

}item;


int ash( char *s, int size){
	
	int i=0, p=0;
	while (s[i]!='\0') {p+=s[i];
				i++;}
	
	int a= p%size;
	
	return a;
}




void add(item **hash, int valore, char *s, int size){
	int i=ash(s, size);

	item *c = (item*)malloc(sizeof(item));
	c->val=valore;
	c->s=s;
	c->next=hash[i];
	hash[i]=c;

}


item *cercaval(item *h, char *s){
	if(h==NULL) return NULL;
	if(strcmp(s, h->s)==0) return h;
		else return cercaval((h->next), s);

}




void insert (item **hash, char* s, int valore, int size){

	int i=0;
	i=ash(s, size);
	
	item *r=(item*)malloc(sizeof(item));

 	r=cercaval(hash[i], s);

	if (r==NULL) add(hash, valore, s, size);
		else { if((r->val )< valore) r->val=valore; }
			
}



void dealloc(item **hash, char*s, int size){
int i=ash(s, size);

item *p=cercaval(hash[i], s);
p->s="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

printf("%s\n", p->s);



}






void stampa(item **hash, int len){

	
	item *p;
	
	int temp=0;
	char *a=(char*)malloc(sizeof(char)*101);
	a='\0';
	
	
	int n;
	for(n=0; n<len; n++){	
				if(hash[n]!=NULL){	
							 p=hash[n];
							while(p!=NULL){
							 if(temp < p->val) { temp=p->val;
										a=p->s;
										}
							if (temp==p->val) 
								if(strcmp(a, p->s)<0) {a=p->s;		
											}

							p=p->next;
							}
						}
				}


	printf("%s\n", a);
	dealloc (hash, a, len);


}




int main(){
	int len;
	scanf("%d", &len);


	item **hash=(item**)malloc(2*len*sizeof(item*));
	int i, valore;

	char *s=(char*)malloc(101*sizeof(char));
	
	for(i=0; i<len; i++){
				scanf("%s", s);
				scanf("%d", &valore);
				insert(hash, s, valore, 2*len);

				
				}

	for(i=0; i<15; i++){
	
	stampa(hash, 2*len);}

return 0;
}
