#include"LinkStack.h"
using namespace std;

void show_Menu()
{
	cout << "****************************************************************************" << endl;
	cout << "*****************0.�˳�ϵͳ*************************************************" << endl;
	cout << "*****************1.��ջ������0Ϊ������**************************************" << endl;
	cout << "*****************2.�õ�ջ��Ԫ��*********************************************" << endl;
	cout << "*****************3.�ж�ջ�Ƿ�Ϊ��*******************************************" << endl;
	cout << "*****************4.���ջ����***********************************************" << endl;
	cout << "*****************5.��ջ*****************************************************" << endl;
	cout << "*****************6.���ջ***************************************************" << endl;
	cout << "*****************7.����ջ***************************************************" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

void exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//�������
struct Node* createNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//����ջ�����Ǵ���һ��struct stack�ı���
	//��ʼ��ջ
stack* createStack()
{
	//�������̾��ǳ�ʼ���Ĺ���
	struct stack* myStack = new stack;
	myStack->stackTop = NULL;
	myStack->size = 0;
	return myStack;

}

//��ջ
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

//���ջ
void clearLStack(struct stack* myStack) 
{
	//�������
	if (myStack->size == 0)
	{
		cout << "ջΪNULL��" << endl;
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

//����ջ
void destroyLStack(struct stack* myStack)
{
	if (myStack->size == 0)
	{
		cout << "ջΪNULL��" << endl;
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

//���ջ����
void Long(struct stack* myStack) 
{
	//�������
	if (myStack->size == 0)
	{
		cout << "ջΪNULL���޷���ȡջ����Ԫ�أ�" << endl;
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
	cout << "���ڳ�ʼ����......" << endl;
	stack* myStack = createStack();
	cout << "��ʼ���Ѿ���ɡ�" << endl;
	cout << "��л����ʹ�á�" << endl;
	while (true)
	{
		show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			exitSystem();
			break;
		case 1://��ջ
			cin >> i;
			while (i != 0) {
				push(myStack, i);
				cin >> i;
			}
			break;
		case 2://�õ�ջ��Ԫ��
			cout << top(myStack) << endl;
			break;
		case 3://�ж�ջ�Ƿ�Ϊ��
			if (empty(myStack)) {
				cout << "ջ��Ϊ��" << endl;
			}
			else {
				cout << "ջΪ��" << endl;
			}
			break;
		case 4://���ջ����
			Long(myStack);
			break;
		case 5://��ջ
			while (empty(myStack))
			{
				cout << top(myStack) << "\t";
				pop(myStack);
			}
			cout << endl;
			cout << "��ȫ����ջ��ɡ�" << endl;
			break;
		case 6://���ջ
			while (empty(myStack))
			{
				clearLStack(myStack);
			}
			cout << "��ȫ�������ɡ�" << endl;
			break;
		case 7://����ջ
			while (empty(myStack))
			{
				destroyLStack(myStack);
			}
			cout << "��ȫ��������ɡ�" << endl;
			break;
		default:
			cout << "�������" << endl;
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}