#include "stack.h"

//ջ�ĳ�ʼ��
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = 5;
	ps->_arr = (LTDataType*)malloc(sizeof(LTDataType));
	assert(ps->_arr);
	
	ps->_top = 0;
}
//ջ������
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
//���ջ�Ƿ�����
void StackCheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		//�����¿ռ�
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
	//���ջΪ��,���ջʧ��,ֱ�ӷ���
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
