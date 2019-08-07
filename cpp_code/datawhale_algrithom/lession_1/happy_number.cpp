/*
	�ο�: https://leetcode-cn.com/problems/happy-number/solution/cxiang-xi-ti-jie-zhi-xing-yong-shi-ji-bai-100-by-y/

*/

#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool is_happy(int number){
	unordered_set<int> bobo;
	while (!bobo.count(number)){//���ٴ�����ͬ�ĺ�ֵ����ʱ������������Ŀѭ�����������жϸ���ֵ�Ƿ�Ϊ1��Ȼ��������
		int sum = 0;
		bobo.insert(number);//����ֵ���������set/map�У�
		while (number!=0)//���ϵؽ���λ����ֱ��ֻʣһ������ʱ��/10��Ϊ0.
		{
			sum = sum + (number % 10)*(number % 10);//��10ȡ���Ǹ�λ����ֵ��    ѭ����ƽ����
			number /= 10;//����10���ǽ�����λ�������Եõ�ʮλ����

		}
		number = sum;   
	}

	return number == 1;

	
}


bool is_happy_2(int number){
	unordered_map<int,int> bobo;
	while (!bobo.count(number)){
		int sum = 0;
		bobo.insert(pair<int,int>(number,1));
		while (number != 0)
		{
			sum = sum + (number % 10)*(number % 10);
			number /= 10;
		}
		number = sum;
	}
	return number == 1;
}

//
//int main(){
//	int number = 9;
//	if (is_happy_2(number)){
//		cout << number << "�ǿ�����" << endl;
//	}
//	else{
//		cout << number << "���ǿ�����" << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}