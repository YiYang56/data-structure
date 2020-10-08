//顺序表逆置.cpp
#include<stdio.h>
#include<malloc.h>
typedef char datatype;
const int maxsize=1024;
typedef struct
{ datatype data[maxsize];
  int last;
}sequenlist;
sequenlist*InitList;
void create(sequenlist*&);
void print(sequenlist*);
void invert(sequenlist*);

int main()
{
	sequenlist*L;
	create(L);//建立顺序表
	print(L);//输出顺序表
	invert(L);//调用顺序表逆值的函数
	print(L);//输出顺序表
	printf("%c",L->data[0]);
}

//建立顺序表
void create(sequenlist*&L)
{
	L=(sequenlist*)malloc(sizeof(sequenlist));
	L->last=0;
	char ch;
	while((ch=getchar())!='*')
	{   
		L->last++;
		L->data[L->last]=ch;
	}
}

//输出顺序表
void print(sequenlist*L)
{
	for(int i=1;i<=L->last;i++)
		printf("%2c",L->data[i]);
	printf("\n");
}

//添加顺序表逆置算法
void invert(sequenlist*L)
{
	int i,j;char temp;
	for(i=1,j=0;i<=L->last/2;i++,j++)
	 {
	 	temp=L->data[i];
	 	L->data[i]=L->data[L->last-j];
	 	L->data[L->last-j]=temp;
	 }
}
