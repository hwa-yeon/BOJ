#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	vector<int> coin(n);
	vector<int> arr(k + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	arr[0] = 1;
	for (int i = 0; i < n; i++) {
		int temp = coin[i];
		for (int j = temp; j <= k; j++) {
			arr[j] += arr[j - temp];
		}
	}
	cout << arr[k] << "\n";

	return 0;
}
