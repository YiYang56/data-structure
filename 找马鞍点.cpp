//找马鞍点程序代码
#include<stdio.h>
#include<malloc.h>
//数组的结构类型定义
const int m=3;
const int n=3;
typedef struct{
	int A[m+1][n+1];
	int max[m+1],min[n+1];
}array;
void minmax(array*);

int main()
{
	array*pa=(array*)malloc(sizeof(array));
    int i, j;
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&pa->A[i][j]);
    minmax(pa);
}

//添加找马鞍点算法
void minmax(array*p)
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		p->min[i]=p->A[i][1];
		for(j=2;j<=n;j++)
		{
			if(p->A[i][j]<p->min[i])
			{
				p->min[i]=p->A[i][j];
			} 
		}
	}
	for(j=1;j<=n;j++)
	{
		p->max[j]=p->A[1][j];
		for(i=2;i<=n;i++)
		{
			if(p->A[i][j]>p->max[j])
			{
				p->max[j]=p->A[i][j];
			} 
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(p->min[i]==p->max[j])
			{
				printf("%d %d %d\n",i,j,p->A[i][j]);
			}
		}
	}
} 
