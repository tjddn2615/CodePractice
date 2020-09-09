#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> fw(n, vector<int>(n,0));
    
    for (int i = 0; i < results.size() ; i++) {
        //cout << results[i][0]-1 << " " << results[i][1]-1 << endl;
        fw[results[i][0]-1][results[i][1]-1] = 1;
    }
    
    
    //출력 인풋 잘들어갔는 지 확인
    // for (int i = 0; i < n; i++) {   
    //     for (int j = 0; j < n; j++) {
    //         cout << fw[i][j] << " " ;   
    //     }cout << endl;
    // }
    // cout << endl;
    

    //핵심 알고리즘
    for (int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(fw[i][k] == 1 && fw[k][j] == 1){
                     fw[i][j] = 1;
                }
            }
        }
    }
        
    // 승 패를 연관성 하나로 합침
    for (int i = 0; i < n; i++) {   
        for (int j = 0; j < n; j++) {
            if(fw[i][j] != fw[j][i]) {
                fw[i][j] = 1;
            } 
        }
    }

    
    // 답 확인
    for (int i = 0; i < n; i++) {   
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (i != j && fw[i][j] == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            answer++;
        }
    }
    
    
    
    return answer;
}