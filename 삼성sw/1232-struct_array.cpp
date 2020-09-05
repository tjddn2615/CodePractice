#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

struct input {
	int num;
	char sign;
	int con1, con2;
};

struct input tree[1001];

int pow(int a, int b){
	int i, pow = 1;
	for (i = 0; i < b; i++){
		pow *= a; 
	}
	return pow;
}

float cal(int src){
	float a,b;
	float result;

	if (tree[src].num){
		//cout << "ret: " << tree[src].num << endl;
		return tree[src].num;
	}else if (tree[src].sign){
		a=cal(tree[src].con1);
		b=cal(tree[src].con2);
		if (tree[src].sign=='+'){
			result=a+b;
		//	cout << a <<"+"<<b<<":" <<result<<endl;
		}else if (tree[src].sign=='-'){
			result=a-b;
		//	cout << a <<"-"<<b<<":" <<result<<endl;
		}else if (tree[src].sign=='*'){
			result=a*b;
		//	cout << a <<"*"<<b<<":" <<result<<endl;
		}else if (tree[src].sign=='/'){
			result=a/b;
		//	cout << a <<"/"<<b<<":" <<result<<endl;
		}
		return result;
	}

}

int main(){

	int i,j,k,t;
	int num;


	for(t=1;t<=10;t++){
		
		for(i=0;i<1001;i++){
			tree[i].num=0;
			tree[i].sign='0';
			tree[i].con1=0;
			tree[i].con1=0;
		}
		
		
		//input
		cin >> num;
		for(i=1;i<=num;i++){
			int tmp;
			string tmpc;
			cin >> tmp >> tmpc;
			if (isdigit(tmpc[0])){
				int sum=0;
				for(j=0;j<tmpc.length();j++){
					sum+=(int)(tmpc[j]-'0')*pow(10,tmpc.length()-j-1);
				}
				//cout << sum << " " << "num: " << tmpc[0] << " : "<< tmpc[1] << "///" << tmpc.length() << endl;
				tree[i].num=sum;
			}else{
				tree[i].sign=tmpc[0];
				cin >> tree[i].con1 >> tree[i].con2;
			}
		}

		//cout << endl;

//		for(i=1;i<=num;i++){//input check
//			cout << tree[i].num << tree[i].sign << tree[i].con1 << tree[i].con2 << endl;
//		}

		int ret=cal(1);

		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}
