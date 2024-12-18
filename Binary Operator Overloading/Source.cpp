#include<iostream>
using namespace std;
class name {
private:
	int num;
public:
	name(int n) {
		num = n;
	}
	void display() {
		cout << "Value is: " << num << endl;
	}
	name operator+(name n2) {
		return num + n2.num;
	}
	name operator-(name n2) {
		return num - n2.num;
	}
	name operator*(name n2) {
		return num * n2.num;
	}
	name operator/(name n2) {
		return num / n2.num;
	}
};
int main() {
	name n1(10);
	cout << "In 1st Object ";
	n1.display();
	name n2(5);
	cout << "In 2nd Object ";
	n2.display();
	name sum(0);
	sum = n1 + n2;
	cout << "After Sum ";
	sum.display();
	name diff(0);
	diff = n1 - n2;
	cout << "After Difference ";
	diff.display();
	name prod(0);
	prod = n1 * n2;
	cout << "After Product ";
	prod.display();
	name div(0);
	div = n1 / n2;
	cout << "After Division ";
	div.display();
	return 0;
}