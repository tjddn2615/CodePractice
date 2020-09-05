#include <cstdio>

using namespace std;

int main(){

	int test_case;
	int i;

	int num;
	int base, mul;


	for(test_case=1;test_case<=10;test_case++){

		scanf("%d", &num);
		scanf("%d %d", &base, &mul);

		int tmp=base;
		for(i=0;i<mul-1;i++){
			tmp*=base;
		}

		printf("#%d %d\n", test_case, tmp);

	}

	return 0;

}