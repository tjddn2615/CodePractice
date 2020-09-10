#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    int cnt = 0;
    
    for(auto c : s){
        if(c != ' '){
            tmp += c;
        }else{
            int size = tmp.size();
            for(int i = 0;i<size;i++){ 
                if(i % 2 == 0){
                    // 한글자만 대문자로
                    tmp[i] = toupper(tmp[i]);
                }else{
                    // 한글자만 소문자로
                    tmp[i] = tolower(tmp[i]);
                }
            }
            answer += (tmp + " ");
            
            tmp = "";
        }
    }
    
    int size = tmp.size();
    for(int i = 0;i<size;i++){ 
        if(i % 2 == 0){
            tmp[i] = toupper(tmp[i]);
        }else{
            tmp[i] = tolower(tmp[i]);
        }
    }
    answer += tmp;
    
    
    return answer;
}