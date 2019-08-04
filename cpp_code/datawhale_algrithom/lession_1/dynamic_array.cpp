/*
	参考: https://blog.csdn.net/tyxacm/article/details/88321206
	主要思路: 
	数组容量的动态扩充，选择固定倍数扩充，牺牲了空间换时间；
	选择固定值扩充，牺牲时间换空间。

*/
#include<iostream>
using namespace std;

template<typename T> struct DynamicArray{
	T *arr; //首地址
	int capacity; //当前容量
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
//扩充一倍
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

