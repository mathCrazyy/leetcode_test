#include<iostream>

using namespace std;

void traverse(int arr[], int n){//��ʾ�ող���ģ���������ı�Ȼ�Ǳȸղ���Ĵ󣬲���ʾҲ���ԣ����϶�����ʾ�ģ�������<������<=��
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insert_x(int arr[],int n,int arr_size){
	int i = n;
	if (n == arr_size)
		return;
	int key = arr[i];

	while (key<arr[i-1])
	{
		arr[i] = arr[i-1];
		i--;
		if (i == 0){
			break;
		}
	}
	arr[i] = key;
	traverse(arr, n);
}
void insert_sort(int arr[],int n){//��ʵ����д��forѭ����ǿ��д���˵���...
	if (n <=9 &&n > 0){
		insert_sort(arr, n -1);
		
		insert_x(arr, n,9);
	}

}

int main(){
	cout << "endl" << endl;
	int arr[9] = { 9, 8, 6, 3, 1, 2, 4, 5, 7 };
	//insert_x(arr,8);
	insert_sort(arr, 9);
	traverse(arr, 9);
	
	cout << endl;
	system("pause");
	return 0;
}