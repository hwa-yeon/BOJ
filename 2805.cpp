#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<long long> tree;

bool solve(long long leng) {

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] - leng > 0) {
			sum += tree[i] - leng;
		}
	}

	if (sum >= M) return true;
	else return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	tree.resize(N);

	long long maxTree = 0;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		maxTree = max(maxTree, tree[i]);
	}
	sort(tree.begin(), tree.end());

	long long st = 0;
	long long en = maxTree;
	while (st < en) {
		long long mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st << "\n";

	return 0;
}
