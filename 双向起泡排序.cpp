//˫����������ĳ������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//˳���ṹ���Ͷ���
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
	printf("����ǰ�����ݣ�");
	print(r,n);
	dbubblesort(r,n);
	printf("���������ݣ�");
	print(r,n);
}

//����˳���
void create(sequenlist r[],int n)
{
	srand(time(0));
	for(int i=1;i<=n;i++)
		r[i].key=rand()%90;
}

//���˳���
void print(sequenlist r[],int n)
{
	for(int i=1;i<=n;i++)
		printf("%5d",r[i].key);
	printf("\n");
}

//���˫�����������㷨
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
