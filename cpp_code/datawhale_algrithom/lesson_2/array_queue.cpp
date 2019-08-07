/*

	���о����Ƚ��ȳ�
	ʹ������ʵ��
*/
#include<iostream>

using namespace std;

class QueueTest{

public:
	QueueTest();
	~QueueTest();
	bool is_empty();
	bool is_full();
	bool push(int value);
	bool pop_back();//��Ҫ�����ڳ��ӣ������ȳ�����0��ʼ��
	bool get_head(int &value);//��ȡ��ͷ�����˴Ӷ�ͷ�ߣ�
	bool traverse();
	int m_data[100];
	int m_length;
};
QueueTest::QueueTest(){
	m_length = 0;
}
QueueTest::~QueueTest(){
	
}
bool QueueTest::is_empty(){
	if (m_length == 0){
		return true;
	}
	else{
		return false;
	}
}
bool QueueTest::is_full(){
	if (m_length == 100){
		return true;
	}
	else{
		return false;
	}

}

bool QueueTest::push(int value){
	if (is_full()){
		return false;
	}
	m_data[m_length] = value;
	m_length++;
	return true;
}

bool QueueTest::pop_back(){
	if (is_empty()){
		return false;

	}
	for (int i = 0; i < m_length-1; i++){
		m_data[i] = m_data[i + 1];
	}
	m_length--;
	return true;
}
bool QueueTest::traverse(){
	if (is_empty()){
		return false;
	}
	else{
		for (int i = 0; i < m_length; i++){
			cout << m_data[i] << endl;
		}
		return true;
	}
}

bool QueueTest::get_head(int &value){
	if (m_length == 0){
		cout << "����һ���նӣ� �����Ԫ��" << endl;
		return false;
	}
	value = m_data[0];

	return true;

}
/*
int main(){
QueueTest queue;
int head1 = -1;
queue.get_head(head1);
cout << head1 << endl;
int a = 1;
int b = 2;
int c = 3;
queue.push(a);
queue.push(b);
queue.push(c);
cout << "��ǰջ��" << endl;
queue.traverse();
queue.pop_back();
cout << "һ��Ԫ�س���" << endl;
int head2 = -1;
queue.get_head(head2);
cout << "��ǰ�Ķ�ͷ��: " << head2 << endl;
queue.traverse();
system("pause");
return 0;
}
*/
