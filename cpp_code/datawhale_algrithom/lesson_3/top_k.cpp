/*
	����forѭ����ʱ�临�Ӷ�Ӧ��Ҳ��O(n)��...
*/
#include<algorithm>
#include<map>
#include<iostream>


using namespace std;
//
//int main(){
//
//	int arr[6] = { 2, 1, 3, 5 ,11,9};
//	int top = 2;
//	map<int, int> mm;
//	for (int i = 0; i < 6; i++){
//		mm.insert(pair<int, int>(arr[i], 1));
//	}
//	//����mapĬ�ϴ�С��󣬵�k�󣬼���n-kС��
//	
//	int circle_time = 0;
//	int top_value = 0;
//	for (map<int, int>::iterator it = mm.begin(); it != mm.end(); it++){
//		
//		if (circle_time == 6 - top){
//			top_value = it->first;
//			break;
//		}
//		circle_time++;
//		
//	}
//	cout <<"value: "<< top_value << endl;
//
//
//	system("pause");
//	return 0;
//}