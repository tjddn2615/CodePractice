#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> arr2(arr.begin(),arr.end());
    vector<int> answer;
    
    sort(arr2.begin(),arr2.end(), greater<>());
    
    int min = arr2[arr2.size()-1];
    
    if(arr.size() == 1){
        answer.push_back(-1);
    }else{
        for(auto ar : arr){
            if(ar == min){
                continue;
            }else{
                answer.push_back(ar);
            }
        }
    }
    
    return answer;
}