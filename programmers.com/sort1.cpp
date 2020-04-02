#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i,j,k;
    
    vector<int> tmp;
    
    for(i=0;i<commands.size();i++){
        for(j=commands[i][0]-1;j<commands[i][1];j++){
            tmp.push_back(array[j]);
           // cout << "j: " << j << "   " << array[j] << endl;
        }
        sort(tmp.begin(),tmp.end());
         
        int ans=commands[i][2]-1;
        answer.push_back(tmp[ans]);
        
        tmp.clear();
    }
    

    
    
    
    
    return answer;
}