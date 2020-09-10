#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 1;

    int i = 0;
    stringstream ssInt(s);
    ssInt >> i;
        //cout << i << endl;
    
    return i;
}