#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string answer_sheet, vector<string> sheets) {
    int answer = 0;
    
    int length=answer_sheet.size();
    int doubt[100]={0};
    int max_doubt=0;
    
    int i,j,k,l;
    
    for(i=0;i<sheets.size();i++){//모든 테스트 케이스 확인
        for(j=0;j<sheets[i].size();j++){//각 sheet에 대해서 확인
            for(k=i+1;k<sheets.size();k++){
                for(l=0;l<sheets[k].size();l++){
                    if(sheets[i][j]==sheets[k][l]){//doubt 발견됬을 때
                        doubt[j]=1;
                    }
                }
                int max_cont=0;
                int cont=0;
                int dbt_cnt=0;
                for(l=0;l<sheets[k].size();l++){//doubt 수 확인
                    if(doubt[l]==1){
                        dbt_cnt++;
                        cont++;
                        cout << " 1" ;
                    }else{
                        cout << " 0" ;
                        if(max_cont<cont){
                            max_cont=cont;
                        }
                        cont=0;
                    }
                }
                cout << dbt_cnt << " " << max_cont << endl;

            }
        }
    }

    int dbt_cnt=0;
    for(i=0;i<answer_sheet.size();i++){
        if(doubt[i]==1){
            dbt_cnt++;
        }
        cout << doubt[i] << " ";
    }cout << endl;
    
    cout << max_doubt;
    
    answer =  dbt_cnt + max_doubt*max_doubt;
    
    
    
    return answer;
}