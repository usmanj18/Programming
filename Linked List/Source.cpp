#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int val) {
		data = val;
		next = NULL;
	}
};

class List {
private:
	Node* head;
	Node* tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}

	void pushFront(int num) {
		Node* nvaNode = new Node(num);
		if (head == NULL) {
			head = tail = nvaNode;
			return;
		}
		else {
			nvaNode->next = head;
			head = nvaNode;
		}
	}

	void pushBack(int num) {
		Node* nvaNode = new Node(num);
		if (head == NULL) {
			head = tail = nvaNode;
			return;
		}
		else {
			tail->next = nvaNode;
			tail = nvaNode;
		}
	}

	void popFront() {
		if (head == NULL) {
			cout << "List is Empty..\n";
			return;
		}
		else {
			Node* temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
	}

	void popBack() {
		if (head == NULL) {
			cout << "List is Empty...\n";
			return;
		}
		else {
			Node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			temp -> next = NULL;
			delete tail;
			tail = temp;
		}
	}

	void print(){
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	List l1;
	l1.pushFront(2);
	l1.pushFront(1);

	l1.pushBack(3);
	l1.print();

	l1.popFront();
	l1.print();

	l1.popBack();
	l1.print();
	return 0;
}