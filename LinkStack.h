/**
 * ����:��׿�� QG��һ�ܵ���ҵ
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
	struct Node* stackTop;    //ջ�����
	ElemType size;			  //ջ��Ԫ�ظ���
};


//��ջ
stack* createStack();//��ʼ��ջ
int empty(struct stack* myStack);//�ж�ջ�Ƿ�Ϊ��
int top(struct stack* myStack);//�õ�ջ��Ԫ��
void clearLStack(struct stack* myStack);//���ջ
void destroyLStack(struct stack* myStack);//����ջ
void Long(struct stack* myStack);//���ջ����
void push(struct stack* myStack, int data);//��ջ
void pop(struct stack* myStack);//��ջ

void exitSystem();
void show_Menu();

#endif 