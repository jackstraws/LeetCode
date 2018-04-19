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
	ListNode * new_head = NULL;//new_head是指向逆序的头指针，初始化为空使得第一个节点第一次指向空，表示链表结束，也就是最后一个节点
	ListNode * temp = NULL;//temp是中间变量，用来记录逆置到哪个节点了
	if(!head){//如果head指向Null说明没有节点,直接结束
		cout<<"NULL"<<endl;
		return new_head;
	}
	//1.备份顺序链表
	//2.由head领导一个节点从顺序链表中断下来指向逆序的链表的头
	//3.new_head指向头，因为经过第2步后new_head会指向第二个节点
	//4.head指回顺序列表
	while(head){//只要head不指向NULL就一直逆置
		temp = head->next;//temp指向head的下一个节点，用于“领导”剩下的节点，否则一会头结点指向的节点会和剩下的节点断开，无法寻找
		head->next = new_head;//head的第一个节点的next指向是刚初始化为NULL的new_head，表示逆置链中的最后一个节点；剩下的循环中表示和
		//剩下顺序链表断开，这个节点的next指向已有的逆序链表，放在他们的最开头
		new_head = head;//把new_head移到逆序链表的第一个节点，因为是head新断下来的，所以放在开头，所以new_head指向head就行了
		head = temp;//head需要重新找到顺序的链表，因为一直由temp领导，所以就指向temp，以进行下一次的断开

	}
	return new_head;
}

int main(){
	//ListNode a = ListNode(6);
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);