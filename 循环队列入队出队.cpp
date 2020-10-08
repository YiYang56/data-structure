//循环队列入队出队
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//循环队列的结构类型定义
const int m=5;
typedef int datatype;
typedef struct
{   datatype sequ[m];
    int  rear, quelen;
}qu;
void setnull(qu*);
void enqueue(qu*, datatype);
datatype *dequeue(qu*);

int main()
{  qu *sq;
   datatype x, *p;
   int key;
   sq=(qu*)malloc(sizeof(qu));
   setnull(sq);
   do
   {  printf("1.Enter Queue   2.Delete Queue   -1.Quit:");
      scanf("%d",&key);
      switch(key)
      {  case 1:  printf("Enter the Data:"); scanf("%d",&x);
		          enqueue(sq,x);  break;
	     case 2:  p=dequeue(sq);
		          if(p!=NULL) printf("%d\n",*p);
		          break;
	     case -1: exit(0);
      }
   }while(1);
}

//置空队
void setnull(qu *sq)
{  sq->rear=m-1;
   sq->quelen=0;
}

//添加入队算法
void enqueue(qu*sq,int x)
{
	if(sq->quelen==m)
	{
		printf("队列上溢");
	}
	else
	{
		sq->rear=(sq->rear+1)%m;
		sq->sequ[sq->rear]=x;
		sq->quelen++;
	}
}
//添加出队算法
datatype *dequeue(qu*sq)
{
	datatype sun;
	if(sq->quelen==0)
	{
		printf("队列上溢");return NULL;
	}
	else
	{
		sq->quelen--;
        sun=sq->sequ[(sq->rear-sq->quelen+m)%m];
        return(&sun);
	}
}
