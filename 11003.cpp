#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	deque< pair<int, int> > DQ;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (!DQ.empty() && i == DQ.front().second + L) {
			DQ.pop_front();
		}
		while (!DQ.empty() && DQ.back().first > num) {
			DQ.pop_back();
		}

		DQ.push_back(make_pair(num, i));
		cout << DQ.front().first << " ";
	}
	cout << "\n";

	return 0;
}
