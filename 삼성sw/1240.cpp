#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){

    int T;
    int t,i,j,k;

    int height,len;

    cin >> T;
    //cout << T;
    for(t=1;t<T+1;t++){
        string input;
        char input_c[100];
        int input_i[8];
        int input_cnt=7;
        cin >> height >> len;        
        //printf("h:%d l:%d",height,len);
        for(i=0;i<height;i++){
            cin >> input;
            //cout << "input: " << input << endl; 
            if(input.find("1")<=len && input.find("1")>=0){
                string tmp;
                for(j=i+1;j<height;j++){
                    cin>>tmp;
                }
                break;
            }
        }

        //cout << "input: " << input << endl;


        //find
        strcpy(input_c,input.c_str());

       // printf("input_c:%s", input_c);

        for(i=len;i>=0;i--){
            //0
            if(input_c[i-6]=='0'&&input_c[i-5]=='0'&&input_c[i-4]=='0'&&input_c[i-3]=='1'&&input_c[i-2]=='1'&&input_c[i-1]=='0'&&input_c[i]=='1'){

         //       printf("0: ");
                input_i[input_cnt]=0;
                input_cnt--;
                i-=6;
            //1
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='0'&&input_c[i-4]=='1'&&input_c[i-3]=='1'&&input_c[i-2]=='0'&&input_c[i-1]=='0'&&input_c[i]=='1'){

                input_i[input_cnt]=1;
                input_cnt--;
                i-=6;
                
            //2
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='0'&&input_c[i-4]=='1'&&input_c[i-3]=='0'&&input_c[i-2]=='0'&&input_c[i-1]=='1'&&input_c[i]=='1'){
            
                input_i[input_cnt]=2;
                input_cnt--;
                i-=6;
            //3
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='1'&&input_c[i-4]=='1'&&input_c[i-3]=='1'&&input_c[i-2]=='1'&&input_c[i-1]=='0'&&input_c[i]=='1'){
            
 
                input_i[input_cnt]=3;
                input_cnt--;
                i-=6;               
                
            //4
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='1'&&input_c[i-4]=='0'&&input_c[i-3]=='0'&&input_c[i-2]=='0'&&input_c[i-1]=='1'&&input_c[i]=='1'){
            

                input_i[input_cnt]=4;
                input_cnt--;
                i-=6;
            //5
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='1'&&input_c[i-4]=='1'&&input_c[i-3]=='0'&&input_c[i-2]=='0'&&input_c[i-1]=='0'&&input_c[i]=='1'){
 
                input_i[input_cnt]=5;
                input_cnt--;
                i-=6;           
            //6
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='1'&&input_c[i-4]=='0'&&input_c[i-3]=='1'&&input_c[i-2]=='1'&&input_c[i-1]=='1'&&input_c[i]=='1'){
 
                input_i[input_cnt]=6;
                input_cnt--;
                i-=6;           
            //7
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='1'&&input_c[i-4]=='1'&&input_c[i-3]=='1'&&input_c[i-2]=='0'&&input_c[i-1]=='1'&&input_c[i]=='1'){
            
                input_i[input_cnt]=7;
                input_cnt--;
                i-=6;
            //8
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='1'&&input_c[i-4]=='1'&&input_c[i-3]=='0'&&input_c[i-2]=='1'&&input_c[i-1]=='1'&&input_c[i]=='1'){
            
                input_i[input_cnt]=8;
                input_cnt--;
                i-=6;
            //9
            }else if(input_c[i-6]=='0'&&input_c[i-5]=='0'&&input_c[i-4]=='0'&&input_c[i-3]=='1'&&input_c[i-2]=='0'&&input_c[i-1]=='1'&&input_c[i]=='1'){

                input_i[input_cnt]=9;
                input_cnt--;
                i-=6;
            }
        }

        // printf("hello");
        // for(i=0;i<8;i++){
        //    printf("%d ", input_i[i]);
        // }
        // printf("\n");
        
        int result=(input_i[0]+input_i[2]+input_i[4]+input_i[6])*3+(input_i[1]+input_i[3]+input_i[5])+input_i[7];
        if(result%5==0){
            int sum=0;
            for(j=0;j<8;j++){
                sum+=input_i[j];
            }
            printf("#%d %d\n",t,sum);
        }else{
            printf("#%d %d\n",t,0);
        }
    }


    return 0;
}

