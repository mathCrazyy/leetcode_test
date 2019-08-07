/*

	从写以数组模拟栈和数组模拟队的代码中发现了，基本只有出队和出栈以及看栈顶还是队头的时候，代码不同，其余相似

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
		cout << "栈已经是空的了，没有元素可以出栈" << endl;
		return false;
	}
	Node* current_node = m_list;
	m_list->next = m_list->next->next;//只需要将原来的链表的下下一个指向的地址，给了当前的下一个地址即可。
	
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
cout << "出队后head ele is: " << value << endl;;
queue.traverse();
queue.popback();
queue.popback();
queue.popback();//其实出队不了了
if (queue.is_empty()){
cout << "当下队为空" << endl;
}

system("pause");
return 0;

}




*/
