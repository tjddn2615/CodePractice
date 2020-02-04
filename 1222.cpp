#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	string input;

	for(int T=1; T<=10; T++){
		int num;

		cin >> num;
		cin >> input;

		int tmp=0;
		int count=0;
		for(int i=0;i<num;i++){
			if(i%2==1){
				continue;
			}
			tmp=(input[i]-48);
			//cout << tmp << endl;
			count+=tmp;
		}
		cout << "#" << T << " " << count <<endl;
	}

	return 0;

}
