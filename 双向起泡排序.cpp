//双向起泡排序的程序代码
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//顺序表结构类型定义
typedef int datatype;
typedef struct{
	int key;
	datatype data;
}sequenlist;

void create(sequenlist[],int);
void print(sequenlist[],int);
void dbubblesort(sequenlist[],int);

int main()
{
	const int n=10;
	sequenlist r[n+1];
	create(r,n);
	printf("排序前的数据：");
	print(r,n);
	dbubblesort(r,n);
	printf("排序后的数据：");
	print(r,n);
}

//建立顺序表
void create(sequenlist r[],int n)
{
	srand(time(0));
	for(int i=1;i<=n;i++)
		r[i].key=rand()%90;
}

//输出顺序表
void print(sequenlist r[],int n)
{
	for(int i=1;i<=n;i++)
		printf("%5d",r[i].key);
	printf("\n");
}

//添加双向起泡排序算法
void dbubblesort(sequenlist r[],int n)
{
	int i=1,j,flag=1,t;
	while(flag)
	{
		flag=0;
		for(j=n-i+1;j>i;j--)
		{
			if(r[j].key<r[j-1].key)
			{
				t=r[j].key;
				r[j].key=r[j-1].key;
				r[j-1].key=t;
				flag=1;
			}
		}
		for(t=1;t<n;t++)
		{
			printf("%d ",r[t].key);
		}
		printf("\n");
		for(j=i+1;j<n-i+1;j++)
		{
			if(r[j].key>r[j+1].key)
			{
				t=r[j].key;
				r[j].key=r[j+1].key;
				r[j+1].key=t;
				flag=1;
			}
		}
		for(t=1;t<n;t++)
		{
			printf("%d ",r[t].key);
		}
		printf("\n");
		i++;
	}
}
