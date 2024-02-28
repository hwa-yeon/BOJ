#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string p;
		cin >> p;

		int n;
		cin >> n;

		string x;
		cin >> x;

		deque<int> D;
		string s = "";
		for (int j = 0; j < x.length(); j++) {
			if (isdigit(x[j])) {
				s += x[j];
			}
			else {
				if (s != "" || !s.empty()) {
					D.push_back(stoi(s));
					s = "";
				}
			}
		}

		int error = 0;
		int reverse = 0;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				if (reverse) {
					reverse = 0;
				}
				else {
					reverse = 1;
				}
			}
			else if (p[j] == 'D') {
				if (D.empty()) {
					error = 1;
					break;
				}
				else {
					if (reverse) {
						D.pop_back();
					}
					else {
						D.pop_front();
					}
				}
			}
		}

		if (error) {
			cout << "error" << "\n";
		}
		else {
			cout << "[";
			while (!D.empty()) {
				if (D.size() == 1) {
					cout << D.front();
					break;
				}

				if (reverse) {
					cout << D.back() << ",";
					D.pop_back();
				}
				else {
					cout << D.front() << ",";
					D.pop_front();
				}
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}
