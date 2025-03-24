#include<iostream>
using namespace std;
int main() {
	const int n = 2, m = 3;
	int arr[n][m] = { 1,2,3,4,5,6 };
	cout << "Array is: \n";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int target;
	cout << "Enter Element to Search: ";
	cin >> target;
	bool found = false;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == target) {
				cout << "Element found at Row '" << i << "' and Column '" << j << "'\n";
				found = true;
			}
		}
	}
	if (!found) {
		cout << "Not Found..:(\n";
	}
	return 0;
}