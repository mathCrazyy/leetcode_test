/*
	参考: https://leetcode-cn.com/problems/happy-number/solution/cxiang-xi-ti-jie-zhi-xing-yong-shi-ji-bai-100-by-y/

*/

#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool is_happy(int number){
	unordered_set<int> bobo;
	while (!bobo.count(number)){//当再次有相同的和值插入时，即满足了题目循环的条件，判断该数值是否为1，然后跳出。
		int sum = 0;
		bobo.insert(number);//将和值存入无序的set/map中，
		while (number!=0)//不断地降低位数，直到只剩一个数字时，/10就为0.
		{
			sum = sum + (number % 10)*(number % 10);//对10取余是个位数的值。    循环求平方和
			number /= 10;//除以10，是降低了位数。可以得到十位数。

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
//		cout << number << "是快乐数" << endl;
//	}
//	else{
//		cout << number << "不是快乐数" << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}