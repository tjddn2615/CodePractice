#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v(n+1,0);
    v[1] = 1;
    
    for(int i = 2; i <= n ; i++){
        for(int j = i; j <= n ;j+=i){
            if(j==i){
                continue;
            }
            //cout << "j" << j << endl;
            v[j]=1;
        }
    }
    
    for(int i = 1; i <= n ; i++){
        //cout << i << " "<< v[i] << endl;
        if (v[i] == 0){
            answer++;
        }
    }
    
    return answer;
}