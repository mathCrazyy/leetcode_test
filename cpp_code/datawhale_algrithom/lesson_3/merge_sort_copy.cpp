
#include<iostream>

using namespace std;



void Merge(int *a, int p, int q, int r)

{

	int n1 = q - p + 1;       //�󲿷ֵĵ�Ԫ�ظ���

	int n2 = r - q;           //ͬ��

	int i, j, k;

	int *L = new int[n1 + 1];

	int *R = new int[n2 + 1];

	for (i = 0; i<n1; i++)

		L[i] = a[p + i];

	for (j = 0; j<n2; j++)

		R[j] = a[q + j + 1];

	L[n1] = 11111111;

	R[n2] = 11111111;

	// ����L��0~n1-1��ţ���n1�����int�����ܱ�ʾ�������������Ϊ���������Ϊ��

	//����ϲ�ʱ�����統����L�е�n1��Ԫ���Ѿ�ȫ����˳��������a�У�ֻʣ������R��

	//����Ԫ�أ���ʱ��ΪR��ʣ�µ�Ԫ��ȫ��С��11111111,��ִ��else��䣬ֱ�ӽ�ʣ�µ�

	//Ԫ�ؿ�����a�С�

	for (i = 0, j = 0, k = p; k <= r; k++)

	{

		if (L[i] <= R[j])

			a[k] = L[i++];

		else

			a[k] = R[j++];

	}



	delete[]L;

	delete[]R;

}



void MergeSort(int *a, int l, int r)

{

	if (l<r)

	{

		int m = (l + r) / 2;

		MergeSort(a, l, m);

		MergeSort(a, m + 1, r);

		Merge(a, l, m, r);

	}

}



//����������
//
//int main()
//
//{
//
//	int i;
//
//	//int a[11] = { 2, 5, 8, 8, 66, 33, 2, 12, 0, 56, 20 };
//	int a[8] = { 2, 3, 9, 10, 1, 4, 6, 7 };
//	int a1[8] = { 2, 3, 9, 10, 1, 4, 6, 7 };
//	Merge(a1, 0, 4, 7);
//	for (i = 0; i<8; i++)
//
//		cout << a1[i] << " ";
//
//	for (i = 0; i<8; i++)
//
//		cout << a[i] << " ";
//
//	cout << endl;
//
//	MergeSort(a, 0, 7);
//
//	for (i = 0; i<8; i++)
//
//		cout << a[i] << " ";
//
//	cout << endl;
//	system("pause");
//	return 0;
//
//}
