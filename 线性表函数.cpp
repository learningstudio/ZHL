#include<stdio.h>
#include <stdlib.h>
#define CSFPL  100     //线性表存储空间的 初始分配量
#define ZL  10    //线性表存储空间的分配 增量
typedef  int ElemType;   //默认数据类型为int
typedef  struct{
   ElemType  *elem;   //存储空间的基地址
   int  length;       //当前长度
   int  listlength;     //当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;
//给线性表分配储存容量 
int Sqint(SqList *L)
{
    L->elem=(ElemType *)malloc(CSFPL*sizeof(ElemType));
    if(!L->elem) return 0;
    L->length=0;//元素的个数
    L->listlength=CSFPL;//分配的格子数
    return 1;
}
//把数输入线性表 
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
//把线性表数输出
void output(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
     printf("%d ",L.elem[i]);
}
//在线性表中：插入
int Sqcharu(SqList *L, int i, ElemType e)
{
	int j;
	ElemType *newbase;
	if(i<1 || i>L->length+1)   return 0;    //插入位置不合法
	if(L->length>=L->listlength)              //当前存储空间已满，增加分配
	{ 
		newbase = (ElemType *)realloc(L->elem, (L->listlength+ZL)*sizeof(ElemType));
		if(!newbase) return 0;              //存储分配失败
		L->elem = newbase;
		L->listlength+=ZL;   
	}
	for(j=L->length-1;j>=i-1;j--)
		L->elem[j+1] = L->elem[j];  //插入位置及之后的元素后移
	L->elem[i-1]=e;                 //插入e
	++L->length;                    //表长增1
	return 1;
} 
//在线性表中：删除1
int Sqshanchu(SqList *L, int i)//i表是位置 

{
    int j;
    if(i<1 || i>L->length)  return 0;   //删除位置不合法
    for(j=i-1; j<L->length-1; j++)                
         L->elem[j]=L->elem[j+1];       //被删元素之后的元素前移
    --L->length;
    return 1;
} 
//在线性表中：删除2 
 int Sqshanchu(SqList *L, int i)//i表是数 

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
//在线性表中：查找数的位置
int Sqchazhao(SqList L, ElemType e)

{
         int i=1;     //i的初值为第一个元素的位序
         while(i<=L.length&&L.elem[i-1]!=e)  
		    i++;
         if(i<=L.length)  
		   return i;
         else 
		   return 0;
} 
//把两个顺序线性表LA,LB合并成一个顺序线性表Lc 
void hebing_Sq(SqList LA,SqList LB,SqList *LC)
{
	int i=0,j=0,k=0;
	int La_len,Lb_len;
	ElemType La_elem,Lb_elem;
	La_len=LA.length;    //获得LA的元素个数
	Lb_len=LB.length;    //获得LB的元素个数
	while(i<La_len&&j<Lb_len)
	{
		La_elem=LA.elem[i];   //获得LA的第i个元素的值
		Lb_elem=LB.elem[j];    //获得LB的第j个元素的值
		if(La_elem<=Lb_elem)//把LA的第i个元素的值插入到LC中
		{
			Sqcharu(LC,++k,La_elem);//插入 
			i++;
		}
		else //把LB的第J个元素的值插入到LC中
		{
			Sqcharu(LC,++k,Lb_elem);
			j++;
		}
	}
	while(i<La_len)Sqcharu(LC,++k,LA.elem[i++]);//插入剩余段
	while(j<Lb_len)Sqcharu(LC,++k,LB.elem[j++]);
} 










