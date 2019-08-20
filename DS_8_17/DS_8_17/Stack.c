#include "stack.h"

//栈的初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = 5;
	ps->_arr = (LTDataType*)malloc(sizeof(LTDataType));
	assert(ps->_arr);
	
	ps->_top = 0;
}
//栈的销毁
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_arr)
	{
		free(ps->_arr);
		ps->_arr = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
		
	}
}
//检查栈是否满了
void StackCheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		//开辟新空间
		ps->_capacity = ps->_capacity * 2;
		ps->_arr = (LTDataType*)realloc(ps->_arr,ps->_capacity * sizeof(ps->_capacity));
		
	}
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}

void StackPush(Stack* ps, LTDataType data)
{
	assert(ps);
	StackCheckCapacity(ps);
	ps->_arr[ps->_top] = data;
	ps->_top++;
	//ps->_arr[ps->_top++] = data;
}
void StackPop(Stack* ps)
{
	assert(ps);
	//如果栈为空,则出栈失败,直接返回
	if (StackEmpty(ps))
		return;
	else
		ps->_top--;
}
LTDataType StackTop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return (LTDataType)0;
	}
	return ps->_arr[ps->_top - 1];
}
