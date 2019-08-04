/*
	合并两个有序的序列

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> merge_sorted(vector<int> L1, vector<int> L2){
	int len = max(L1.size(), L2.size());
	vector<int> L3;
	int larger = -10000000;
	while (L1.size() > 0 && L2.size() > 0){
		int l1 = L1.front();
		int l2 = L2.front();
		if (l1 > l2){
			L3.push_back(l2);
			vector<int>::iterator k = L2.begin();
			L2.erase(k);
		}
		else{
			L3.push_back(l1);
			vector<int>::iterator k = L1.begin();
			L1.erase(k);
		}
	}
	if (L1.size() == 0){
		for (int i = 0; i < L2.size(); i++){
			L3.push_back(L2[i]);
		}
	}
	else{
		for (int i = 0; i < L1.size(); i++){
			L3.push_back(L1[i]);
		}
	}
	return L3;

}


//
//int main(){
//	vector<int> LL1 = { 1, 2, 3 };
//	vector<int> LL2 = { 2, 3, 4 };
//	vector<int>LL3=merge_sorted(LL1, LL2);
//	for (int i = 0; i < LL3.size(); i++){
//		cout << LL3[i] << endl;
//	}
//	system("pause");
//	return 0; 
//}

/*
看到了这个： 
https://blog.csdn.net/aaa958099161/article/details/89971539
有三种方法，想到了第二种方法。第三种....不太喜欢
*/