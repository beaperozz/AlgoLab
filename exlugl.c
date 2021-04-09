#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
			int val;
			char *s;
			struct node *next;

}item;


int hashing( int x, int size){
	
	return (x % 109) %size;
}




void add(item **hash, int chiave, char *s, int size){
	int i=hashing(chiave, size);

	item *c = (item*)malloc(sizeof(item));
	c->val=chiave;
	c->s=s;
	c->next=hash[i];
	hash[i]=c;

}


item *cercaval(item *h, int x){
	if(h==NULL) return NULL;
	if(h->val==x) return h;
		else return cercaval((h->next), x);

}




void insertooo(item **hash, char* s, int chiave, int size){

	int i=0;
	i=hashing(chiave, size);
	
	item *r=(item*)malloc(sizeof(item));

 	r=cercaval(hash[i], chiave);

	if (r==NULL) add(hash, chiave, s, size);
		else { r->s=s; }
			
}




item *sort(item* primo){
if(primo->next==NULL) return primo;

item *ultimo, *p;

int flag;
char* a;

ultimo=NULL;

flag=1;

while(flag==1){

	p=primo;
	flag=0;
	while(p->next !=ultimo){

			if(strcmp(p->s, (p->next)->s) >0){
							a=p->s;
							p->s=(p->next)->s;
							(p->next)->s=a;
							flag=1;

						}
			p=p->next;

				}
	ultimo=p;



	}

	
return (primo);
}






void stampa(item *t){

if(t==NULL) return;
printf("%s\n", t->s);
stampa(t->next);
}



void initialize(item** tab, int m) {
  int i;
  for(i=0; i<m; i++) {
    tab[i]=NULL;
  }
}

void insert(item** hash, int key, char* value, int m) {
  int i=hashing(key, m);
  item* new=(item*)malloc(sizeof(item));
  new->s=(char*)malloc(100*sizeof(char));
  new->val=key;
  strcpy(new->s, value);
  int ok=1;

  if(hash[i]==NULL) {
    hash[i]=new;
    new->next=NULL;
  }
  else {
    item *p=NULL, *aux, *flag=NULL, *prec=NULL;
    aux=hash[i];
	while( aux!=NULL && ok  ) {
	if((strcmp(aux->s, value)) <0) flag=p;
	
	prec=p;
     	p=aux; 
	if( aux->val==key) {printf("evvai"); ok=0;}
	 aux=aux->next;
    }

    if (aux!=NULL) {
     		 if(p->val==key) {
       				 strcpy(p->s, value);
       				 return;
     				 }
		 if(flag!=NULL) {
				prec->next=aux;
				p->next=flag->next;
				flag->next=p;
				
				}
   		 }

    if(hash[i]==aux) hash[i]=new;
    	else p->next=new;
    new->next=aux;
  }
}




int main(){
	int len;
	scanf("%d", &len);


	item **hash=(item**)malloc(2*len*sizeof(item*));

	initialize(hash, 2*len);
	int i, chiave;

	char *s=(char*)malloc(101*sizeof(char));
	
	for(i=0; i<len; i++){	scanf("%d", &chiave);
				scanf("%s", s);
				insert(hash, chiave, s, 2*len);

				}
	
	int k=0;
	scanf("%d", &k);
	if(hash[k]==NULL) printf("vuota");
		else {	
			
			stampa(hash[k]);	
			}

return 0;
}







