/*

	��д������ģ��ջ������ģ��ӵĴ����з����ˣ�����ֻ�г��Ӻͳ�ջ�Լ���ջ�����Ƕ�ͷ��ʱ�򣬴��벻ͬ����������

*/

#include<iostream>
using namespace std;

class Node{
public:
	int m_value;
	Node* next;
};

class LinkQueue{
public:

	LinkQueue();
	~LinkQueue();
	bool push(int value);
	bool is_empty();
	bool popback();
	//bool get_top(int &value);
	bool get_head(int &value);

	bool traverse();
	Node *m_list;

	int m_length;
};

LinkQueue::LinkQueue(){
	m_length = 0;
	m_list = new Node();
	m_list->m_value = 0;
	//m_list = NULL;
}
LinkQueue::~LinkQueue(){

}

bool LinkQueue::push(int value){
	Node* node = new Node();
	node->m_value = value;
	node->next = NULL;
	Node* current_node = m_list;
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = node;
	m_length++;
	return true;
}
bool LinkQueue::is_empty(){
	if (m_length == 0){
		return true;
	}
	else{
		return false;
	}
}

bool LinkQueue::traverse(){
	Node *current_node = m_list;
	while (current_node->next)
	{
		current_node = current_node->next;
		cout << current_node->m_value << endl;
	}
	return true;
}
bool LinkQueue::popback(){
	if (m_length == 0){
		cout << "ջ�Ѿ��ǿյ��ˣ�û��Ԫ�ؿ��Գ�ջ" << endl;
		return false;
	}
	Node* current_node = m_list;
	m_list->next = m_list->next->next;//ֻ��Ҫ��ԭ�������������һ��ָ��ĵ�ַ�����˵�ǰ����һ����ַ���ɡ�
	
	m_length--;
	return true;
}

bool LinkQueue::get_head(int &value){
	if (m_length == 0){
		return false;
	}
	value = m_list->next->m_value;
	
	return true;
}

/*
int main(){
int a = 0;
int b = 1;
int c = 2;
LinkQueue queue;
queue.push(a);
queue.push(b);
queue.push(c);
queue.traverse();
int value;
queue.get_head(value);
cout << "head ele is: " << value << endl;;
queue.popback();
queue.get_head(value);
cout << "���Ӻ�head ele is: " << value << endl;;
queue.traverse();
queue.popback();
queue.popback();
queue.popback();//��ʵ���Ӳ�����
if (queue.is_empty()){
cout << "���¶�Ϊ��" << endl;
}

system("pause");
return 0;

}




*/
