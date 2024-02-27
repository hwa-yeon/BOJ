#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> myqueue;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		
		if (str == "push") {
			int num;
			cin >> num;
			myqueue.push(num);
		}
		else if (str == "pop") {
			if (myqueue.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << myqueue.front() << "\n";
				myqueue.pop();
			}
		}
		else if (str == "size") {
			cout << myqueue.size() << "\n";
		}
		else if (str == "empty") {
			if (myqueue.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (str == "front") {
			if (myqueue.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << myqueue.front() << "\n";
			}
		}
		else if (str == "back") {
			if (myqueue.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << myqueue.back() << "\n";
			}
		}
	}

	return 0;
}
