/*
	��������Ҳ�����˷��η�,����ָ��
	https://www.bilibili.com/video/av47837026?from=search&seid=4896342868324342020
	https://www.bilibili.com/video/av47840085
	�о��ݹ�....�Ͳ�������������...��Ȼ���ɱ���....
	//��дһ�����崦��ģ�
	//��д�������������������������崦������㣬���õݹ��ƶ��Ķ�����
*/
#include<iostream>

using namespace std;

int partition(int arr[], int l, int r){
	/*
		l�ǿ�ָ�룬 r �����һ��Ԫ�ص��±�
	*/
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l ; j < r; j++){
		if (arr[j] < pivot){
			i++;
			int temp = 0;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = 0;
	temp = arr[i + 1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i + 1;
}
void traverse(int arr[], int l, int r){
	for (int i = 0; i < r; i++){
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void quick_sort(int arr[],int l,int r){
	if (l < r){//ֻ�е���һ����̵�����Ԫ�ؽ������򣬲��ܹ���������ȫ��Ԫ�������ϡ�
		int pivot_index = partition(arr, l, r);//�ݹ�ı�pivot��index��
		cout <<"-------   "<< pivot_index << endl;
		quick_sort(arr, l, pivot_index - 1);//����pivot_indexǰ��Ĳ���
		traverse(arr, l, r);
		quick_sort(arr, pivot_index + 1, r);//����pivot_index����Ĳ���
		traverse(arr, l, r);
	}
}

//int main(){
//	int arr[7] = { 3, 1, 2, 4, 7, 6, 5 };
//
//	quick_sort(arr, 0, 6);
//	for (int i = 0; i < 7; i++){
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
