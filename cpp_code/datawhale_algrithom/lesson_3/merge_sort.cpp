/*
	参考: 
	https://www.bilibili.com/video/av9982752?from=search&seid=6949168202633448760
	由于归并排序是对两个有序的数组进行排序，所有当拿到一个无序数组时，先要想办法生成两个有序数组，通过归并的思想。
	归并只能够处理两个已经排序的数组；如果要对未排序的数组做处理，需要使用到分治。
	
	技巧: 
	先写已排序好的两个数组的合并。
*/

#include<iostream>
using namespace std;
//合并
void merge(int arr[], int L, int M, int R){
	/*
	左边的数组开始点，中间分割点，右边数组结束点
	*/
	int left_size = M - L;
	int right_size = R - M+1;
	//int left_size = M - L+1;
	//int right_size = R - M ;
	cout << left_size << "  ===  " << right_size << endl;

	//初始化数组大小，不能直接用变量，只好用malloc来初始化。https://zhidao.baidu.com/question/72156708.html4720
	//也可以用new来动态初始化数组。https://www.cnblogs.com/haoyijing/p/5815035.html
	//int *left = (int*)malloc(left_size*sizeof(int));
	//int *right = (int*)malloc(right_size*sizeof(int));

	int *left = new int [left_size+1];//left_size已经是个数了，为什么要+1
	int *right = new int [right_size+1];

	//delete[]left;
	//delete[]right;
//	int left[LEFT_SIZE];
//	int right[right_size];
	int i, j,k;
	for (i = 0; i < left_size; i++){//填充左边的数组
		left[i] = arr[L+i];
	}
	 
	for (j = 0; j < R; j++){//填充右边的数组
		right[j] = arr[M+j];
	}
	for (i = 0; i < left_size; i++){
		cout << left[i] <<" ";
	}
	cout << endl;
	for (i = 0; i < right_size; i++){
		cout << right[i] << " ";
	}
	cout << endl;

	i = 0;
	j = 0;
	 k = 0;
	while (i<left_size && j<right_size)
	{
		if (left[i] < right[j]){
			arr[k] = left[i];
			i++;
			k++;
		}
		else{
			arr[k] = right[j];
			j++;
			k++;
		}
	}
	while (i<left_size)
	{
		arr[k] = left[i];
		cout << arr[k] << endl;
		i++;
		k++;
	}
	while (j<right_size)
	{
		arr[k] = right[j];
		cout << arr[k] << endl;
		i++;
		j++;
	}
	for (int i = 0; i <= R; i++){
		cout << arr[i] << " ";
	}
	cout << endl;


	
	//delete[]right//
	delete[]left;
}

//分治
void merge_sort(int arr[], int L, int R){
	/*
		对于一个未排序的数组
	*/
	if (L < R){
		int M = (L + R) / 2;
		merge_sort(arr, L, M);//对左边部分做一个归并排序
		merge_sort(arr, M + 1, R);//对右边部分做一个归并排序
		merge(arr, L, M, R);//合并。
		cout << "==================" << endl;
		for (int i = 0; i < R; i++){
			cout << arr[i] << " ";
		}
		cout << "==================" << endl;
	}
	//if (L == R){
	//	return;
	//}
	//else{
	//	int M = (L + R) / 2;
	//	merge_sort(arr, L, M);//对左边部分做一个归并排序
	//	merge_sort(arr, M + 1, R);//对右边部分做一个归并排序
	//	merge(arr, L, M, R);//合并。
	//	cout << "==================" << endl;
	//	for (int i = 0; i < R; i++){
	//		cout << arr[i] << " ";
	//	}
	//	cout << "==================" << endl;
	//}
	
}
//
//
//int main(){
//	int arr[] = { 2, 3, 9, 10, 1, 4, 6, 7 };
//	int L = 0;
//	int R = 7;
//	int M = (R-L+1) / 2;
//	merge(arr, L, M, R);
//	for (int i= 0; i <= R; i++){
//		cout << arr[i] << endl;
//	}
//	cout << "----" << endl;
//	int arr1[] = { 2, 18, 9, 10, 4, 1, 6, 7 };
//	int L1 = 0;
//	int R1 = 7;
//	merge_sort(arr1, L1, R1);//???????????
//	
//
//	for (int i = 0; i <= R1; i++){
//		cout << arr1[i] <<" ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}