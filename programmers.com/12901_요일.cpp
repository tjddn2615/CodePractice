#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int overall = 0;
    
    vector<string> date = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> month = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    for(int i = 0; i < a-1 ; i++){
        overall += month[i];
    }
    overall += b;

    int tmp = (overall % 7) - 1;
    
    if(tmp == -1){
        tmp = 6;
    }
    
    answer += date[tmp];
    
    return answer;
}