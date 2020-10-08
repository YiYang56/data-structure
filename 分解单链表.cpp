#include<stdio.h>
#include<malloc.h>
typedef char datatype;
typedef struct node
{  datatype data;
   struct node *next;
}linklist;
void create(linklist*&);
void resolve(linklist*,linklist*,linklist*,linklist*);
void insert(linklist*,linklist*);
void print1(linklist*);
void print2(linklist*);
int main()
{  linklist *head,*letter,*digit,*other;
   create(head);
   print1(head);
   letter=(linklist*)malloc(sizeof(linklist));//����3����ѭ������
   letter->next=letter;
   digit=(linklist*)malloc(sizeof(linklist));
   digit->next=digit;
   other=(linklist*)malloc(sizeof(linklist));
   other->next=other;
   resolve(head,letter,digit,other);//���÷ֽⵥ����ĺ���
   print2(letter);//���ѭ������
   print2(digit);
   print2(other);
}

//����������
void create(linklist*&head)
{  datatype x;
   linklist *s,*r;
   head=new linklist;
   r=head;
   while((x=getchar())!='$')
   {  
	  s=(linklist*)malloc(sizeof(linklist));
      s->data=x;
	  r->next=s;
	  r=s;
   }
   r->next=NULL;
}

//��ѭ�������в���
void insert(linklist*h,linklist*p)
{  linklist *q=h;
   while(q->next!=h) q=q->next;
   q->next=p;
   p->next=h;
}

//���������
void print1(linklist*head)
{  linklist *p=head->next;
   while(p!=NULL)
   {  printf("%c",p->data);
      p=p->next;
   }
   printf("\n");
}

//���ѭ������
void print2(linklist*head)
{  linklist *p=head->next;
   while(p!=head)
   {  
	   printf("%c",p->data);
       p=p->next;
   }
   printf("\n");
}

//��Ӱ���ĸ�����֡������ַ��ֽⵥ�����㷨
void resolve(linklist*a,linklist*b,linklist*c,linklist*d)
{
	linklist *p,*q,*x,*y,*z;
	q=a->next;x=b;y=c;z=d;
	while(q!=NULL)
	{
		p=q;
		q=q->next;
		if((p->data>=65&&p->data<=90)||(p->data>=97&&p->data<=122)) 
		{
			x->next=p;
			p->next=b;
			x=p;
		}
		else if(p->data>=48&&p->data<=57)
		{
			y->next=p;
			p->next=c;
			y=p;
		}
		else
		{
			z->next=p;
			p->next=d;
			z=p;
		}
	}
}
