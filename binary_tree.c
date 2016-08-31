#include<stdio.h>
#include<stdlib.h>  //exit(0)
#include<malloc.h>  //malloc
typedef struct Node   //�ṹ��д��ǰ��
{
	int data;
	struct Node * lchild;
	struct Node * rchild;
}BiTNode, *BiTree;
int sum=0;
int con_sum;
int tag=0;
int time=0;
int a[20]={0};
int CountLine (FILE *fp);
void post_error(FILE *fp2);//���������fp2���ERROR
void post_null(FILE *fp2);
void SearchTree (BiTree T, int x, FILE* fp);
void CreateTree(BiTree T, int x, FILE* fp);
void PreTree(BiTree T, FILE * fp2);
int main()
{
	FILE *fp;
	FILE *fp2;
	BiTree T = (BiTree)malloc(sizeof(BiTNode)); //���������
	char ch;
	int  count, cnt; //con_sum:Ҫ�ҵĺ�ֵ  count:�����ж��ٸ��� 
	int x; 
	int line_num;
if ((fp=fopen("input.txt","r"))==NULL)
{
	exit(0);
}
if ((fp2=fopen("output.txt","w"))==NULL)
{
	exit(0);
}
line_num = CountLine (fp); //���������������Ѿ����ļ���ָ��ص���ͷ

ch=fgetc(fp);//��ʱ��ftell(fp)==1

//fscanf(fp, "%d", &n);//�����⣬ע�⵽Ӧ����ch��ܻ�������
//fseek(fp, 2L, 1);
while(ch!=EOF)
{
	if (ch>='0' && ch <='9')
	{
		ungetc(ch, fp);
		fscanf(fp, "%d", &con_sum);
		printf("%d\n", con_sum);/////////////////////////////////
	}
	else if (ch == '\n')
	{
		break;
	}
	else if (ch != ' ')//��������ĸ�������ַ�
	{
		post_error(fp2);
		fcloseall();
		exit(0);
	}
	ch=fgetc(fp);  //ѭ���ı�֤
}
ch=fgetc(fp);
while(ch!=EOF)
{
	if ((ch>='0' && ch <='9') || ch == '-')
	{
		ungetc(ch, fp);
		fscanf(fp, "%d", &count);
		printf("%d\n", count);///////////////////////////////////////////
			if(count<1 || count>20 || count!= line_num-2)//n������Ҫ��
		{
		post_error(fp2);
		fcloseall();
		exit(0);
		}
	}
	else if (ch == '\n')
	{
		break;
	}
	ch=fgetc(fp);  //ѭ���ı�֤
}
cnt = count;
while(cnt>0)  //��һ��Ŀ̫�����أ�
{
	
fscanf(fp, "%d", &x);
		
	if (cnt == count)
	{
		T->data = x;}
	printf("%d\n", T->data);
		SearchTree(T, x, fp);

	cnt--;

}

PreTree(T,fp2); //�������·�����
if (tag == 0)
{
	post_null(fp2);
}

fcloseall();
while(1);
return 0;
}


void post_error(FILE *fp2)
{
	fprintf(fp2, "%s", "ERROR");
}

void post_null(FILE *fp2)
{
	fprintf(fp2, "%s", "NULL");
}

void SearchTree (BiTree T, int x, FILE *fp)//����������
{
	if (T->data == x)
	{
		CreateTree(T, x, fp); return;
	}
	else if (T->lchild != NULL || T->rchild != NULL)
	{
		if (T->lchild != NULL)
		{
			SearchTree (T->lchild,x, fp);
		}
		if (T->rchild != NULL)
		{
			SearchTree (T->rchild,x, fp);
		}
	}

}

void CreateTree(BiTree T, int x, FILE *fp)
{
	int a, b;
	T->lchild = (BiTree)malloc(sizeof (BiTNode));
	T->rchild = (BiTree)malloc(sizeof (BiTNode));
	if (T->data == x)
	{
		fscanf (fp, "%d",&a);
		fscanf (fp, "%d",&b); //����ÿ�����к����������
		if (a!= -1)
		{
			T->lchild->data = a;
			T->lchild->lchild = NULL;
			T->lchild->rchild = NULL;
		}
		else T->lchild = NULL;

		if (b != -1)
		{
			T->rchild->data = b;
			T->rchild->lchild = NULL;
			T->rchild->rchild = NULL;
		}
		else T->rchild = NULL;
	}
}

void PreTree(BiTree T, FILE * fp2)
{
	int i;
	if (T!= NULL)
	{
		sum = sum + T->data;
	
		a[time]=T->data;
		time++;
		if ((T->lchild == NULL) &&( T->rchild == NULL))
		{	printf("%d ",sum);/////////////////////////////
			if (sum == con_sum)
			{
				tag = 1;//��־���Ѿ���·��
				for(i=0; i<time; i++)
				{
					fprintf(fp2, "%d ", a[i]);
					a[i]=0;  //��ʵ����Ҫ����Ϊtime�Ѿ�����
				}
				fprintf(fp2, "%c", '\n');
			}
		
			
		}
	
		if (T->lchild != NULL)
		{
			PreTree(T->lchild, fp2);
		}
		if (T->rchild != NULL)
		{
			PreTree (T->rchild, fp2);
		}
		time--;
			sum=sum - T->data; //λ�ã�����������������������������������
	}
	}

int CountLine (FILE *fp)
{
	int n=1;
	char ch;
while(!feof(fp))
{
	ch=fgetc(fp);
	if (ch == '\n' && ((ch=fgetc(fp))>='0' && ch<='9')) n++;
}
rewind(fp);
return n;
}
