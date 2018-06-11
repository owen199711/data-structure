#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define maxsize 30
#define max 5
typedef struct node1{
	int adjvex;//��� 
	struct node1 *nextarc;
}ArcNode;   //��ڵ�

typedef struct node2{
	int data;
    ArcNode *nextarc; 
}Vnode;  //��ͷ

typedef Vnode Adjlist[max];  //��ͷ����
typedef struct nod{
	Adjlist adjlist;
	int n;
}AlGraph;  //�ڽӱ�


typedef struct node3{
	int num;   //���
}node4;

typedef struct que{
   int data[max];
   int fort,rear;	
}queue;

typedef struct a{
	node4 num[max];
	int e[max][max];
	int a2;//����
}Graph;    //����
void creat(Graph *p){     //���󴴽�
    char arc[maxsize]="0101110110010111110110110";
	int i;
	for(i=0;i<5;i++){
		for(int j=0;j<5;j++){
			int a=arc[i*5+j]-'0';
			p->e[i][j]=a;
		}
		p->num[i].num=i;
	}
	p->a2=i;
}
void show(Graph *p){     //�������
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%d ",p->e[i][j]);
		}
		printf("\n");
	}
}

void showTu(AlGraph *Ap){
	ArcNode *p;
	int i;
	printf("�ڽӱ����£�");
	printf("\n%6s%12s\n","���","���ڱ��");
	for(i=0	;i<Ap->n;i++){
		printf("%4d ",Ap->adjlist[i].data);
		for(p=Ap->adjlist[i].nextarc;p!=NULL;p=p->nextarc){
			printf("%6d",p->adjvex);
		}
		printf("\n");
	} 
	 
}

void creatTu(AlGraph *&Ap,Graph *p){// 
	int i,j;
	ArcNode *pa;
	Ap=(AlGraph*)malloc(sizeof(AlGraph));
	for(i=0;i<p->a2;i++){
		Ap->adjlist[i].nextarc=NULL;
		Ap->adjlist[i].data=i;
	}
	for(i=0;i<p->a2;i++){
		for(int j=0;j<p->a2;j++){
			if(p->e[i][j]!=0)
			{
		    	pa=(ArcNode*)malloc(sizeof(ArcNode));
				pa->adjvex=j;
				pa->nextarc=Ap->adjlist[i].nextarc;
                Ap->adjlist[i].nextarc=pa;
			}
		}
	}
	Ap->n=p->a2;
}

void creat2(AlGraph *&p){//���뷨�����ڽӱ�
    int a,b,m,n;
    ArcNode *h;
    printf("������Ķ������������");
    scanf("%d,%d",&a,&b);
    for(int i=0;i<a;i++){
    	printf("���붥����:");
		scanf("%d",&p->adjlist[i].data);
		p->adjlist[i].nextarc=NULL;
	}
	
	 for(int i=0;i<b;i++){
	 	printf("��%d���µĶ����:",i);
	 	scanf(" %d,%d",&m,&n);
	 	h=(ArcNode*)malloc(sizeof(ArcNode));
	 	h->adjvex=m;
	 	h->nextarc=p->adjlist[n].nextarc; 
	 	p->adjlist[n].nextarc=h;
	 	
	 	h=(ArcNode*)malloc(sizeof(ArcNode));
	 	h->adjvex=n;
	 	h->nextarc=p->adjlist[m].nextarc; 
	 	p->adjlist[m].nextarc=h;
	 	
	 }
    p->n=a; 	
}


void change(Graph *&G,AlGraph *T){//�� �����ת�� 
	    ArcNode *p;
	    int i,j;
	    for(i=0;i<T->n;i++){
	    	for(j=0;j<T->n;j++){
	    		G->e[i][j]=0;
			}
		}
		for(i=0;i<T->n;i++){
	      for(p=T->adjlist[i].nextarc;p!=NULL;p=p->nextarc){
	      	int n=p->adjvex;
	     	G->e[i][n]=1;
		    }
	    }
}

void DFS(AlGraph *T,int v,int vist[max]){//��ȱ��� 
	ArcNode *p;
	vist[v]=1;
	printf(" %d ",v);
	p=T->adjlist[v].nextarc; 
	while(p!=NULL){
		if(vist[p->adjvex]==0){
			DFS(T,p->adjvex,vist);
		}
		p=p->nextarc;
	}
}

void BFS(AlGraph *g,int v,int vist[max]){//��ȱ��� 
	ArcNode *p;
	queue *q=(queue*)malloc(sizeof(queue));
	q->fort=0;q->rear=0; 
	int a;
	printf(" %d",v);
	vist[v]=1;
	q->rear=(q->rear+1)%max;
	q->data[q->rear]=v;
	while(q->fort!=q->rear){
		q->fort=(q->fort+1)%max; 
		a=q->data[q->fort];
		p=g->adjlist[a].nextarc;
		while(p!=NULL){
			if(vist[p->adjvex]==0){
				printf( " %d",p->adjvex);
		    	q->rear=(q->rear+1)%max;
		     	vist[p->adjvex]=1;
		    	q->data[q->rear]=p->adjvex;
			}
		    p=p->nextarc;
		}
	}
	
}
			
main(){
	int vist[max];
	for(int i=0;i<max;i++)
	    vist[i]=0;
	Graph p;
	AlGraph *T;
	creat(&p);
	creatTu(T,&p);
	show(&p);
	showTu(T);
	DFS(T,1,vist);
	BFS(T,1,vist);
//	creat2(T);
//	change(p,T);
//	show(p);
}



