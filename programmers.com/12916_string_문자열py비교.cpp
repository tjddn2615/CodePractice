#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cntP=0,cntY=0;
    
    for(int i = 0; i< s.size();i++){
        
        if(tolower(s.at(i)) == 'p'){
            cntP++;
        }
        else if(tolower(s.at(i)) == 'y'){
            cntY++;
        }
    }
    
    if(cntP == cntY){
        return true;
    }else{
        return false;
    }
}