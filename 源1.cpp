#include"LinkStack.h"
using namespace std;

void show_Menu()
{
	cout << "****************************************************************************" << endl;
	cout << "*****************0.退出系统*************************************************" << endl;
	cout << "*****************1.入栈（输入0为结束）**************************************" << endl;
	cout << "*****************2.得到栈顶元素*********************************************" << endl;
	cout << "*****************3.判断栈是否为空*******************************************" << endl;
	cout << "*****************4.检测栈长度***********************************************" << endl;
	cout << "*****************5.出栈*****************************************************" << endl;
	cout << "*****************6.清空栈***************************************************" << endl;
	cout << "*****************7.销毁栈***************************************************" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

void exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//创建结点
struct Node* createNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//创建栈，就是创建一个struct stack的变量
	//初始化栈
stack* createStack()
{
	//创建过程就是初始化的过程
	struct stack* myStack = new stack;
	myStack->stackTop = NULL;
	myStack->size = 0;
	return myStack;

}

//入栈
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

//清空栈
void clearLStack(struct stack* myStack) 
{
	//防御编程
	if (myStack->size == 0)
	{
		cout << "栈为NULL！" << endl;
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

//销毁栈
void destroyLStack(struct stack* myStack)
{
	if (myStack->size == 0)
	{
		cout << "栈为NULL！" << endl;
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

//检测栈长度
void Long(struct stack* myStack) 
{
	//防御编程
	if (myStack->size == 0)
	{
		cout << "栈为NULL，无法获取栈顶的元素！" << endl;
		system("pause");
	}
	else {
		cout << myStack->size << endl;
	}
}



int main()
{
	int choice = 0;
	int i;
	cout << "正在初始化中......" << endl;
	stack* myStack = createStack();
	cout << "初始化已经完成。" << endl;
	cout << "感谢您的使用。" << endl;
	while (true)
	{
		show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			exitSystem();
			break;
		case 1://入栈
			cin >> i;
			while (i != 0) {
				push(myStack, i);
				cin >> i;
			}
			break;
		case 2://得到栈顶元素
			cout << top(myStack) << endl;
			break;
		case 3://判断栈是否为空
			if (empty(myStack)) {
				cout << "栈不为空" << endl;
			}
			else {
				cout << "栈为空" << endl;
			}
			break;
		case 4://检测栈长度
			Long(myStack);
			break;
		case 5://出栈
			while (empty(myStack))
			{
				cout << top(myStack) << "\t";
				pop(myStack);
			}
			cout << endl;
			cout << "已全部出栈完成。" << endl;
			break;
		case 6://清空栈
			while (empty(myStack))
			{
				clearLStack(myStack);
			}
			cout << "已全部清空完成。" << endl;
			break;
		case 7://销毁栈
			while (empty(myStack))
			{
				destroyLStack(myStack);
			}
			cout << "已全部销毁完成。" << endl;
			break;
		default:
			cout << "输入错误" << endl;
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}