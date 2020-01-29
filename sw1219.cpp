#include <cstdio>

using namespace std;

int main(){

	int T;
	int test_case;
	int i;

	int len;
	int tmp;
	int input1[100]={-1};
	int input2[100]={-1};


	for(test_case=1;test_case<=10;test_case++){

		scanf("%d %d", &T, &len);
		for(i=0;i<len;i++){
			scanf("%d", &tmp);
			if (input[tmp]==0){
				scanf("%d", &input1[tmp]);
			}else{
				scanf("%d", &input2[tmp]);
			}
		}

	}	

	return 0;
}