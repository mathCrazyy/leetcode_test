/*
	单链表的一个节点由两部分组成，一部分存储当前节点的数据，一部分存储下一个节点的地址信息。
	1. 首先初始化，
	2. 插入
	3. 删除
	4. 查询某个位置的节点
	注意: 需要把Node节点和整个链表分开实现，混在一起很难写。
	欸...个人水平限制，作业不能百分百完成，目前写循环链表和双向链表会耗费大量的精力还不讨好，能看懂但是容易忘，暂时放弃
	
	反转链表参考： https://www.jianshu.com/p/84117123f709
	快慢指针，从而得到链表的中间位置。只需要一次遍历。https://blog.csdn.net/ttyue_123/article/details/52166442
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
	//NodeSingle *m_list;//这里不对了........就算是头，应该是用其组成部分。Node
	Node *m_list;
	
};

NodeSingle::NodeSingle()
{
	m_list = new Node();//申请了头节点,头节点的data不存放值。
	m_i_length = 0;//同时长度置为0.
}

NodeSingle::~NodeSingle()
{

}

int NodeSingle::insert_node_from_head_wrong(Node wait_insert_node){
	m_list->next = &wait_insert_node;//不能用Node 栈自动分配，否则会被自动释放
	m_list->next->data = wait_insert_node.data;
	
	m_i_length++;
	return 1;
}

int NodeSingle::insert_node_from_head(Node *wait_insert_node){
	
	wait_insert_node->next = m_list->next;//先把原来的m_list的下一个节点赋值给带插入的节点的下一个位置。
	
	m_list->next = wait_insert_node;//将带插入的节点插入到头地址的下面
	
	m_list->next->data = wait_insert_node->data;//头地址的下面的值赋值

	m_i_length++;//同时长度+1
	return 1;
}

int NodeSingle::display_node_wrong(){//修改了地址...导致后面不能用了
	
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
	//头节点是第0个节点，序号为0，k删除第1个节点，不能删除头节点。
	for (int i = 0; i < k; i++){//头节点不存放值，从第1个开始
			
		current_node = current_node->next;//这里是第k-1个节点，下一个就是要删除的
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
	beforenode->next = current_node->next;//current的node要比beforenode更下一层。
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
	searched_node->data = current_node->data;//current的node要比beforenode更下一层。
	
	current_node = NULL;

	return 1;
}

int NodeSingle::node_reverse_wrong(){
	Node *current_node = m_list;
	Node *temp_node = NULL;
	Node*before_node = NULL;
	for (int i = 0; i < m_i_length; i++){
		if (before_node == NULL){
			temp_node = current_node->next;//当前节点的下一个，包含了之后链表的信息
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
	while (q)//当q为0时，说明p走到了原链表的尽头，而原链表尽头是存放有值的。
	{
		
		//Node * r = q->next;
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	//我最初假设，头节点不存放值，而再逆序后，这里的头也存放了值，故需要往后退一格。
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
			//L1上小
			L1->node_search(1, &node_l1);
		}
		else{
			Node* node = new Node();
			L2->node_delete(1, node);
			cout << node->data << endl;
			L3->insert_node_from_head(node);
			//L2上小
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
	single_node->display_node();//  20，10（第1，2个节点）,,逆转之后是10，20
	
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

	single_node3->display_node();//  20，10（第1，2个节点）

	Node node_search;
	single_node3->node_search(1, &node_search);
	
	cout << "要找的节点: " << node_search.data << endl;
	
	

	int k = 1;
	Node node_deleted;
	node_deleted.next = NULL;
	single_node3->node_delete(k, &node_deleted);
	cout<<"被删除掉的节点: " << node_deleted.data << endl;
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