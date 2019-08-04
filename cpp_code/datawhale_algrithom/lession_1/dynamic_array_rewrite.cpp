/*

	模板类的实现，必须放在内部

*/
#include<iostream>

using namespace std;

//  DynamicArray<int> da;
template<typename T>
class DynamicArray
{
public:
	
	DynamicArray(int capacity = DEFAULT_CAPACITY){
		arr = new T[this->capacity = capacity];
	}
	~DynamicArray(){
		delete[]arr;
	}

	

	T &operator[](int index){//重载赋值，当给的index==容量大小时，需要进行扩展了
		while (capacity<=index)// 如果不使用<=，则在容量10的数组中，index==10的下标，造成
		{
			expend();
		}
		return arr[index]; //这里的越界。
	}
	void expend();

	T *arr;  // 数组嘛...由于是连续存储，只需要记录其存放的首地址即可。
	int capacity; //数组当前的容量，待扩充
	static const  int DEFAULT_CAPACITY = 10;// 初始的默认容量
private:


};
template<typename T> void DynamicArray<T>::expend(){
	T* oldarr = arr;
	
	//oldarr = arr;
	arr = new T[capacity << 1];
	for (int i = 0; i < capacity; ++i){
		cout << oldarr[i] << endl;
		arr[i] = oldarr[i];
	}
	capacity <<= 1;
	delete oldarr;
	
}

//
//
//int main(){
//	DynamicArray<int> da;
//	for (int i = 0; i < 10000; ++i){
//		da[i] = 0;
//		cout << i << endl;
//	}
//	return 0;
//}