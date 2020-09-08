#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char number[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F'};


string number_to_n(int num, int n){
    string result;
    
    if(num == 0) {
        return "0";
    }
    
    while(num > 0){
        result += number[num % n];
        num /= n;
    }
    
    reverse(result.begin(),result.end());
    
    return result;
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    string overall;
    
    for(int i = 0 ; overall.size() < m * t ; i++){
        string ngame = number_to_n(i, n);
        overall += ngame;
    }
    
    
    for(int i = 0; i< t; i++){
        answer += overall.at((m*i)+(p-1));
    }
    
    
    return answer;
}