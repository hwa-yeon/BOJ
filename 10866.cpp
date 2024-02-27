#include <iostream>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> mydeque;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int num;
			cin >> num;
			mydeque.push_front(num);
		}
		else if (str == "push_back") {
			int num;
			cin >> num;
			mydeque.push_back(num);
		}
		else if (str == "pop_front") {
			if (mydeque.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << mydeque.front() << "\n";
				mydeque.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (mydeque.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << mydeque.back() << "\n";
				mydeque.pop_back();
			}
		}
		else if (str == "size") {
			cout << mydeque.size() << "\n";
		}
		else if (str == "empty") {
			if (mydeque.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (str == "front") {
			if (mydeque.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << mydeque.front() << "\n";
			}
		}
		else if (str == "back") {
			if (mydeque.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << mydeque.back() << "\n";
			}
		}
	}

	return 0;
}
