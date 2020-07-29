#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<vector<int>> arr22;
    
    int result_x = arr1.size();
    int result_y = arr2[0].size();
    
    //cout << result_x << " " << result_y << endl;
    
    for(int i=0;i<arr2.size();i++){
        vector<int> tmp_v;
        for(int j=0;j<arr2[0].size();j++){
            tmp_v.push_back(0);
        }
        arr22.push_back(tmp_v);
    }
    
    
    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<arr2[0].size();j++){
            arr22[j][i]=arr2[i][j];
        }
    }
    
    // arr22 출력
    // for(int i=0;i<arr22.size();i++){
    //     for(int j=0;j<arr22[0].size();j++){
    //         cout << arr22[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i=0;i<result_x;i++){
        vector<int> tmp_v;
        for(int j=0;j<result_y;j++){
            tmp_v.push_back(0);
        }
        answer.push_back(tmp_v);
    }
    
//  answer 0 들어갔는 지 확인
//     for(int i=0;i<result_x;i++){
//         for(int j=0;j<result_y;j++){
//             cout << answer[i][j] << " ";
//         }
//         cout << endl;
//     }
    
    
    for(int i=0;i<result_x;i++){
        for(int j=0;j<result_y;j++){
            
            for(int i2=0;i2<arr2[0].size();i2++){
                for(int j2=0;j2<arr22[0].size();j2++){
                    //cout << arr1[i][i2]*arr22[j2][j] << endl;
                    answer[i][j]+=arr1[i][i2]*arr2[i2][j];
                }
            }
        }
    }
    
    for(int i=0;i<result_x;i++){
        for(int j=0;j<result_y;j++){
            answer[i][j]/=arr2[0].size();
        }
    }
    
    
    return answer;
}