#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(){

	int i,j,k;
	int test_case;

	stack<char> s;
	char input[500];

	int target_len;
	int error=1;//1=valid 0=error

	for(test_case=1;test_case<=10;test_case++){
		scanf("%d",&target_len);

		scanf("%s", &input);

		//printf("%d %s\n",target_len, input);
		error=1;
		for(i=0;i<target_len;i++){
			if(input[i]=='{' || input[i]=='[' || input[i]=='(' || input[i]=='<'){
				s.push(input[i]);
			}else{
				if(input[i]=='}' && s.top()=='{') s.pop();
				else if(input[i]==']' && s.top()=='[') s.pop();
				else if(input[i]==')' && s.top()=='(') s.pop();
				else if(input[i]=='>' && s.top()=='<') s.pop(); 
				else {
					error=0;
					break;
				}
			}
		}

		cout << "#" << test_case << " " << error << endl;

	}


	return 0;
}

