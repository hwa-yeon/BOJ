#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		A[i] = i + 1;
	}

	cout << "<";
	int temp = K - 1;
	while (!A.empty()) {
		if (A.size() == 1) {
			cout << A[temp] << ">";
			break;
		}

		cout << A[temp] << ", ";
		A.erase(A.begin() + temp);
		temp = (temp + (K - 1)) % A.size();
	}

	cout << "\n";

	return 0;
}
