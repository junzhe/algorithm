#include <iostream>
#include <cstring>
#include <string>

using namespace std;

    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int count = 0;
        int d1[S.size() + 1];
        int d2[S.size() + 1];
	
	for(int i=0;i<=S.size();i++) {
		d1[i] = 1;
	}

	memset(d2, 0, (S.size() + 1)*sizeof(int));
        
        for(int i=1; i<=T.size();i++) {
            count = 0;
            for(int j = 1; j<=S.size(); j++) {
                if(T[i-1]!=S[j-1]) d2[j] = count;
                else {
			d2[j] = d1[j-1] + count;
			count = d2[j];
		}
            }
            
            memcpy(d1, d2, sizeof(int)*(S.size() + 1));
            memset(d2, 0, sizeof(int)*(S.size() + 1));
        }
        
        return d1[S.size()];
    }

int main(){
	cout<<numDistinct("aaaaaaaaabbbbbbbbbb", "ab")<<endl;
}
