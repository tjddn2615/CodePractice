#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        char tmp= ' ';
        if(s[i] >= 'A' && s[i] <= 'Z'){
            tmp = 'A';
        }
        else if(s[i] >= 'a' && s[i] <= 'z') {
            tmp = 'a';
        }
        if(s[i] != ' '){
            tmp = (s[i] + n - tmp) % 26 + tmp;
        }
        answer += tmp;
    }
    
    
    return answer;
}