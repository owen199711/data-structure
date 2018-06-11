#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
}linklist,*link;
link creat(int n);
int delet(link &L,int m);
void show(link L);
void showbyyuesefu(link L,int m);
void show(link L){
	link p=L;
	while(p->next!=L){
		printf("%d-",p->data);
		p=p->next;
	}
		printf("%d-",p->data);

}
void showbyyuesefu(link L,int m){
	link p=L;
	link pre;
	while(p->next!=NULL){
		int n=m;
		while(n!=1&&p->next!=NULL){
			n--;
			pre=p;
			p=p->next;		
		}
	    printf("%d,",p->data);
	    	pre->next=p->next;
	    	p->next=NULL;
	    if(pre->next!=NULL)
		    p=pre->next;
	}

}
link creat(int n){
    link head=(linklist*)malloc(sizeof(linklist));
	link p1=head;
	head->data=1;
	for(int i=2;i<=n;i++){
			link p=(linklist*)malloc(sizeof(linklist)); 
			p1->next=p;
			p->data=i;
			p->next=NULL;
			p1=p;			
	}
	p1->next=head;
	return head;
}
main(){
	link L=creat(8);
	show(L);
	printf("\n"); 
	showbyyuesefu(L,2);
}
