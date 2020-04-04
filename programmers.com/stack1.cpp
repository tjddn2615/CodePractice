#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    int i,j;
    
    stack<int> s;
    
    for(i=heights.size()-1;i>-1;i--){
        int flag=0;
        for(j=i-1;j>-1;j--){
            if(heights[i]<heights[j]){
                //cout << "i: " << i <<", j: " << j << endl;
                s.push(j+1);
                //cout << "top check: " << s.top() << endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            s.push(0);
        }
    }
    
    cout << "size: " << s.size() << endl;
     
    while(!s.empty()){
        //cout << "top: " << s.top() << endl;
        answer.push_back(s.top());
        s.pop();
    }
    
    return answer;
}