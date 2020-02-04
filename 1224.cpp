#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int cal(int n, string input){
	int tmp=1;
	int b_num;
	int count=0;
	for(int i=0;i<num;i++){
		if(input[i]=='+'){
			tmp*=b_num;
			//cout << tmp << endl;
			count+=tmp;
			tmp=1;
		}else if(input[i]=='*'){
			tmp*=b_num;
		}else if(input[i]=='('){
			cal(i, input)
		}
		else{
			b_num=(input[i]-48);	
		}
	}
}

int main() {
	string input;

	for(int T=1; T<=10; T++){
		int num;

		cin >> num;
		cin >> input;

		int tmp=1;
		int b_num;
		int count=0;

		for(int i=0;i<num;i++){
			if(input[i]=='+'){
				tmp*=b_num;
				//cout << tmp << endl;
				count+=tmp;
				tmp=1;
			}else if(input[i]=='*'){
				tmp*=b_num;
			}else if(input[i]=='('){
				
			}
			else{
				b_num=(input[i]-48);	
			}
		}
		
		//cout << tmp << endl;
		count+=tmp*b_num;
		

		cout << "#" << T << " " << count <<endl;
	}

	return 0;
}