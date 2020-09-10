#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int cnt = 0;
    
    for(int i = phone_number.size()-1; i >= 0; i--){
        if(cnt < 4){
            answer += phone_number[i];
            cnt ++;
        }
        else {
            answer += "*";
        }
    }
    
    reverse(answer.begin(),answer.end());
    
    
    return answer;
}