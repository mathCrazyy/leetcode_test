/*
	�ο�: 
	https://www.bilibili.com/video/av9982752?from=search&seid=6949168202633448760
	���ڹ鲢�����Ƕ������������������������е��õ�һ����������ʱ����Ҫ��취���������������飬ͨ���鲢��˼�롣
	�鲢ֻ�ܹ����������Ѿ���������飻���Ҫ��δ�����������������Ҫʹ�õ����Ρ�
	
	����: 
	��д������õ���������ĺϲ���
*/

#include<iostream>
using namespace std;
//�ϲ�
void merge(int arr[], int L, int M, int R){
	/*
	��ߵ����鿪ʼ�㣬�м�ָ�㣬�ұ����������
	*/
	int left_size = M - L;
	int right_size = R - M+1;
	//int left_size = M - L+1;
	//int right_size = R - M ;
	cout << left_size << "  ===  " << right_size << endl;

	//��ʼ�������С������ֱ���ñ�����ֻ����malloc����ʼ����https://zhidao.baidu.com/question/72156708.html4720
	//Ҳ������new����̬��ʼ�����顣https://www.cnblogs.com/haoyijing/p/5815035.html
	//int *left = (int*)malloc(left_size*sizeof(int));
	//int *right = (int*)malloc(right_size*sizeof(int));

	int *left = new int [left_size+1];//left_size�Ѿ��Ǹ����ˣ�ΪʲôҪ+1
	int *right = new int [right_size+1];

	//delete[]left;
	//delete[]right;
//	int left[LEFT_SIZE];
//	int right[right_size];
	int i, j,k;
	for (i = 0; i < left_size; i++){//�����ߵ�����
		left[i] = arr[L+i];
	}
	 
	for (j = 0; j < R; j++){//����ұߵ�����
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

//����
void merge_sort(int arr[], int L, int R){
	/*
		����һ��δ���������
	*/
	if (L < R){
		int M = (L + R) / 2;
		merge_sort(arr, L, M);//����߲�����һ���鲢����
		merge_sort(arr, M + 1, R);//���ұ߲�����һ���鲢����
		merge(arr, L, M, R);//�ϲ���
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
	//	merge_sort(arr, L, M);//����߲�����һ���鲢����
	//	merge_sort(arr, M + 1, R);//���ұ߲�����һ���鲢����
	//	merge(arr, L, M, R);//�ϲ���
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