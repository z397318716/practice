#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define N 10
typedef int LTDataType;
/*
//�����ľ�̬ջ�ṹ
typedef struct Stack
{
	LTDataType _arr[N];
	int _top;
}Stack;
*/

//֧�ֶ�̬������ջ�ṹ
typedef struct Stack
{
	LTDataType* _arr;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);					//ջ��ʼ��
void StackDestory(Stack* ps);				//����ջ

void StackPush(Stack* ps, LTDataType data);	//��ջ
void Stackpop(Stack* ps, LTDataType data);	//��ջ

LTDataType StackTop(Stack* ps);				//��ȡջ��Ԫ��
int StackSize(Stack* ps);					//ջ�Ĵ�С
int StackEmpty(Stack* ps);					//�ж�ջ�Ƿ�Ϊ��

void StackTest();

