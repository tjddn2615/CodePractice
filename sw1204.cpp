#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int test_case;
	int T;
	int i,j,k;
	int student[101]={0,};
	int score;
	int max_loc;
	int num;

	//setbuf(stdout, NULL);
	scanf("%d", &T);


	for (test_case = 1; test_case <= T; ++test_case){
		cin >> num;
		for(i=0;i<101;i++){//initialize
			student[i]=0;
		}
		
		for(i=0;i<1000;i++){//input
			cin >> score;
			student[score]+=1;
			score=0;
			//cout << "input: " << score << endl;
		}

		max_loc=0;
		for(i=1;i<101;i++){//find max
			//cout << "every count" << i << " : " << student[i] << endl;
			if (student[i]>=student[max_loc]){
				max_loc=i;
			//	cout << "out: " << i << " ; " << student[max_loc] << endl;
			}
		}
		
		cout << "#" << test_case << " " << max_loc << endl;
	}
	
	return 0;
}
