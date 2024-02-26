#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack< pair<int, int> > mystack;
	vector<int> arr(N , -1);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		while (!mystack.empty() && mystack.top().second < num) {
			arr[mystack.top().first] = num;
			mystack.pop();
		}

		mystack.push(make_pair(i, num));
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}
