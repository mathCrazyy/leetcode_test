/*

	ģ�����ʵ�֣���������ڲ�

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

	

	T &operator[](int index){//���ظ�ֵ��������index==������Сʱ����Ҫ������չ��
		while (capacity<=index)// �����ʹ��<=����������10�������У�index==10���±꣬���
		{
			expend();
		}
		return arr[index]; //�����Խ�硣
	}
	void expend();

	T *arr;  // ������...�����������洢��ֻ��Ҫ��¼���ŵ��׵�ַ���ɡ�
	int capacity; //���鵱ǰ��������������
	static const  int DEFAULT_CAPACITY = 10;// ��ʼ��Ĭ������
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