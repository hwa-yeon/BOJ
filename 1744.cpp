#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> minus;
	vector<int> plus;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num > 0) {
			plus.push_back(num);
		}
		else {
			minus.push_back(num);
		}
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	int result = 0;
	for (int i = 0; i < minus.size(); i += 2) {
		if (i == minus.size() - 1) {
			result += minus[i];
			break;
		}

		result += (minus[i] * minus[i + 1]);
	}
	for (int i = plus.size() - 1; i >= 0; i -= 2) {
		if (i == 0) {
			result += plus[i];
			break;
		}
		if (plus[i] == 1 || plus[i - 1] == 1) {
			result += plus[i];
			result += plus[i - 1];
			continue;
		}
		result += (plus[i] * plus[i - 1]);
	}

	cout << result << "\n";

	return 0;
}
