/*
	c�ο�: https://blog.csdn.net/qq_41231926/article/details/82861877
	������˼·
	1. ����������ֵĳ˻�>number����i-1����number��ƽ����������պõ��ڣ���i����number��ƽ������ʱ�临�Ӷ�Ϊsqrt(n),�ռ临�Ӷ�ΪO(1)

	2. ʹ�ö��ַ���
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
		if (mid*mid>number){//�м�������>number����ôӦ����midСһЩ��ֻ����
			high = mid - 1;
		} else{
			low = mid + 1;
		}
	}
	return high;//��Low��high���ʱ�򣬾�������ѭ����Ҳ������������⣬����high����ȷ���ٽ�ֵ������highֵ��

}

int main(){
	int number = 10;
	cout << number<<"��ƽ������: " << sqrt_1(number) << endl;
	cout << number << "��ƽ������: " << sqrt_2(number) << endl;
	system("pause");
	return 0;
}
