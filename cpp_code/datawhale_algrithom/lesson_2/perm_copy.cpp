#include<iostream>
using namespace std;

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
		for (int i = 0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = k; i<n; i++)
		{
			if (isswap(arr, k, i))
			{
				swap(&arr[k], &arr[i]);
				permutations(arr, k + 1, n);
				swap(&arr[i], &arr[k]);
			}
		}
	}
}
//int main()
//{
//	int a[3] = { 1, 2, 3 };
//	permutations(a, 0, 3);
//	system("pause");
//	return 0;
//}