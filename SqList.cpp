#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
//静态分配
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;
//动态分配
#define InitSize 100
typedef struct{
	ElemType *data;
	int capacity;//动态数组的最大容量
	int length;
}SeqList;
bool del_s_t(SqList &L,ElemType s,ElemType t)
{
	int i,j;
	if(s>=t||L.length==0)
		return false;
	for(i=0;i<L.length && L.data[i]<s;i++)
	if(i>=L.length)
		return false;
	for(j=i;j<L.length && L.data[j]<=t;j++)
	for(;j<L.length;i++,j++)
		L.data[i]=L.data[j];
	L.length=i;
	return true;
}
//打印顺序表元素
void PrintList(SqList &L)
{
	for(int i=0;i<L.length;i++)
	{
		printf("%4d",L.data[i]);
	}
	printf("\n");
}
int main()
{
	SqList L;//顺序表的名称
	bool ret;//查看返回值
	//首先手动在顺序表中赋值
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=3;
	L.data[3]=4;
	L.data[4]=5;
	L.data[5]=6;
	L.data[6]=7;
	L.data[7]=8;
	L.data[8]=9;
	L.data[9]=10;
	L.length=10;
	ret=del_s_t(L,3,6);
	if(ret)
	{
		printf("删除成功\n");
		PrintList(L);
	}else{
		printf("删除失败\n");
	}
	
	system("pause");//停在控制台窗口
}
