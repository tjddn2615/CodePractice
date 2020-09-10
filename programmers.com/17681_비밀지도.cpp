#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


string number_to_2(int num){
    string result;
 
    if(num == 0) {
        return "0";
    }
    
    while(num > 0){
        result += to_string(num % 2);
        num /= 2;
        //cout << result << " " ;
    }//cout << endl;
    
    reverse(result.begin(),result.end());
    
    return result;
    
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n,"");
    
    for(int i = 0;i < n;i++){
        //cout << number_to_2(arr1[i]) << endl;
        string tmp1 = number_to_2(arr1[i]);
        while(tmp1.size() < n){
            tmp1 = "0"+tmp1;
        }
        string tmp2 = number_to_2(arr2[i]);
        while(tmp2.size() < n){
            tmp2 = "0"+tmp2;
        }
        //cout << tmp1 << " " << tmp2 << endl;
        
        for(int j = 0;j<n;j++){
            //cout << tmp1[j] << " " << tmp2[j] << " ";
            if (tmp1[j] == '1' || tmp2[j] == '1') {
                answer[i] = answer[i] + "#";
                //cout << "add #" << endl;
            }
            else if (tmp1[j] == '0' && tmp2[j] == '0') {
                answer[i] = answer[i] + " ";
               // cout << "add space" << endl;
            }
        }//cout << "line jump" << endl;
    }

    // for(int i = 0;i < n;i++){
    //     cout << answer[i] << endl;   
    // }cout << endl;
    
    return answer;
}