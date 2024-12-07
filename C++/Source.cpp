#include<iostream>
#include<string>
using namespace std;
class Start {
private:
	string text;
public:
	Start() {
		text = "Bismillah...!!!";
	}
	void settext(string txt) {
		text = txt;
	}
	string gettext() {
		return text;
	}
};
int main() {
	Start s1;
	string txt;
	cout << "Enter the Text: ";
	getline(cin,txt);
	s1.settext(txt);
	cout << "Your Text is: " << s1.gettext() << endl;
	return 0;
}