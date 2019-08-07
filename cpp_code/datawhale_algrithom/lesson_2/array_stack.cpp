/*
	栈: 先进后出（队: 先进先出）

	参考: https://www.cnblogs.com/yellowgg/p/6735334.html
*/
#include<iostream>

using namespace std;

class StackTest{
public:
	StackTest();
	~StackTest();
	bool is_empty();
	bool is_full();
	bool push(int value);
	bool pop_back();
	bool get_top(int &value);
	bool traverse();
	int m_basket[100];
	int m_top;
};

StackTest::StackTest(){
	m_top = -1;//栈最开始里面是没有值的，给值-1.
}
StackTest::~StackTest(){

}
bool StackTest::is_empty(){
	if (m_top == -1){
		return true;
	}
	else{
		return false;
	}
}

bool StackTest::is_full(){
	if (m_top == 99){
		return true;
	}
	else{
		return false;
	}
}

bool StackTest::push(int value){
	if (is_full()){
		return false;
	}
	else{
		m_top++;
		m_basket[m_top] = value;
		
		return true;
	}
}

bool StackTest::pop_back(){
	if (is_empty()){
		return false;
	}
	else{
		//value = m_basket[m_top];
		m_top--;
		return true;
	}
}

bool StackTest::get_top(int &value){
	if (is_empty()){
		return false;
	}
	else{
		value = m_basket[m_top];
		return true;
	}
}

bool StackTest::traverse(){
	if (is_empty()){
		return false;
	}
	else{
		for (int i = 0; i <= m_top; i++){
			cout << m_basket[i] << endl;
		}
		return true;
	}
}
/*

int main(){
StackTest stack;
stack.push(1);
stack.push(2);
stack.push(3);
stack.traverse();
int value = -1;
stack.get_top(value);
cout << "top is : " <<value<< endl;
stack.pop_back();
cout << "出栈一个元素后" << endl;
stack.traverse();
stack.pop_back();
stack.pop_back();
if (stack.is_empty()){
cout << "空栈" << endl;
}

system("pause");
return 0;
}
*/
