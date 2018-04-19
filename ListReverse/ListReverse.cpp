#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

class ListNode{
public:
	ListNode(int value){
		cout<<"Constructor..."<<endl;
		init(value);
	}
	void init(int value);
	void printList(char * list_name);
	const ListNode * getNext();
	void setNext(ListNode * next);
	ListNode * reverse(ListNode * head);
	~ListNode(){
		cout<<"Destructor..."<<endl;
	}
private:
	int value;
	ListNode * next;
};

void ListNode::init(int value){
	this->value = value;
	this->next = NULL;
}

void ListNode::printList(char * list_name){
	//printf("%s",*list_name);
	cout<<list_name;
	ListNode * head = this;
	if(!head){
		cout<<"NULL"<<endl;
		return;
	}
	while(head){
		cout<<head->value<<ends;
		head = head->next;
	}
	cout<<endl;
}

const ListNode * ListNode::getNext(){
	return this->next;
}

void ListNode::setNext(ListNode * next){
	this->next = next;
}

ListNode * ListNode::reverse(ListNode * head){
	ListNode * new_head = NULL;//new_head��ָ�������ͷָ�룬��ʼ��Ϊ��ʹ�õ�һ���ڵ��һ��ָ��գ���ʾ���������Ҳ�������һ���ڵ�
	ListNode * temp = NULL;//temp���м������������¼���õ��ĸ��ڵ���
	if(!head){//���headָ��Null˵��û�нڵ�,ֱ�ӽ���
		cout<<"NULL"<<endl;
		return new_head;
	}
	//1.����˳������
	//2.��head�쵼һ���ڵ��˳�������ж�����ָ������������ͷ
	//3.new_headָ��ͷ����Ϊ������2����new_head��ָ��ڶ����ڵ�
	//4.headָ��˳���б�
	while(head){//ֻҪhead��ָ��NULL��һֱ����
		temp = head->next;//tempָ��head����һ���ڵ㣬���ڡ��쵼��ʣ�µĽڵ㣬����һ��ͷ���ָ��Ľڵ���ʣ�µĽڵ�Ͽ����޷�Ѱ��
		head->next = new_head;//head�ĵ�һ���ڵ��nextָ���Ǹճ�ʼ��ΪNULL��new_head����ʾ�������е����һ���ڵ㣻ʣ�µ�ѭ���б�ʾ��
		//ʣ��˳������Ͽ�������ڵ��nextָ�����е����������������ǵ��ͷ
		new_head = head;//��new_head�Ƶ���������ĵ�һ���ڵ㣬��Ϊ��head�¶������ģ����Է��ڿ�ͷ������new_headָ��head������
		head = temp;//head��Ҫ�����ҵ�˳���������Ϊһֱ��temp�쵼�����Ծ�ָ��temp���Խ�����һ�εĶϿ�

	}
	return new_head;
}

int main(){
	//ListNode a = ListNode(6);
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);