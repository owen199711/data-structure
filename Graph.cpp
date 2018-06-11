#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxsize 10
typedef struct Gnode{
	int serialName;//编号 
	struct Gnode* nextarc;
}gnode;
typedef struct Ghead{
	char pointName[10];//节点名 
	gnode* firstarc;
}ghead;
typedef ghead firstp[maxsize];
typedef struct graph{
	 int brim;//边
	 int pointN;//节点数 
	 firstp firstP;//表头数组	 
}Graph;

void CreatTu(Graph *&G){
	int bNum,dNum,m,n;
	gnode *nodearc;
	printf("输入创建图的边数，与顶点数：");
	scanf("%d,%d",&bNum,&dNum);
	
	for(int i=0;i<dNum;i++){
		printf("输入顶点名\n");
		scanf("%s",&G->firstP[i].pointName);
		G->firstP[i].firstarc=NULL;
	}
	for(int i=0;i<bNum;i++){
		printf("输入e(i,j)边上的顶点编号");
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
    printf("邻接表如下：");
	printf("\n%6s%8s%12s\n","编号","顶点","相邻编号");
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

