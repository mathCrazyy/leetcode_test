/*

	链表法解决散列冲突的问题.https://blog.csdn.net/ynnusl/article/details/89343419
*/

#include<iostream>
using namespace std;
#define N_vec 20 //数组数量
#define NhashSlot 7 //哈希槽的数量,7个存储数据的一级位置，
#define N_R 200 //一共的上限？

//数据节点
class Node{
public:
	Node();
	void init_key_link(int key);//初始化第一个key落到的位置，将作为该位置的头节点。（initPnode)
	
	int m_key;
	int m_num;
	Node* next;
	Node* pre;
};
class Hash_pre{
public:
	Node* m_link[N_vec];//注意.....在参考代码中...*Pnode对link[N]进行了修饰...是二维数组了相当于
	int m_num;//哈希表中现存的数据
	int m_len;//哈希数组长度
};


void Node::init_key_link(int key){

	m_key = key;
	m_num = 1;
	next = NULL;
	pre = NULL;

}



//哈希链表
class Hash{
public:
	Hash();
	~Hash();
	Node* m_link[N_vec];//注意.....在参考代码中...*Pnode对link[N]进行了修饰...是二维数组了相当于
	int m_num;//哈希表中现存的数据
	int m_len;//哈希数组长度

	void init_hash(int len);
	
	//散列位置计算，通过取余定位置。
	int hash_pos(int key);
	//寻找节点位置
	Node* find_node_pos(int key);
	//感觉原代码的初始化哈希链表有点多余...不写了
	
	//哈希插入
	void insert(int key);

	Node* search(int key);

	int delete_node(int key);


	void traverse_hash();
	void traverse_node(Node* node);
};
Hash::Hash(){

}
void Hash::init_hash(int len){
	for (int i = 0; i < len; i++){
		m_link[i]->init_key_link(-1);//哈希表的主列上，每个位置都初始化一下。
	}
	//当前哈希表存储的数据总数为0
	m_num = 0;
	m_len = len;
	
}
Hash::~Hash(){
	for (int i = 0; i < m_len; i++){
		delete(m_link[i]);//先释放主节点
	}
	delete m_link;//再释放哈希表头
}
int Hash::hash_pos(int key){
	return key%NhashSlot;
}

Node* Hash::find_node_pos(int key){
	int pos = hash_pos(key);
	//这个时候只是找到了key这个值在主列上hash应该在的位置,需要判断在这个位置上的链接
	Node* key_link = m_link[pos];//这个key所在的link头.
	while (key_link->next != NULL && key_link->m_key != key)//不为空，且并没有找到该值..就继续走
	{
		key_link = key_link->next;
	}
	//如果没有找到呢...原代码这里好像没有考虑啊
	return key_link;
}

void Hash::insert(int key){
	Node* p = find_node_pos(key);
	if (p->next != NULL){
		p->next++;//代表找到了...那么也得插入啊..怎么不插入？？？？
	}
	else{
		Node*main_node = new Node();
		main_node->init_key_link(key);
		p->next = main_node;
		main_node->pre = p;//搞了一个双向吗...
	}
	m_num++;
}

Node* Hash::search(int key){
	Node* p = find_node_pos(key);
	if (p->next == NULL){
		return NULL;//不存在这个值
	}
	else{
		return p;
	}
}



int Hash::delete_node(int key){
	Node *p = find_node_pos(key);
	p->pre->next = p->next;//该位置的前面的下一个指向该位置的下一个，即夹过去了...就是删除了
	m_num--;
	return 0;
}
void Hash::traverse_node(Node* node){
	while (node->next!=NULL)
	{
		cout << node->m_key << endl;
		node = node->next;
	}
}
void Hash::traverse_hash(){
	for (int i = 0; i < m_len; i++){
		traverse_node(m_link[i]);
	}
}

int main(){
	Hash hash;
	hash.init_hash(N_vec);
	for (int i = 0; i < N_vec; i++){
		hash.insert(i);
	}
	hash.traverse_hash();
	system("pause");
	return 0;
}