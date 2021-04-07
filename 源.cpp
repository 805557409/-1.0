#include <iostream>
#include <stdlib.h>
using namespace std;

class LinkStack
{
public:
	struct Node {
		int data;
		struct Node* next;
	};

//�������
	struct Node* createNode(int data)
	{
		struct Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}

	struct stack
	{
		struct Node* stackTop;//ջ�����
		int size;			  //ջ��Ԫ�ظ���
	};

//����ջ�����Ǵ���һ��struct stack�ı���
	//��ʼ��ջ
	LinkStack::stack* createStack()
	{
		//�������̾��ǳ�ʼ���Ĺ���
		struct stack* myStack = new stack;
		myStack->stackTop = NULL;
		myStack->size = 0;
		return myStack;

	}
	
	void push(struct stack* myStack, int data)
	{
		//����������㴴������
		struct Node* newNode = createNode(data);
		//��ջ�������������ͷ����
		newNode->next = myStack->stackTop;
		myStack->stackTop = newNode;
		myStack->size++;
	}

//��ȡջ��Ԫ��
	int top(struct stack* myStack)
	{
		//�������
		if (myStack->size == 0) 
		{
			cout << "ջΪNULL���޷���ȡջ����Ԫ�أ�" << endl;
			system("pause");
			return myStack->size;
		}
		return myStack->stackTop->data;
	}

//��ջ
	void pop(struct stack* myStack)
	{
		//�������
		if (myStack->size == 0)
		{
			cout << "ջΪNULL���޷���ȡջ����Ԫ�أ�" << endl;
			system("pause");
		}
		else
		{
			struct Node* nextNode = myStack->stackTop->next;
			delete (myStack->stackTop);
			myStack->stackTop = nextNode;
			myStack->size--;
		}
	}

//�ж�ջ�Ƿ�Ϊ��
	int empty(struct stack* myStack)
	{
		if (myStack->size == 0)
		{
			return 0;
		}
		else {
			return 1;
		}
	}
};




int main()
{
	int i;
	LinkStack s1;
	LinkStack::stack* myStack = s1.LinkStack::createStack();
	cin >> i;
	while (i!=0 ) {
		s1.LinkStack::push(myStack, i);
	    cin >> i;
	}

	while (s1.LinkStack::empty(myStack))
	{
		cout << s1.LinkStack::top(myStack) << "\t" ;
		s1.LinkStack::pop(myStack);
	}
	cout << endl;
	

	system("pause");
	return 0;
}
