#include <string>
#include <vector>
#include <iostream>

using namespace std;

//최대공약수
int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


//최소공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}


int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
    	answer = lcm(answer, arr[i]);
    }

    return answer;
}