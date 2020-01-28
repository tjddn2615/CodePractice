#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int test_case;
	int T;
	int i,j,k;
	int student[101]={0};
	int score;
	int max_loc;

	setbuf(stdout, NULL);
	scanf("%d", &T);


	for (test_case = 1; test_case <= T; ++test_case){
		for(i=0;i<1000;i++){
			cin >> score;
			student[score]++;
		}

		max_loc=0;
		for(i=1;i<100;i++){
			if (student[i]>=student[max_loc]){
				max_loc=i;
			}
		}
		cout << "#" << test_case << " " << max_loc << endl;
	}
	
	return 0;
}