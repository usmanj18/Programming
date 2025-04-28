#include<iostream>
using namespace std;
	//Creating a Node.
class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int val) {
		data = val;
		prev=next = NULL;
	}
};
	//Creating List of Nodes.
class List {
private:
	Node* head;
	Node* tail;
public:
	List() {
		tail=head = NULL;
	}
	//Adding Node to Front
	void pushFront(int val) {
		Node* newNode = new Node(val);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	//Adding Node to End.
	void pushEnd(int val) {
		Node* newNode = new Node(val);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	//Deleting 1st Node.
	void popFront() {
		if (empty()) {
			cout << "List is Empty...\n";
		}
		else {
			Node* temp = head;
			head = temp->next;
			head->prev = NULL;
			temp->next = NULL;
			delete temp;
		}
	}
	//Deleting Last Node
	void popEnd() {
		if (empty()) {
			cout << "List is Empty...\n";
		}
		else {
			Node* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
	}
	//Displaying Node's Details.
	void print() {
		if (empty()) {
			cout << "List is Empty..\n";
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	//Empty Check.
	bool empty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	List l1;

	l1.pushFront(5);
	l1.pushFront(10);
	l1.pushFront(15);
	l1.pushFront(20);
	cout << "List: ";
	l1.print();

	l1.pushEnd(5);
	l1.pushEnd(10);
	l1.pushEnd(15);
	l1.pushEnd(20);
	cout << "List: ";
	l1.print();

	l1.popFront();
	cout << "List: ";
	l1.print();

	l1.popEnd();
	cout << "List: ";
	l1.print();
	return 0;
}