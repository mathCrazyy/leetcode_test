/*

参考： 
https://www.jianshu.com/p/0f823fbd4d20
还是想用递归...再实现一下..
*/
#include<iostream>

using namespace std;


bool has_number(int arr[],int low , int high, int number){
	int m = (low+high) / 2;
	if (low==high){
		if (arr[0] == number){
			return true;
		}
		else{
			return false;
		}
	}
	if (arr[m] == number){
		return true;
	}
	else if(arr[m]>number){
		has_number(arr, low, m - 1,number);
	}
	else{
		has_number(arr, m + 1, high, number);
	}
}

bool has_nubmber_1(int arr[], int target, int len_arr){
	int low = 0, high = len_arr, mid;
	
	while (low<high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == target){
			return true;
		}
		else if (arr[mid]<target){
			low = mid+1;//自己写的是log=mid;实际上一样...可能会由于边界问题算多了
		}
		else {
			high = mid - 1;

		}
	}
	return false;
}


//
//int main(){
//	int arr[7] = { 1, 3, 5, 7, 9, 11, 15 };
//	int number = 4;
//	if (has_nubmber_1(arr, number, 7)){
//		cout << "存在这个值" << endl;
//	}
//	else{
//		cout << "不存在这个值" << endl;
//	}
//	if (has_number(arr, 0, 7, number)){
//		cout << "存在这个值" << endl;
//	}
//	else{
//		cout << "不存在这个值" << endl;
//	}
//
//	int x = 20;
//	int y = 21;
//	int x1 = x >> 1;
//	int y1 = y >> 1;
//
//	cout << x1 << endl;
//	cout << y1 << endl;
//	system("pause");
//	return 0;
//}