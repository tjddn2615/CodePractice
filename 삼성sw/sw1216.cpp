#include <iostream>

using namespace std;

int main(){

	int i,j,k;
	int T, test_case;
	char input[100][100];
	int target_len;
	int count=0;
	int max=0;
	int flag=0;

	for(test_case=1;test_case<=10;test_case++){
		cin >> T;
		for(i=0;i<100;i++){
			cin >> input[i];
		}
		count = 0;
		max=0;
		
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				for(target_len=100;target_len>=1;target_len--){
					flag=0;
					for(k=0;k<target_len/2;k++){//horizontal
						if(j+target_len-1-k >= 100){
							break;
						}
						if(input[i][j+k]==input[i][j+target_len-1-k] && j+target_len-1-k < 100){
							flag++;
						}else{
							flag=0;
							break;
						}
					}
					if(flag==target_len/2){
						if (max<target_len){
							max=target_len;
							cout << i << ":" << j << endl;
						}
					}
					flag=0;
					for(k=0;k<target_len/2;k++){//vertical
						if(i+target_len-1-k >= 100){
							break;
						}
						if(input[i+k][j]==input[i+target_len-1-k][j]  && i+target_len-1-k < 100){
							flag++;
						}else{
							flag=0;
							break;
						}
					}
					if(flag==target_len/2){
						if (max<target_len){
							max=target_len;
						}
					}
				}
			}
		}
		cout << "#" << test_case << " " << max << endl;
	}


	return 0;
}
