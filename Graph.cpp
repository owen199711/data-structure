#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxsize 10
typedef struct Gnode{
	int serialName;//��� 
	struct Gnode* nextarc;
}gnode;
typedef struct Ghead{
	char pointName[10];//�ڵ��� 
	gnode* firstarc;
}ghead;
typedef ghead firstp[maxsize];
typedef struct graph{
	 int brim;//��
	 int pointN;//�ڵ��� 
	 firstp firstP;//��ͷ����	 
}Graph;

void CreatTu(Graph *&G){
	int bNum,dNum,m,n;
	gnode *nodearc;
	printf("���봴��ͼ�ı������붥������");
	scanf("%d,%d",&bNum,&dNum);
	
	for(int i=0;i<dNum;i++){
		printf("���붥����\n");
		scanf("%s",&G->firstP[i].pointName);
		G->firstP[i].firstarc=NULL;
	}
	for(int i=0;i<bNum;i++){
		printf("����e(i,j)���ϵĶ�����");
		scanf("%d,%d",&m,&n);
		getchar();
		nodearc=(gnode*)malloc(sizeof(gnode));
		nodearc->serialName=m;
		nodearc->nextarc=G->firstP[n].firstarc;
		G->firstP[n].firstarc=nodearc;	
		nodearc=(gnode*)malloc(sizeof(gnode));
		nodearc->serialName=n;
		nodearc->nextarc=G->firstP[m].firstarc;
		G->firstP[m].firstarc=nodearc;
	}
	G->brim=bNum;G->pointN=dNum;
}

void show(Graph *p){
	gnode *node;
    printf("�ڽӱ����£�");
	printf("\n%6s%8s%12s\n","���","����","���ڱ��");
	for(int i=0;i<p->pointN;i++){
		printf("%4d%8s",i,p->firstP[i].pointName);
		for(node=p->firstP[i].firstarc;node!=NULL;node=node->nextarc){
			printf("%8d",node->serialName);
		}
		printf("\n");
	}
}

int main(){
	Graph *G;
	CreatTu(G);
	show(G);	
}

