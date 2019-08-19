#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define N 10
typedef int LTDataType;
/*
//定长的静态栈结构
typedef struct Stack
{
	LTDataType _arr[N];
	int _top;
}Stack;
*/

//支持动态增长的栈结构
typedef struct Stack
{
	LTDataType* _arr;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);					//栈初始化
void StackDestory(Stack* ps);				//销毁栈

void StackPush(Stack* ps, LTDataType data);	//入栈
void Stackpop(Stack* ps, LTDataType data);	//出栈

LTDataType StackTop(Stack* ps);				//获取栈顶元素
int StackSize(Stack* ps);					//栈的大小
int StackEmpty(Stack* ps);					//判断栈是否为空

void StackTest();

