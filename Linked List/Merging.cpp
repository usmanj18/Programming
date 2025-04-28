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
		tail=head = NULL;
	}
	void insert(int val) {
		Node* newNode = new Node(val);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
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
	Node* getHead() {
		return head;
	}
	void setHead(Node* h1) {
		head = h1;
	}
	Node* merge(Node* h1, Node* h2) {
		if (h1 == NULL) return h2;
		if (h2 == NULL) return h1;
		if (h1->data <= h2->data) {
			h1->next = merge(h1->next, h2);
			return h1;
		}
		else {
			h2->next = merge(h1, h2->next);
			return h2;
		}
	}
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
	List l1, l2, l3;

	l1.insert(5);
	l1.insert(10);
	l1.insert(15);
	l1.insert(20);
	cout << "List 1: ";
	l1.print();

	l2.insert(6);
	l2.insert(9);
	l2.insert(13);
	l2.insert(27);
	cout << "List 2: ";
	l2.print();

	Node* result = l3.merge(l1.getHead(), l2.getHead());
	l3.setHead(result);
	cout << "Merged List: ";
	l3.print();

	return 0;
}