#include<iostream>
using namespace std;
		//Making a Node
class Node {
public:
	int value;
	Node* next;
	Node(int v) {
		value = v;
		next = NULL;
	}
};
		//Making List of Nodes
class List {
private:
	Node* head;
public:
	List() {
		head = NULL;
	}
		//Inserting Values in Nodes
	void insert(int val) {
		Node* nvaNode = new Node(val);
		if (head == NULL) {
			head = nvaNode;
			return;
		}
		nvaNode->next = head;
		head = nvaNode;
	}
		//Displaying Values
	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
		//Finding Middle Node
//Method 1:
	void m1() {
		Node* temp = head;
		int size= 0;
		while (temp != NULL) {
			temp = temp->next;
			size++;
		}
		if (size == 0) {
			cout << "List is Empty\n";
			return;
		}
		int mid = (size / 2);
		temp = head;
		for (int i = 0;i < mid;i++) {
			temp = temp->next;
		}
		cout << "Middle Index is: " << mid << endl;
		cout << "Value at Middle is: " << temp->value << endl;
	}
//Method 2:
		//Slow Fast Pointer
	void m2() {
		Node* slow;
		Node* fast;
		int index = 0;
		slow = fast = head;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			index++;
		}
		cout << "Middle Index is: " << index<< endl;
		cout << "Middle Index Value is: " << slow->value << endl;
	}
};

int main() {
	List l1;
	
	l1.insert(5);
	l1.insert(10);
	l1.insert(15);

	l1.display();
	cout << "==================\n";
	l1.m1();
	cout << "==================\n";
	l1.m2();

	return 0;
}