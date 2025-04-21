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
		//Reversing the Nodes
	void reverse() {
		Node* prev = NULL;
		Node* curr = head;
		Node* next = NULL;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		} 
		head = prev;
	}
};

int main() {
	List l1;

	l1.insert(5);
	l1.insert(10);
	l1.insert(15);

	cout << "Original: ";
	l1.display();

	cout << "Reversed: ";
	l1.reverse();
	l1.display();

	return 0;
}