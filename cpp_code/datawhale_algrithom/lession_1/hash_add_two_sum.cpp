/*
	ʾ����
	���� nums = [2, 7, 11, 15], target = 9
	��Ϊ nums[0] + nums[1] = 2 + 7 = 9
	���Է��� [0, 1]

	���ߣ�shuaidi
	���ӣ�https://leetcode-cn.com/problems/two-sum/solution/yi-bu-bu-dai-ni-cong-bao-li-dao-zui-you-jie-de-guo/
	��Դ�����ۣ�LeetCode��
	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

#include<vector> 
#include<iostream>
#include<map>
#include<hash_map>

using namespace std;


vector<int> two_sum(vector<int>  numbers, int target){
	vector<int> need;
	map<int, int> map_number;
	for (int i = 0; i < numbers.size(); i++){
		map<int, int>::iterator iter;
		iter = map_number.find(target - numbers[i]);//�ҵ�ǰֵ�Ĳ�
		//��map���Ҳ����� target-��ǰֵ ��ȵ�ֵ���򽫵�ǰֵ��Ž�ȥΪkey,��indexΪvalue��
		if (iter == map_number.end()){
			map_number[numbers[i]] = i;//���δ�����ҵ���"��ǰֵ"�Ĳ���
		}
		else{
			need.push_back(i);//���ҵ�ʱ����ǰֵΪ����һ��������
			need.push_back(map_number[numbers[i]]);//�Ǹ������±ꡣ
		}
	}

	return need;
}

vector<int> two_sum2(vector<int>  numbers, int target){
	vector<int> need;
	hash_map<int, int> map_number;
	for (int i = 0; i < numbers.size(); i++){
		hash_map<int, int>::iterator iter;
		iter = map_number.find(target - numbers[i]);
		if (iter == map_number.end()){
			map_number[numbers[i]] = i;
		}
		else{
			need.push_back(i);
			need.push_back(map_number[numbers[i]]);
		}
	}

	return need;
}

//
//int main()
//{
//	vector<int> numbers = { 2, 7, 11, 15 };
//	int target = 13;
//	vector<int> need=two_sum2(numbers,target);
//	for (int i = 0; i < need.size(); i++){
//		cout << need[i] << endl;
//	}
//	system("pause");
//	return 0;
//}

/*

	hash_map ��mpa ����һ����ǰ���ǹ�ϣ�������Ǻ�������ڲ��洢��ͬ��ǰ�����ĸ�����ڴ棬ʱ�临�Ӷ�Ϊ����,����ΪO(logn).
	hash_map��ʹ���˷�Ͱ��ԭ��
	https://blog.csdn.net/ddkxddkx/article/details/6555754

*/