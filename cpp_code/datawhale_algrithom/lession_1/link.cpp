/*
	�������һ���ڵ�����������ɣ�һ���ִ洢��ǰ�ڵ�����ݣ�һ���ִ洢��һ���ڵ�ĵ�ַ��Ϣ��
	1. ���ȳ�ʼ����
	2. ����
	3. ɾ��
	4. ��ѯĳ��λ�õĽڵ�
	ע��: ��Ҫ��Node�ڵ����������ֿ�ʵ�֣�����һ�����д��
	�G...����ˮƽ���ƣ���ҵ���ܰٷְ���ɣ�Ŀǰдѭ�������˫�������ķѴ����ľ��������ֺã��ܿ�����������������ʱ����
	
	��ת����ο��� https://www.jianshu.com/p/84117123f709
	����ָ�룬�Ӷ��õ�������м�λ�á�ֻ��Ҫһ�α�����https://blog.csdn.net/ttyue_123/article/details/52166442
*/
#include<iostream>
using namespace std;
class Node{
public:
	Node *next;
	int data;
private:

};

class NodeSingle
{
public:
	NodeSingle();
	~NodeSingle();
	int insert_node_from_head_wrong(Node wait_insert_node);
	int insert_node_from_head(Node *wait_insert_node);
	int node_delete_wrong(int k, Node*deleted_node);
	int node_delete(int k, Node*deleted_node);
	
	int node_search(int k, Node*searched_node);
	
	int display_node();
	int display_node_wrong();

	int node_reverse_wrong2();
	int node_reverse_wrong();
	int node_reverse();

	int find_medium_node(Node *node);

	int m_i_length;
private:
	//NodeSingle *m_list;//���ﲻ����........������ͷ��Ӧ����������ɲ��֡�Node
	Node *m_list;
	
};

NodeSingle::NodeSingle()
{
	m_list = new Node();//������ͷ�ڵ�,ͷ�ڵ��data�����ֵ��
	m_i_length = 0;//ͬʱ������Ϊ0.
}

NodeSingle::~NodeSingle()
{

}

int NodeSingle::insert_node_from_head_wrong(Node wait_insert_node){
	m_list->next = &wait_insert_node;//������Node ջ�Զ����䣬����ᱻ�Զ��ͷ�
	m_list->next->data = wait_insert_node.data;
	
	m_i_length++;
	return 1;
}

int NodeSingle::insert_node_from_head(Node *wait_insert_node){
	
	wait_insert_node->next = m_list->next;//�Ȱ�ԭ����m_list����һ���ڵ㸳ֵ��������Ľڵ����һ��λ�á�
	
	m_list->next = wait_insert_node;//��������Ľڵ���뵽ͷ��ַ������
	
	m_list->next->data = wait_insert_node->data;//ͷ��ַ�������ֵ��ֵ

	m_i_length++;//ͬʱ����+1
	return 1;
}

int NodeSingle::display_node_wrong(){//�޸��˵�ַ...���º��治������
	
	for (int i = 0; i < m_i_length; i++){
		
		m_list = m_list->next;
		cout << m_list->data << endl;
	}
	return 0;
}
int NodeSingle::display_node(){
	Node *current_node = m_list;
	for (int i = 0; i < m_i_length; i++){

		current_node = current_node->next;
		cout << current_node->data << endl;
	}
	return 0;
}

int NodeSingle::node_delete_wrong(int k, Node*deleted_node){
	if (k >= m_i_length||k<0){
		return 0;
	}
	Node* current_node = m_list;
	Node* current_node_flag = current_node;
	//ͷ�ڵ��ǵ�0���ڵ㣬���Ϊ0��kɾ����1���ڵ㣬����ɾ��ͷ�ڵ㡣
	for (int i = 0; i < k; i++){//ͷ�ڵ㲻���ֵ���ӵ�1����ʼ
			
		current_node = current_node->next;//�����ǵ�k-1���ڵ㣬��һ������Ҫɾ����
	}
	deleted_node->data = current_node->data;
	if (current_node->next != NULL){
		current_node = current_node->next->next;
	}
	else{
		current_node->next = NULL;
	}
	
	//current_node = current_node_flag;
	m_list = current_node_flag;
	m_i_length--;
	//m_list = list_flag;
	return 1;
}

int NodeSingle::node_delete(int k, Node*deleted_node){
	if (k < 0 || k > m_i_length){
		return 0;
	}
	Node *beforenode = new Node();
	Node *current_node = m_list;
	for (int i = 0; i < k; i++){
		
		beforenode = current_node;
		current_node = current_node->next;
	}
	beforenode->next = current_node->next;//current��nodeҪ��beforenode����һ�㡣
	deleted_node->data = current_node->data;
	current_node = NULL;
	delete current_node;
	m_i_length--;
	return 1;
}

int NodeSingle::node_search(int k, Node*searched_node){
	if (k < 0 || k > m_i_length){
		
		return 0;
	}
	
	Node *current_node = m_list;
	for (int i = 0; i < k; i++){
		current_node = current_node->next;
	}
	searched_node->data = current_node->data;//current��nodeҪ��beforenode����һ�㡣
	
	current_node = NULL;

	return 1;
}

int NodeSingle::node_reverse_wrong(){
	Node *current_node = m_list;
	Node *temp_node = NULL;
	Node*before_node = NULL;
	for (int i = 0; i < m_i_length; i++){
		if (before_node == NULL){
			temp_node = current_node->next;//��ǰ�ڵ����һ����������֮���������Ϣ
			temp_node->data = current_node->next->data;

			//temp_node->next = before_node;
		
			before_node = current_node;

			//current_node->next = before_node;
			
			
		}
		else{
			temp_node->next = before_node;
			//temp_node = temp_node->next;
			//before_node->next = temp_node;
			//before_node->next->data = temp_node->data;
		}


	}
	return 1;
}
int NodeSingle::node_reverse_wrong2(){
	
	Node* current_node = m_list;
	Node * temp_node;
	Node*pre_node;
	while (current_node!=NULL)
	{
		pre_node = current_node;
		temp_node = current_node->next;
		temp_node->next = pre_node;
		current_node = current_node->next;
	}
	
	return 0;
}

int NodeSingle::node_reverse(){

	Node* p = m_list;
	
	Node*q = m_list->next;
	//p->next = NULL;
	m_list->next = NULL;
	Node *r;
	//while (p->next != NULL)
	while (q)//��qΪ0ʱ��˵��p�ߵ���ԭ����ľ�ͷ����ԭ����ͷ�Ǵ����ֵ�ġ�
	{
		
		//Node * r = q->next;
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	//��������裬ͷ�ڵ㲻���ֵ����������������ͷҲ�����ֵ������Ҫ������һ��
	m_list->next = p;
	m_list->data = 0;
	
	return 0;
}

NodeSingle *merge_two_sorted_link(NodeSingle *L1, NodeSingle *L2){
	cout << "-------" << endl;
	L1->display_node();
	L2->display_node();
	cout << "-------" << endl;
	Node node_l1;
	L1->node_search(1, &node_l1);
	Node node_l2;
	L2->node_search(1, &node_l2);

	NodeSingle *L3=new NodeSingle;
	while (L1->m_i_length != 0 && L2->m_i_length != 0)
	{
		if (node_l1.data <= node_l2.data){
			Node* node = new Node();
			L1->node_delete(1, node);
			cout << node->data << endl;
			L3->insert_node_from_head(node);
			//L1��С
			L1->node_search(1, &node_l1);
		}
		else{
			Node* node = new Node();
			L2->node_delete(1, node);
			cout << node->data << endl;
			L3->insert_node_from_head(node);
			//L2��С
			L2->node_search(1, &node_l2);
		}
	}

	if (L1->m_i_length > 0){
		for (int i = 0; i < L1->m_i_length; i++){
			Node* node = new Node();
			L1->node_delete(1, node);
			cout << node->data << endl;
			L3->insert_node_from_head(node);
		}
	}
	if (L2->m_i_length > 0){
		for (int i = 0; i < L2->m_i_length; i++){
			Node* node = new Node();
			L2->node_delete(1, node);
			cout << node->data << endl;
			L3->insert_node_from_head(node);
		}
	}
	L3->display_node();
	cout << "-------" << endl;
	L3->node_reverse();
	L3->display_node();
	cout << "-------" << endl;
	return L3;
}

int NodeSingle::find_medium_node(Node *node){
	Node* fast_node = m_list;
	Node* slow_node=m_list;
	while (fast_node)
	{
		fast_node = fast_node->next->next;
		slow_node = slow_node->next;
	}
	node->data=slow_node->data;
	return 0;
}

int main(){
	NodeSingle *single_node=new NodeSingle();
	Node node;
	node.next = NULL;
	node.data = 10;
	single_node->insert_node_from_head(&node);

	Node node2;
	node2.next = NULL;
	node2.data = 20;
	single_node->insert_node_from_head(&node2);
	single_node->node_reverse();
	single_node->display_node();//  20��10����1��2���ڵ㣩,,��ת֮����10��20
	
	NodeSingle*single_node2 = new NodeSingle();
	Node node3;
	node3.next = NULL;
	node3.data = 20;
	single_node2->insert_node_from_head(&node3);
	Node node4;
	node4.next = NULL;
	node4.data = 10;
	single_node2->insert_node_from_head(&node4);

	NodeSingle *node_merge=merge_two_sorted_link(single_node, single_node2);
	node_merge->display_node();



	NodeSingle *single_node3 = new NodeSingle();
	Node node5;
	node5.next = NULL;
	node5.data = 10;
	single_node3->insert_node_from_head(&node5);

	Node node6;
	node6.next = NULL;
	node6.data = 20;
	single_node3->insert_node_from_head(&node6);

	single_node3->display_node();//  20��10����1��2���ڵ㣩

	Node node_search;
	single_node3->node_search(1, &node_search);
	
	cout << "Ҫ�ҵĽڵ�: " << node_search.data << endl;
	
	

	int k = 1;
	Node node_deleted;
	node_deleted.next = NULL;
	single_node3->node_delete(k, &node_deleted);
	cout<<"��ɾ�����Ľڵ�: " << node_deleted.data << endl;
	single_node3->display_node();


	NodeSingle *single_node4 = new NodeSingle();
	Node node7;
	node7.next = NULL;
	node7.data = 1;
	single_node4->insert_node_from_head(&node7);
	Node node8;
	node8.next = NULL;
	node8.data = 2;
	single_node4->insert_node_from_head(&node8);
	Node node9;
	node9.next = NULL;
	node9.data = 3;
	single_node4->insert_node_from_head(&node9);
	Node* node_medium=new Node();
	single_node4->find_medium_node(node_medium);
	cout << node_medium->data << endl;
	system("pause");
	return 0;
}