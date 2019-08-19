#include "stack.h"

//栈的初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_arr = (LTDataType*)malloc(sizeof(LTDataType));
	assert(ps->_arr);
	ps->_capacity = 3;
	ps->_top = 0;
}
//栈的销毁
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_arr)
	{
		ps->_capacity = 0;
		ps->_top = 0;
		free(ps->_arr);
	}
}
//检查栈是否满了
void StackCheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		//开辟新空间
		int NewCapacity = ps->_capacity * 2;
		LTDataType* tmp = (LTDataType*)malloc(sizeof(NewCapacity));
		//assert(tmp);
		if (tmp == NULL)
		{
			assert(0);
			return;
		}
		for (int i = 0; i < ps->_top; i++)
		{
			tmp[i] = ps->_arr[i];
		}
		free(ps->_arr);
		ps->_arr = tmp;
		ps->_capacity = NewCapacity;
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
	if (ps->_top == 0)
		return 1;
	else
		return 0;
	//return ps->_top == 0;
}

void StackPush(Stack* ps,LTDataType data)
{
	assert(ps);
	StackCheckCapacity(ps);
	ps->_arr[ps->_top + 1] = data;
	ps->_top++;
	//ps->_arr[ps->_top++] = data;
}
void StackPop(Stack* ps)
{
	assert(ps);
	//如果栈为空,则出栈失败,直接返回
	if (StackEmpty)
		return;
	else
		ps->_top--;
}
LTDataType StackTop(Stack* ps)
{
	return ps->_arr[ps->_top-1];
}
