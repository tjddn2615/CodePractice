#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

	int i,T,t;




	cin >> T;
	for(t=1;t<=T;t++){

		string origin;
		int str_len;
		int target;
		vector <string> v;

		cin >> target;
		cin >> origin;

		v.push_back(origin);

		for(i=1;i<origin.size();i++){
			v.push_back(origin.substr(i));
		}

		sort(v.begin(),v.end());
		printf("#%d %s\n", t, v[target-1].c_str());

	}//T

	return 0;
}