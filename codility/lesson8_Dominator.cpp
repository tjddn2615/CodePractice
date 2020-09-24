#include <map>

int solution(vector<int> &A) {
    
    map<int, int> m;
    int maxv=0;
    int maxi=-1;
    int maxii=-1;
    bool sf = false;
    
    for(int i = 0; i< A.size(); i++) {
        if(m.count(A[i])) {
            m[A[i]]++;
            if(m[A[i]] > maxv) {
                maxv = m[A[i]];
                maxi = A[i];
                maxii = i;
                sf = false;
                cout << "max: " << m[A[i]] << endl;
            }
            else if(m[A[i]] == maxv) {
                cout << "sf: " << endl;
                sf = true;
            }
        }
        else{
            m.insert(make_pair(A[i],1));
            if(m[A[i]] > maxv) {
                maxv = m[A[i]];
                maxi = A[i];
                maxii = i;
            }
        }
    }
    
    if (maxv < A.size()/2 || sf) {
        cout << maxv << " " << A.size()/2 << endl;
        return -1;
    }
    return maxii;
    
}