#include<iostream>
using namespace std;

class Node{
public:
	int m_value;
	Node* next;
};

class LinkStack{
public:
	
	LinkStack();
	~LinkStack();
	bool push(int value);
	bool is_empty();
	bool popback();
	bool get_top(int &value);
	
	bool traverse();
	Node *m_list;

	int m_length;
};

LinkStack::LinkStack(){
	m_length = 0;
	m_list = new Node();
	m_list->m_value = 0;
	//m_list = NULL;
}
LinkStack::~LinkStack(){

}

bool LinkStack::push(int value){
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
bool LinkStack::is_empty(){
	if (m_length == 0){
		return true;
	}
	else{
		return false;
	}
}

bool LinkStack::traverse(){
	Node *current_node = m_list;
	while (current_node->next)
	{
		current_node=current_node->next;
		cout << current_node->m_value << endl;
	}
	return true;
}
bool LinkStack::popback(){
	if (m_length == 0){
		cout << "栈已经是空的了，没有元素可以出栈" << endl;
		return false;
	}
	Node* current_node = m_list;
	while (current_node->next->next)
	{
		current_node = current_node->next;
	}
	current_node->next = NULL;
	m_length--;
	return true;
}

bool LinkStack::get_top(int &value){
	if (m_length == 0){
		return false;
	}
	Node * current_node = m_list;
	while (current_node->next)
	{
		current_node=current_node->next;
		value = current_node->m_value;
	}
	return true;
}

/*
int main(){
int a = 0;
int b = 1;
int c = 2;
LinkStack stack;
stack.push(a);
stack.push(b);
stack.push(c);
stack.traverse();
int value;
stack.get_top(value);
cout << "top ele is: " << value<<endl;;
stack.popback();
stack.get_top(value);
cout << "出栈后top ele is: " << value << endl;;
stack.traverse();
stack.popback();
stack.popback();
stack.popback();//其实出栈不了了
if (stack.is_empty()){
cout << "当下栈为空" << endl;
}

system("pause");
return 0;
}

*/

