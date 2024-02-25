#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<int> mystack;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			mystack.push(num);
		}
		else if (str == "pop") {
			if (mystack.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << mystack.top() << "\n";
				mystack.pop();
			}
		}
		else if (str == "size") {
			cout << mystack.size() << "\n";
		}
		else if (str == "empty") {
			if (mystack.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "top") {
			if (mystack.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << mystack.top() << "\n";
			}
		}
	}

	return 0;
}
