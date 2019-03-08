#include<stdio.h>
#include <stdlib.h>
#define CSFPL  100     //���Ա�洢�ռ�� ��ʼ������
#define ZL  10    //���Ա�洢�ռ�ķ��� ����
typedef  int ElemType;   //Ĭ����������Ϊint
typedef  struct{
   ElemType  *elem;   //�洢�ռ�Ļ���ַ
   int  length;       //��ǰ����
   int  listlength;     //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;
//�����Ա���䴢������ 
int Sqint(SqList *L)
{
    L->elem=(ElemType *)malloc(CSFPL*sizeof(ElemType));
    if(!L->elem) return 0;
    L->length=0;//Ԫ�صĸ���
    L->listlength=CSFPL;//����ĸ�����
    return 1;
}
//�����������Ա� 
void input(SqList *L, int n)
{
     ElemType data,*newbase;
     while(L->length>=L->listlength){
     newbase = (ElemType *)realloc(L->elem, (L->listlength+ZL)*sizeof(ElemType));
		L->elem = newbase;
		L->listlength +=ZL;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		L->elem[i]=data;
	}
	L->length=n;
}
//�����Ա������
void output(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
     printf("%d ",L.elem[i]);
}
//�����Ա��У�����
int Sqcharu(SqList *L, int i, ElemType e)
{
	int j;
	ElemType *newbase;
	if(i<1 || i>L->length+1)   return 0;    //����λ�ò��Ϸ�
	if(L->length>=L->listlength)              //��ǰ�洢�ռ����������ӷ���
	{ 
		newbase = (ElemType *)realloc(L->elem, (L->listlength+ZL)*sizeof(ElemType));
		if(!newbase) return 0;              //�洢����ʧ��
		L->elem = newbase;
		L->listlength+=ZL;   
	}
	for(j=L->length-1;j>=i-1;j--)
		L->elem[j+1] = L->elem[j];  //����λ�ü�֮���Ԫ�غ���
	L->elem[i-1]=e;                 //����e
	++L->length;                    //����1
	return 1;
} 
//�����Ա��У�ɾ��1
int Sqshanchu(SqList *L, int i)//i����λ�� 

{
    int j;
    if(i<1 || i>L->length)  return 0;   //ɾ��λ�ò��Ϸ�
    for(j=i-1; j<L->length-1; j++)                
         L->elem[j]=L->elem[j+1];       //��ɾԪ��֮���Ԫ��ǰ��
    --L->length;
    return 1;
} 
//�����Ա��У�ɾ��2 
 int Sqshanchu(SqList *L, int i)//i������ 

{
	int j=0;
    for(j;j<L->length;j++)
	{
	    if(i==L->elem[j]);
		{
			L->elem[j]=L->elem[j+1]; 
			--L->length;
			j--;
		}	
	}      
} 
//�����Ա��У���������λ��
int Sqchazhao(SqList L, ElemType e)

{
         int i=1;     //i�ĳ�ֵΪ��һ��Ԫ�ص�λ��
         while(i<=L.length&&L.elem[i-1]!=e)  
		    i++;
         if(i<=L.length)  
		   return i;
         else 
		   return 0;
} 
//������˳�����Ա�LA,LB�ϲ���һ��˳�����Ա�Lc 
void hebing_Sq(SqList LA,SqList LB,SqList *LC)
{
	int i=0,j=0,k=0;
	int La_len,Lb_len;
	ElemType La_elem,Lb_elem;
	La_len=LA.length;    //���LA��Ԫ�ظ���
	Lb_len=LB.length;    //���LB��Ԫ�ظ���
	while(i<La_len&&j<Lb_len)
	{
		La_elem=LA.elem[i];   //���LA�ĵ�i��Ԫ�ص�ֵ
		Lb_elem=LB.elem[j];    //���LB�ĵ�j��Ԫ�ص�ֵ
		if(La_elem<=Lb_elem)//��LA�ĵ�i��Ԫ�ص�ֵ���뵽LC��
		{
			Sqcharu(LC,++k,La_elem);//���� 
			i++;
		}
		else //��LB�ĵ�J��Ԫ�ص�ֵ���뵽LC��
		{
			Sqcharu(LC,++k,Lb_elem);
			j++;
		}
	}
	while(i<La_len)Sqcharu(LC,++k,LA.elem[i++]);//����ʣ���
	while(j<Lb_len)Sqcharu(LC,++k,LB.elem[j++]);
} 










