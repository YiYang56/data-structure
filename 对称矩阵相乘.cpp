//�Գƾ�����˵ĳ������
#include<stdio.h>
#include<malloc.h>
//����ṹ���͵Ķ���.h
const int n=3;
const int size=n*(n+1)/2;
typedef int datatype;
typedef struct{
	datatype A[size],B[size],C[n][n];
}array;

void input(datatype[]);
void output(datatype[][n]);
void mult(array*);

int main()
{
	array*pa;
	pa=(array*)malloc(sizeof(array));
	printf("����Ϊ�����������A��������:\n");
    input(pa->A);//����Ϊ�����������A��������
	printf("����Ϊ�����������B��������:\n");
	input(pa->B);//����Ϊ�����������B��������
	mult(pa);
	output(pa->C);//�������C
}

//�Գƾ��������
void input(datatype x[])
{
	for(int i=0;i<size;i++)
		scanf("%d",&x[i]);
}

//��������
void output(datatype x[][n])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%5d",x[i][j]); 
		printf("\n");
	}
}

//��ӶԳƾ�������㷨
void mult(array*p)
{
	int i,j,k,s,p1,p2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s=0;
			for(k=0;k<n;k++)
			{
				if(i>=k)
				{
					p1=p->A[i*(i+1)/2+k];
				}
				else
				{
					p1=p->A[k*(k+1)/2+i];
				}
				if(k>=j)
				{
					p2=p->B[k*(k+1)/2+j];
				}
				else
				{
					p2=p->B[j*(j+1)/2+k];
				}
				s=s+p1*p2;
			}
			p->C[i][j]=s;
		}
	}
}
