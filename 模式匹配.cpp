//ģʽƥ��ĳ������
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

int Index(seqstring*,seqstring*);

int main()
{
	seqstring*S,*subS;
	S=(seqstring*)malloc(sizeof(seqstring));
	subS=(seqstring*)malloc(sizeof(seqstring));
	printf("���봮��"); gets(S->str);
	S->len=strlen(S->str);
	printf("�����Ӵ���"); gets(subS->str);
	subS->len=strlen(subS->str);
	if(Index(S,subS)>0) printf("ƥ��ɹ���\n");
	else printf("ƥ��ʧ�ܣ�\n");
}

//���˳�򴮵�����ģʽƥ���㷨
int Index(seqstring*S,seqstring*subS)
{
	int i,j,t,k=0;
	for(i=0;S->str[i]!='\0';i++)
	{
		t=i;
		for(j=0;j<subS->len;j++)
		{
			if(S->str[t]==subS->str[j])
			{
				t++;
			}
			else
			{
				break;
			}
		}
		if(j==subS->len)
		{
			k=1;break;
		}
	}
	return k;
}














