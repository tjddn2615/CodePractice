#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	string numSystem[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
	for (int tc = 1; tc <= T; tc++) {
		string tmp;
		int n;
		cin >> tmp;
		cin >> n;
		int nums[10] = { 0 };
		for (int i = 0; i < n; i++) {
			string num = "";
			cin >> num;
			if (num == numSystem[0]) nums[0]++;
			else if (num == numSystem[1]) nums[1]++;
			else if (num == numSystem[2]) nums[2]++;
			else if (num == numSystem[3]) nums[3]++;
			else if (num == numSystem[4]) nums[4]++;
			else if (num == numSystem[5]) nums[5]++;
			else if (num == numSystem[6]) nums[6]++;
			else if (num == numSystem[7]) nums[7]++;
			else if (num == numSystem[8]) nums[8]++;
			else if (num == numSystem[9]) nums[9]++;
		}

		cout << "#" << tc << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < nums[i]; j++) {
				cout << numSystem[i] + " ";
			}
		}
		cout << endl;
	}
}