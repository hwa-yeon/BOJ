#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector< vector<int> > A(N, vector<int>(3));
	A[0][0] = 1;
	A[0][1] = 1;
	A[0][2] = 1;
	for (int i = 1; i < N; i++) {
		A[i][0] = (A[i - 1][1] + A[i - 1][2]) % 9901;
		A[i][1] = (A[i - 1][0] + A[i - 1][2]) % 9901;
		A[i][2] = (A[i - 1][0] + A[i - 1][1] + A[i - 1][2]) % 9901;
	}

	int result = (A[N - 1][0] + A[N - 1][1] + A[N - 1][2]) % 9901;
	cout << result << "\n";

	return 0;
}
