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
		if (isEmpty()) {
			head = tail = nvaNode;
			return;
		}
		else {
			nvaNode->next = head;
			head = nvaNode;
		}
	}
		//Detecting Cycle
	Node* cycle() {
		Node* slow=head;
		Node* fast=head;
		bool cycle = false;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				cycle=true;
				break;
			}
		}
		if (!cycle) {
			return NULL;
		}
		//Finding the Starting Point & Ending Cycle
		slow = head;
		Node* prev=NULL;
		while (fast != slow) {
			slow = slow->next;
			prev = fast;
			fast = fast->next;
		}
		prev->next = NULL; //Ends Cycle.
		return slow;
	}
		//Printing the List
	void print() {
		if (isEmpty()) {
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

	bool isEmpty() {
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
	//Psuhing Value 5
	l1.pushFront(5);
	l1.print();
	//Pushing Value 10
	l1.pushFront(10);
	l1.print();
	//Making pointer to hold Function
	Node* result = l1.cycle();
	if (result != NULL) {
		cout << "Cycle detected at Value: " << result->data << endl;
	}
	else {
		cout << "Cycle not Detected\n";
	}
	cout << "List after Removing Cycle: ";
	l1.print();

	return 0;
}