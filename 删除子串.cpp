//ɾ���Ӵ��ĳ������
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//˳�򴮵Ľṹ���Ͷ���
#define maxsize 100
typedef struct
{  
	char str[maxsize];
    int len;
}seqstring;

void strPut(seqstring*);
void strDelete(seqstring*,int,int);
int main()
{
	seqstring*S;
	int i,m;
	S=(seqstring*)malloc(sizeof(seqstring));
	printf("���봮��"); gets(S->str);
	S->len=strlen(S->str);
	strPut(S);
	printf("ɾ���Ŀ�ʼλ��:");scanf("%d",&i);
	printf("ɾ�����ַ�����:");scanf("%d",&m);
	strDelete(S,i,m);
	strPut(S);
}

//�����
void strPut(seqstring*S)
{
	int i;
	for(i=0;i<S->len;i++)
		printf("%c",S->str[i]);
	printf("\n");
}

//���ɾ���Ӵ��㷨
void strDelete(seqstring*S,int a,int b)
{
	char c[maxsize];int i,j;
	for(i=0;i<maxsize;i++)
	{
		c[i]='\0';
	}
	if(a+b<S->len)
	{
		for(i=0;i<a-1;i++)
		{
			c[i]=S->str[i];
		}
		j=i;
		i=i+b;
		for(i;i<S->len;i++)
		{
			c[j]=S->str[i];
			j++;
		}
		for(j;j<S->len;j++)
		{
			S->str[j]='\0';
		}
		strcpy(S->str,c);
	}
	else if(a<S->len&&a+b>=S->len)
	{
		for(i=0;i<a-1;i++)
		{
			c[i]=S->str[i];
		}
		for(j=a-1;j<S->len;j++)
		{
			S->str[j]='\0';
		}
		strcpy(S->str,c);
	}
	else{
	}
}
