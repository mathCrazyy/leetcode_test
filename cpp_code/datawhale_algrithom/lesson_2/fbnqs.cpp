/*
	1. 쳲���������
	2. �׳�
	3. ȫ����....֪��˼·...�����ǲ���д����������


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
		return get_pbnqs(num-1) + get_pbnqs(num - 2);//������һ��д��....����ϸ��...���Եع�
	}
	else{
		cout << "������ڵ���1��ֵ" << endl;
	}
}

int get_factorial_number(int num){//������ַ���ֵΪ�յ�����������е�print��Ϊreturn���ɣ����Ͳ����...��py��ѧϰ���ġ�
	if (num == 1){
		return 1;
	
	}
	else if (num == 2){
		return 2;
	}
	else if (num > 2){
		return num*get_factorial_number(num-1);//��д����ʽ������n�����֣�����n-1����֮ǰ����ô��϶��ɣ�f(n)=n*f(n-1)
	}
	//�տ�ʼ�޴���дѭ��...........
	/*while (num>1)
	{
		
	}*/
	
}

vector<vector<int>> get_permutation_wrong(vector<int> group, int value, vector<vector<int>> &all_group){
	//ʹ�õݹ��˼�룬f(n)�˻���f(n-1)��ȫ���п�����ɣ�f(n-1)����Ԫ�أ������һ��Ԫ�ص�ȫ���У���ô���ǵ�������λ�ö���
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
		cout << i << "�Ľ׳ˣ� " << get_factorial_number(i) << endl;
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


