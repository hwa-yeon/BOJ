#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int month = 1;
	int day = 1;
	int output = 1;

	int x, y;
	cin >> x >> y;
	while(x != month) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			while (day <= 31) {
				day++;
				output = (output + 1) % 7;
				if (day == 31) {
					month++;
					day = 1;
					output = (output + 1) % 7;
					break;
				}
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			while (day <= 30) {
				day++;
				output = (output + 1) % 7;
				if (day == 30) {
					month++;
					day = 1;
					output = (output + 1) % 7;
					break;
				}
			}
		}
		else if (month == 2) {
			while (day <= 28) {
				day++;
				output = (output + 1) % 7;
				if (day == 28) {
					month++;
					day = 1;
					output = (output + 1) % 7;
					break;
				}
			}
		}
	}

	while (y != day) {
		day++;
		output = (output + 1) % 7;
	}

	if (output == 0) cout << "SUN" << "\n";
	else if (output == 1) cout << "MON" << "\n";
	else if (output == 2) cout << "TUE" << "\n";
	else if (output == 3) cout << "WED" << "\n";
	else if (output == 4) cout << "THU" << "\n";
	else if (output == 5) cout << "FRI" << "\n";
	else if (output == 6) cout << "SAT" << "\n";

	return 0;
}
