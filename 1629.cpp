#include <iostream>
#include <cmath>
using namespace std;

long long pow(int a, int b, int c) {
	if (b == 1)	return a % c;
	long long num = pow(a, b / 2, c);
	num = num * num % c;
	if (b % 2 == 0) return num;
	else return num * a % c;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	cout << pow(A, B, C) << "\n";

	return 0;
}
