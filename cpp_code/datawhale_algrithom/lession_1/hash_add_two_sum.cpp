/*
	示例：
	给定 nums = [2, 7, 11, 15], target = 9
	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]

	作者：shuaidi
	链接：https://leetcode-cn.com/problems/two-sum/solution/yi-bu-bu-dai-ni-cong-bao-li-dao-zui-you-jie-de-guo/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
		iter = map_number.find(target - numbers[i]);//找当前值的补
		//在map中找不到与 target-当前值 相等的值，则将当前值存放进去为key,其index为value。
		if (iter == map_number.end()){
			map_number[numbers[i]] = i;//存放未来被找到的"当前值"的补。
		}
		else{
			need.push_back(i);//当找到时，则当前值为其中一个加数，
			need.push_back(map_number[numbers[i]]);//那个补的下标。
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

	hash_map 和mpa 并不一样。前者是哈希表，后者是红黑树，内部存储不同。前者消耗更多的内存，时间复杂度为常数,后者为O(logn).
	hash_map中使用了分桶的原理。
	https://blog.csdn.net/ddkxddkx/article/details/6555754

*/