//https://bbs.csdn.net/topics/390511919?page=1
#include<iostream>
using namespace std;
void traverse(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int isswap(int *arr, int from, int to)
{
	for (int i = from; i<to; i++)
	{
		if (arr[i] == arr[to])
			return 0;
	}
	return 1;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void permutations(int *arr, int k, int n)
{
	if (k == n)
	{
		cout << "输出---------" << endl;
		for (int i = 0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = k; i<n; i++)
		{
			traverse(arr, n);
			if (isswap(arr, k, i))
			{
				traverse(arr, n);
				cout << "交换位置" << k << "  " << i << endl;
				swap(&arr[k], &arr[i]);
				
				traverse(arr, n);
				permutations(arr, k + 1, n);
				traverse(arr, n);
				cout << "交换位置" << k << "  " << i << endl;
				swap(&arr[i], &arr[k]);
				
				traverse(arr, n);
			}
		}
	}
}
int main()
{
	int a[4] = { 11, 22, 33 ,44};
	permutations(a, 0, 4);
	system("pause");
	return 0;
}