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

//创建结点
	struct Node* createNode(int data)
	{
		struct Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}

	struct stack
	{
		struct Node* stackTop;//栈顶标记
		int size;			  //栈中元素个数
	};

//创建栈，就是创建一个struct stack的变量
	//初始化栈
	LinkStack::stack* createStack()
	{
		//创建过程就是初始化的过程
		struct stack* myStack = new stack;
		myStack->stackTop = NULL;
		myStack->size = 0;
		return myStack;

	}
	
	void push(struct stack* myStack, int data)
	{
		//插入的这个结点创建出来
		struct Node* newNode = createNode(data);
		//入栈操作就是链表表头插入
		newNode->next = myStack->stackTop;
		myStack->stackTop = newNode;
		myStack->size++;
	}

//获取栈顶元素
	int top(struct stack* myStack)
	{
		//防御编程
		if (myStack->size == 0) 
		{
			cout << "栈为NULL，无法获取栈顶的元素！" << endl;
			system("pause");
			return myStack->size;
		}
		return myStack->stackTop->data;
	}

//出栈
	void pop(struct stack* myStack)
	{
		//防御编程
		if (myStack->size == 0)
		{
			cout << "栈为NULL，无法获取栈顶的元素！" << endl;
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

//判断栈是否为空
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
