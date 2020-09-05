#include <iostream>

using namespace std;

int main(){

	int i,j,k;
	int T, test_case;
	char input[8][8];
	int target_len;
	int flag=0;
	int count=0;

	for(test_case=1;test_case<=10;test_case++){

		cin >> target_len;
		for(i=0;i<8;i++){
			cin >> input[i];
		}
		count = 0;
		
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				flag=0;
				for(k=0;k<target_len/2;k++){//horizontal
					if(input[i][j+k]==input[i][j+target_len-1-k] && j+target_len-1-k < 8){
						flag++;
					}else{
						flag=0;
					}
				}
				if(flag==target_len/2){
					count++;
				}
				flag=0;
				for(k=0;k<target_len/2;k++){//vertical
					if(input[i+k][j]==input[i+target_len-1-k][j]  && i+target_len-1-k < 8){
						flag++;
					}else{
						flag=0;
					}
				}
				if(flag==target_len/2){
					count++;
				}
			}
		}

		cout << "#" << test_case << " " << count << endl;

	}

	return 0;
}
