/*
	c参考: https://blog.csdn.net/qq_41231926/article/details/82861877
	有两种思路
	1. 如果两个数字的乘积>number，则i-1就是number的平方跟，如果刚好等于，则i就是number的平方根，时间复杂度为sqrt(n),空间复杂度为O(1)

	2. 使用二分法，
*/


#include<iostream>
using namespace std;

int sqrt_1(int number){
	for (int i = 0; i < number; i++){
		if (i*i == number){
			return i;
		}
		else if (i*i>number)
		{
			return i - 1;
		}
	}
}

int sqrt_2(int number){
	int low = 0, high = number, mid;
	while (low<=high)
	{
		mid = low + (high-low) / 2;
		if (mid*mid == number){
			return mid;
		}
		if (mid*mid>number){//中间的数相乘>number，那么应该让mid小一些，只能让
			high = mid - 1;
		} else{
			low = mid + 1;
		}
	}
	return high;//当Low比high大的时候，就跳出了循环，也是那里出了问题，所以high是正确的临界值，返回high值。

}

int main(){
	int number = 10;
	cout << number<<"的平方根是: " << sqrt_1(number) << endl;
	cout << number << "的平方根是: " << sqrt_2(number) << endl;
	system("pause");
	return 0;
}
