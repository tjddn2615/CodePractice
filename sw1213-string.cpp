#include <iostream>

using namespace std;

int main(){

	int T;
	int test_case;
	int i,j;

	string target;
	string input;
	int target_len;
	int input_len;
	int found=0;
	int count=0;

	for(test_case=1;test_case<=10;test_case++){
		cin >> T;
		cin >> target;
		cin >> input;
		count=0;

		target_len=target.length();
		input_len=input.length();

		for(i=0;i<input_len;){
			//found=-1;
			found=input.find(target,i);
			if(found>-1){
				count++;
				i=found+target_len;
			}else{
				found=1;
				i++;
			}
			//cout << found << endl;
			//cout << count << endl;
			
		}
		cout << "#" << test_case << " " << count << endl;


	}


	return 0;
}
