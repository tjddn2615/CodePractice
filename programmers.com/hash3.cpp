#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    
    
    int i,j;
    
    //answer+=clothes.size();
    
    for(i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    
    
    // for(i=0;i<clothes.size();i++){
    //     m[clothes[i][1]]++;
    // }
    
    int temp=1;
    for(auto iter=m.begin();iter!=m.end();iter++){
        if(iter->second >=1 ){
            cout << iter->second << endl;
            temp*=iter->second + 1;
        }
    }
    answer+=temp;
    answer-=1;


    
    return answer;
}