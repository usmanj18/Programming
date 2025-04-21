#include<iostream>
using namespace std;
		//Simple Node Class
class Node {
public:
	int data;
	Node* next;
	Node(int val) {
		data = val;
		next = NULL;
	}
};
		//Making List of Nodes
class List {
private:
	Node* head;
	Node* tail;
public:
	List() {
		head = tail = NULL;
	}
		//Pushing Node to Front
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
		//Pushing Node to End
	void pushBack(int num) {
		Node* nvaNode = new Node(num);
		if (head == NULL) {
			head = tail = nvaNode;
		}
		else {
			tail->next = nvaNode;
			tail = nvaNode;
		}
	}
		//Deleting First Node
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
		//Deleting Last Node
	void popBack() {
		if (head == NULL) {
			cout << "List is Empty..\n";
		}
		else {
			Node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			temp->next = NULL;
			delete tail;
			tail = temp;
		}
	}
		//Adding Node to Middle
	void insert(int val, int index) {
		if (index < 0) {
			return;
		}
		else if (index == 0) {
			pushFront(val);
		}
		else {
			Node* nvaNode = new Node(val);
			Node* temp = head;
			for (int i = 0;i < index - 1;i++) {
				temp = temp->next;
			}
			nvaNode->next = temp->next;
			temp->next = nvaNode;
		}
	}
		//Searching Value from List
	void search(int val) {
		Node* temp = head;
		int index = 0;
		while (temp != NULL) {
			if (temp->data == val) {
				cout << "Number found at Index: " << index << endl;
				return;
			}
			temp = temp->next;
			index++;
		}
		cout << "Number not Found\n";
		return;
	}
		//Printing the List
	void print() {
		if (head == NULL) {
			cout << "List is Empty..\n";
			return;
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
};

int main() {
	List l1;

	l1.pushFront(5);
	l1.print();

	l1.pushFront(10);
	l1.print();

	l1.pushBack(12);
	l1.print();

	l1.insert(15, 2);
	l1.print();

	l1.popFront();
	l1.print();

	l1.popBack();
	l1.print();

	l1.search(25);

	return 0;
}