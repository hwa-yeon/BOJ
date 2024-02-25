#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<int> myqueue;
	for (int i = 1; i <= N; i++) {
		myqueue.push(i);
	}

	cout << "<";
	while (myqueue.size() > 1) {
		for (int i = 0; i < (K - 1); i++) {
			myqueue.push(myqueue.front());
			myqueue.pop();
		}
		cout << myqueue.front() << ", ";
		myqueue.pop();
	}
	cout << myqueue.front() << ">" << "\n";

	return 0;
}
