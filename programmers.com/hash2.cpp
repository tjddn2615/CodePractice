#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    int i,j;
    
    for(i=0;i<phone_book.size();i++){
        for(j=0;j<phone_book.size();j++){
            if(i==j){
                continue;
            }
            
            int str_len=phone_book[i].size();
            int str_len2=phone_book[j].size();
            
            if(str_len>str_len2){
                continue;
            }
            
            int result = phone_book[i].compare(0, str_len, phone_book[j], 0, str_len);
            if(result==0){
                return false;
            }
        }
    }
    
    
    
    
    
    
    return answer;
}