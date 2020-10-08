//模式匹配的程序代码
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//顺序串的结构类型定义
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
	printf("输入串："); gets(S->str);
	S->len=strlen(S->str);
	printf("输入子串："); gets(subS->str);
	subS->len=strlen(subS->str);
	if(Index(S,subS)>0) printf("匹配成功！\n");
	else printf("匹配失败！\n");
}

//添加顺序串的朴素模式匹配算法
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














