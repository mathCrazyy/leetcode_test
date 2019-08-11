/*
	快速排序也是用了分治法,快慢指针
	https://www.bilibili.com/video/av47837026?from=search&seid=4896342868324342020
	https://www.bilibili.com/video/av47840085
	感觉递归....就不能深入往下想...不然就蒙蔽了....
	//先写一个整体处理的，
	//再写好跳出条件，在条件里做整体处理的运算，做好递归移动的动作。
*/
#include<iostream>

using namespace std;

int partition(int arr[], int l, int r){
	/*
		l是快指针， r 是最后一个元素的下标
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
	if (l < r){//只有当对一个最短的两个元素进行排序，才能够慢慢到了全部元素排序上。
		int pivot_index = partition(arr, l, r);//递归改变pivot的index。
		cout <<"-------   "<< pivot_index << endl;
		quick_sort(arr, l, pivot_index - 1);//处理pivot_index前面的部分
		traverse(arr, l, r);
		quick_sort(arr, pivot_index + 1, r);//处理pivot_index后面的部分
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
