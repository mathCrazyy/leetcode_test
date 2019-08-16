/*

	�������ɢ�г�ͻ������.https://blog.csdn.net/ynnusl/article/details/89343419
*/

#include<iostream>
using namespace std;
#define N_vec 20 //��������
#define NhashSlot 7 //��ϣ�۵�����,7���洢���ݵ�һ��λ�ã�
#define N_R 200 //һ�������ޣ�

//���ݽڵ�
class Node{
public:
	Node();
	void init_key_link(int key);//��ʼ����һ��key�䵽��λ�ã�����Ϊ��λ�õ�ͷ�ڵ㡣��initPnode)
	
	int m_key;
	int m_num;
	Node* next;
	Node* pre;
};
class Hash_pre{
public:
	Node* m_link[N_vec];//ע��.....�ڲο�������...*Pnode��link[N]����������...�Ƕ�ά�������൱��
	int m_num;//��ϣ�����ִ������
	int m_len;//��ϣ���鳤��
};


void Node::init_key_link(int key){

	m_key = key;
	m_num = 1;
	next = NULL;
	pre = NULL;

}



//��ϣ����
class Hash{
public:
	Hash();
	~Hash();
	Node* m_link[N_vec];//ע��.....�ڲο�������...*Pnode��link[N]����������...�Ƕ�ά�������൱��
	int m_num;//��ϣ�����ִ������
	int m_len;//��ϣ���鳤��

	void init_hash(int len);
	
	//ɢ��λ�ü��㣬ͨ��ȡ�ඨλ�á�
	int hash_pos(int key);
	//Ѱ�ҽڵ�λ��
	Node* find_node_pos(int key);
	//�о�ԭ����ĳ�ʼ����ϣ�����е����...��д��
	
	//��ϣ����
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
		m_link[i]->init_key_link(-1);//��ϣ��������ϣ�ÿ��λ�ö���ʼ��һ�¡�
	}
	//��ǰ��ϣ��洢����������Ϊ0
	m_num = 0;
	m_len = len;
	
}
Hash::~Hash(){
	for (int i = 0; i < m_len; i++){
		delete(m_link[i]);//���ͷ����ڵ�
	}
	delete m_link;//���ͷŹ�ϣ��ͷ
}
int Hash::hash_pos(int key){
	return key%NhashSlot;
}

Node* Hash::find_node_pos(int key){
	int pos = hash_pos(key);
	//���ʱ��ֻ���ҵ���key���ֵ��������hashӦ���ڵ�λ��,��Ҫ�ж������λ���ϵ�����
	Node* key_link = m_link[pos];//���key���ڵ�linkͷ.
	while (key_link->next != NULL && key_link->m_key != key)//��Ϊ�գ��Ҳ�û���ҵ���ֵ..�ͼ�����
	{
		key_link = key_link->next;
	}
	//���û���ҵ���...ԭ�����������û�п��ǰ�
	return key_link;
}

void Hash::insert(int key){
	Node* p = find_node_pos(key);
	if (p->next != NULL){
		p->next++;//�����ҵ���...��ôҲ�ò��밡..��ô�����룿������
	}
	else{
		Node*main_node = new Node();
		main_node->init_key_link(key);
		p->next = main_node;
		main_node->pre = p;//����һ��˫����...
	}
	m_num++;
}

Node* Hash::search(int key){
	Node* p = find_node_pos(key);
	if (p->next == NULL){
		return NULL;//���������ֵ
	}
	else{
		return p;
	}
}



int Hash::delete_node(int key){
	Node *p = find_node_pos(key);
	p->pre->next = p->next;//��λ�õ�ǰ�����һ��ָ���λ�õ���һ�������й�ȥ��...����ɾ����
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