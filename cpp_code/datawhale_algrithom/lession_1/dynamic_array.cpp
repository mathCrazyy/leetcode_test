/*
	�ο�: https://blog.csdn.net/tyxacm/article/details/88321206
	��Ҫ˼·: 
	���������Ķ�̬���䣬ѡ��̶��������䣬�����˿ռ任ʱ�䣻
	ѡ��̶�ֵ���䣬����ʱ�任�ռ䡣

*/
#include<iostream>
using namespace std;

template<typename T> struct DynamicArray{
	T *arr; //�׵�ַ
	int capacity; //��ǰ����
	static const int  DEFAULT_CAPACITY = 10;

	DynamicArray(int capacity = DEFAULT_CAPACITY){
		arr = new T[this->capacity = capacity];
	}

	~DynamicArray(){
		delete []arr;
	}

	T &operator[](int index){
		while (capacity<=index)
		{
			expend();
		}
		return arr[index];
	}
	void expend();
};
//����һ��
template<typename T> void DynamicArray<T>::expend(){
	T* oldArr = arr;
	arr = new T[capacity << 1];
	for (int i = 0; i < capacity; ++i){
		arr[i] = oldArr[i];
	}
	capacity <<= 1;
	delete oldArr;
}

//int main(){
//DynamicArray<int> da;
//for (int i = 0; i < 10000; ++i){
//da[i] = 0;
//cout << i << endl;
//}
//return 0;
//}

