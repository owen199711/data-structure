#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
#define Maxsize 100
#define M 8
#define N 8

typedef struct  sa{
	int x;
	int y;
	int id;
}stap;
typedef struct st{
	stap data[Maxsize];
	int top;
} stype;
bool mystap(int x1,int y1,int x2,int y2,int mg[][N+2]);
void  show(int mg[][N+2]);
void creatMg();
main(){
	char arc;
	int mg[M+2][N+2]={
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
       srand(time(NULL));
       int c=0;
	do{
		for(int i=1;i<4;i++){
	        int b=rand()%8+1;
	     	mg[i][b]=1;	
		}
    	if(!mystap(1,1,M,N,mg)){
     	  show(mg);
	      printf("\n�޽�");
	      for(int i=1;i<4;i++){
	        int b=rand()%8+1;
	     	mg[i][b]=0;	
		   }
		}
		printf("\n�Ƿ����(y/n)");
	    scanf(" %c",&arc); 
	    srand(time(0)+c*100);
	    c++;
      }while(arc=='y');

}
bool mystap(int x1,int y1,int x2,int y2,int mg[][N+2]){
	int x,y,id,find;
	stype p;
	p.top=-1;
    p.top++;
	p.data[p.top].x=x1;
	p.data[p.top].y=y1;
	p.data[p.top].id=-1;

	while(p.top>-1){
		x=p.data[p.top].x;
		y=p.data[p.top].y;
		id=p.data[p.top].id;
		if(x==x2&&y==y2){
		  for(int i=0;i<=p.top;i++){
		      int a=p.data[i].x;int b=p.data[i].y;
		      mg[a][b]=-2;
		      show(mg);
		      Sleep(300);
		      system("cls");
		  }
		return true;
		}
		find=0;
		while(id<4&&find==0){
			id++;
			switch(id){
				case 0:x=p.data[p.top].x-1;y=p.data[p.top].y;break;
				case 1:x=p.data[p.top].x;y=p.data[p.top].y+1;break;
				case 2:x=p.data[p.top].x+1;y=p.data[p.top].y;break;
				case 3:x=p.data[p.top].x;y=p.data[p.top].y-1;break;
			}
			if(mg[x][y]==0)
			  find=1;
		}
		if(find==1){
			p.data[p.top].id=id;
			p.top++;
			p.data[p.top].x=x;
			p.data[p.top].y=y;
			p.data[p.top].id=-1;
			mg[x][y]=-1;
		}
		else{
			mg[p.data[p.top].x][p.data[p.top].y]=0;
			p.top--;
		}

	}
	return false;
}

void  show(int mg[][N+2]){
	    for(int i=0;i<M+2;i++){
	    	for(int j=0;j<N+2;j++){
	    		if(mg[i][j]==1)
	    		   printf("%s","��") ;
	    		else  if(mg[i][j]==-2){
	    		      printf("%s","��");
	    		      mg[i][j]=0;
				}
	    		else 
	    		  printf("  ");
			}
			printf("\n");
		}
	} 

