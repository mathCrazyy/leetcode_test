/*
	1. 斐波那契数列
	2. 阶乘
	3. 全排列....知道思路...但就是不会写！！！！！


*/
#include<iostream>
#include<vector>

using namespace std;

int get_pbnqs(int num){
	if (num == 1){
		return 1;
	}else if (num == 2){
		return 2;
	} else if (num>2){
		return get_pbnqs(num-1) + get_pbnqs(num - 2);//诶诶第一次写对....不能细想...粗略地过
	}
	else{
		cout << "输入大于等于1的值" << endl;
	}
}

int get_factorial_number(int num){//如果出现返回值为空的情况，把所有的print改为return即可，解释不清楚...从py中学习到的。
	if (num == 1){
		return 1;
	
	}
	else if (num == 2){
		return 2;
	}
	else if (num > 2){
		return num*get_factorial_number(num-1);//手写递推式（即第n个数字，是有n-1甚至之前的怎么组合而成）f(n)=n*f(n-1)
	}
	//刚开始愚蠢地写循环...........
	/*while (num>1)
	{
		
	}*/
	
}

vector<vector<int>> get_permutation_wrong(vector<int> group, int value, vector<vector<int>> &all_group){
	//使用递归的思想，f(n)退化到f(n-1)，全排列可以想成，f(n-1)个的元素，与最后一个元素的全排列，那么就是调换两个位置而已
	//if (group.size() == 1){
	//	all_group.push_back(group);
	//	return all_group;
		//return all_group.push_back(group);
	//}
	if (group.size() == 1){
		vector<int> temp;
		temp.push_back(group[0]);
		temp.push_back(value);
		all_group.push_back(group);
		all_group.push_back(temp);
		return all_group;
	}
	else{
		
		int value1 = group[group.size() - 1];
		group.pop_back();
		vector<int> temp;
		temp.push_back(value1);
		for (int i = 0; i < group.size(); i++){
			temp.push_back(group[i]);
		}
		vector<int> temp2;
		
		for (int i = 0; i < group.size(); i++){
			temp2.push_back(group[i]);
		}
		temp2.push_back(value1);
		all_group.push_back(temp);
		all_group.push_back(temp2);
		return get_permutation_wrong(group, value, all_group);
	}

}

vector<vector<int>> get_perm(vector<int> group,int special_one_index,vector<vector<int>> &all_group){
	if (special_one_index == group.size() - 1){
		return all_group;
	}
	else{
		vector<int> group_ori = group;
		int temp = group[group.size() - 1];
		group[group.size() - 1] = group[special_one_index];
		group[special_one_index] = temp;
		all_group.push_back(group);
		for (int i = special_one_index+1; i < group.size(); i++){
			int temp = group[group.size() - 1];
			group[group.size() - 1] = group[i];
			group[i] = temp;
			all_group.push_back(group);
		}
		//group[special_one_index]
		//all_group.push_back(group);
		group = group_ori;
		special_one_index++;
		get_perm(group, special_one_index, all_group);
		
		
	}

}

int main(){
	cout << get_pbnqs(1) << endl;
	cout << get_pbnqs(2) << endl;
	cout << get_pbnqs(3) << endl;
	cout << get_pbnqs(4) << endl;
	cout << get_pbnqs(5) << endl;

	for (int i = 3; i < 10; i++){
		cout << i << "的阶乘： " << get_factorial_number(i) << endl;
	}
	vector<int> group;
	group.push_back(1);
	group.push_back(2);
	group.push_back(3);
	vector<vector<int>> all_group;
	int value = -1;
	//get_permutation_wrong(group, value, all_group);
	get_perm(group, 0, all_group);
	system("pause");
	return 0;

}


