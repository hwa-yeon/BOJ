#include <iostream>
#include <cmath>
using namespace std;

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}
	func(a, 6 - a - b, n - 1);
	cout << a << " " << b << "\n";
	func(6 - a - b, b, n - 1);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int count = pow(2, N) - 1;
	cout << count << "\n";
	func(1, 3, N);

	return 0;
}
