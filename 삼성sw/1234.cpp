#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main(){

	int t, i, j, k;


	for(t=1;t<=10;t++){
		char input[100];
		char check[100];
		int chk_cnt=0;
		int num;
		cin >> num;
		cin >> input;	


		RE:
		for (i = 0; i < num-1; i++){
			//printf("%c %c\n", input[i], input[i+1]);
			if(input[i]==input[i+1]){
				//printf("in!!: %c %c\n", input[i], input[i+1]);
				input[i]='a';
				input[i+1]='a';
				for(j=1;j<num/2;j++){
					char tmp;
					if (input[i-j]==input[i+1+j]){
						//printf("in2!!: %c %c\n", input[i-j], input[i+1+j]);
						input[i-j]='a';
						input[i+1+j]='a';
					}else{
						break;
					}
				}
			}
		}

	
		memset(check, 0, sizeof(check));
		//recheck
		chk_cnt=0;
		for(i=0;i<num;i++){
			if (input[i]!='a'){
				check[chk_cnt] = input[i];
				chk_cnt++;
			}
		}
	
		//printf("check: %s\n",check);
		if (chk_cnt!=num){
			//printf("in goto\n");
			memset(input, 0, sizeof(input));
			strcpy(input, check);
			//printf("re input: %s\n",input);
			num=chk_cnt;
			goto RE;
		}



		cout << "#" <<t << " ";
		for(i=0;i<num;i++){
			if (input[i]!='a'){
				cout << input[i];
			}
		}
		cout << endl;

	}

	return 0;
}
