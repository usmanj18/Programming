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
	//Copying a List.
	void copy() {
		//Head of new List
		Node* newHead = new Node(head->data);
		Node* oldtemp = head->next;   //cuz Head is already copied.
		Node* newtemp = newHead;
		while (oldtemp != NULL) {
			Node* copyNode = new Node(oldtemp->data);
			newtemp->next = copyNode;  //point new node to the next of newtemp.
			oldtemp = oldtemp->next;
			newtemp = newtemp->next;
		}
		//Displaying copied List.
		Node* temp = newHead;
		cout << "Copied List: ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
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

	l1.insert(5);
	l1.insert(10);
	l1.insert(15);
	l1.insert(20);
	cout << "List: ";
	l1.print();

	l1.copy();

	return 0;
}