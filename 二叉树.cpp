#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define maxsize 20
typedef struct tree{
	char data;
	struct tree *lchild;
	struct tree *rchild;
}Ttree,*Ttr;
Ttr CreatTre();
Ttr CreatTree(char *str);
void Preorder(Ttr T);
void Inorder(Ttr T); 
void Postorder(Ttr T);

Ttr CreatTre(){   //先序创建树 
    char ch;
    ch=getchar();
    Ttr T;
    if(ch=='#')
      T=NULL;
    else{
        T=(Ttree*)malloc(sizeof(Ttree));
    	T->data=ch;
    	T->lchild=(CreatTre());
    	T->rchild=(CreatTre());
	}
      return T;
}

Ttr CreatTree(char *str){
	Ttr St[maxsize],p,b=NULL;
	int top=-1,k,j=0;
	char ch=str[j];
	while(ch!='\0'){
		switch(ch){
			case '(' : top++; St[top]=p; k=1; break;
			case ',' : k=2; break;
			case ')' : top--; break;
			default:
				p=(Ttr)malloc(sizeof(Ttr));
				p->data=ch;p->lchild=p->rchild=NULL;
				if(b==NULL)
				   b=p;
				else{
					if(k==1)
					  St[top]->lchild=p;
					if(k==2)
					  St[top]->rchild=p;
				}
		}
		j++;
		ch=str[j];
	}
	return b;
}

void Preorder(Ttr T){      //先序遍历二叉树                 
  if(T)
  {
   printf("%c",T->data);
   Preorder(T->lchild);
   Preorder(T->rchild);
  }
}


void Inorder(Ttr T){      //中序遍历二叉树                 
  if(T)
  {
   Preorder(T->lchild);
   printf("%c",T->data);
   Preorder(T->rchild);
  }
}

void Inorder1(Ttr T){
   Ttr str[maxsize],p;
   p=T;
   int top=-1;
   while(p||top!=-1){
   	  if(p!=NULL){
   	  	  top++;
   	  	  str[top]=p;
   	  	  p=p->lchild;
		 }
		 else{
		 	p=str[top];
		 	printf("%c,",p->data);
		 	top--;
		 	p=p->rchild;
		 }
    }
   
}
void Postorder(Ttr T){      //后序遍历二叉树                 
  if(T)
  {
   Preorder(T->lchild);
   Preorder(T->rchild);
   printf("%c",T->data);
  }
}

main(){
    Ttr T;
	char str[maxsize]="a(b(d(,g)),c(e,f))";
//	printf("输入你要创建的树:"); 
//	gets(str);
	T=CreatTree(str);
	printf("\n先序排列:\n");
	Preorder(T);
	printf("\n中序排列：\n");
	Inorder1(T);
	printf("\n后序排列：\n");
	Postorder(T); 
}
