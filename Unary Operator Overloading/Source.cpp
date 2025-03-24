#include<iostream>
using namespace std;
class name {
private:
	int num;
public:
	name() {
		num = 10;
	}
	void display() {
		cout << "The Value is: " << num << endl;
	}
	void operator++() {
		++num;
	}
	void operator++(int) {
		num++;
	}
	void operator--() {
		--num;
	}
	void operator--(int) {
		num--;
	}
};
int main() {
	name n1;
	cout << "Originally ";
	n1.display();
	++n1;
	cout << "After Pre Increment ";
	n1.display();
	n1++;
	cout << "After Post Increment: ";
	n1.display();
	--n1;
	cout << "After Pre Decrement: ";
	n1.display();
	n1--;
	cout << "After Post Decrement: ";
	n1.display();
	return 0;
}