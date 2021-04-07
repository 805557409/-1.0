/**
 * 作者:李卓航 QG第一周的作业
 **/

#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;


typedef int ElemType;

struct Node {
	ElemType data;
	struct Node* next;
};

struct stack
{
	struct Node* stackTop;    //栈顶标记
	ElemType size;			  //栈中元素个数
};


//链栈
stack* createStack();//初始化栈
int empty(struct stack* myStack);//判断栈是否为空
int top(struct stack* myStack);//得到栈顶元素
void clearLStack(struct stack* myStack);//清空栈
void destroyLStack(struct stack* myStack);//销毁栈
void Long(struct stack* myStack);//检测栈长度
void push(struct stack* myStack, int data);//入栈
void pop(struct stack* myStack);//出栈

void exitSystem();
void show_Menu();

#endif 