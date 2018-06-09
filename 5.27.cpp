#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为
//
//3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。
typedef struct node{
	int data;
	struct node * next;
}*Address;
Address creat(int n){
    Address head=(Address)malloc(sizeof(Address));
	Address p1=head;
	head->data=1;
	for(int i=2;i<=n;i++){
			Address p=(Address)malloc(sizeof(Address)); 
			p1->next=p;
			p->data=i;
			p->next=NULL;
			p1=p;			
	}
	return head;
}


Fanzhuan(Address &L,int k){
	int i,n;
	Address Lp,p1=L;
	while(p1->next!=NULL){
		p1=p1->next;
		i++;
	}
  while(n=i>k&&Lp->next!=NULL){
  	Lp=L->next;
  	Address p[k];
  	for(int a=0;a<k;a++){
  		p[a]=Lp;
  		Lp=Lp->next;
	  }
	L=p[k];
	for(int a=k-1;a>0;a--){
		if(k-a<=a){
			Address b;
			b=p[k];
			p[k-a]=b;
			p[k]=p[k-a];
		}
	  	
	  }
	for(int a=0;a<k;a++){
	  	p[a]->next=p[a+1];
	  }
	if(n>i-k){
		p1->next=p[0];
	}
    n=n-k;
  }
	
}

void show(Address L){
	Address p=L;
	while(p->next!=NULL){
		printf("%d-",p->data);
		p=p->next;
	}
		printf("%d-",p->data);

}


main(){
	Address p;
	int n;
	printf("输入你要创建的节点数");
	scanf("%d",&n);
    p=creat(n);
    show(p);
//    printf()
    Fanzhuan(p,3);
    show(p);
}
