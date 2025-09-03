#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    getline(cin,s);
    int n=s.size();
    for(int i=0;i<n-1;i++){
        bool sorted=true;
        for(int j=0;j<n-i-1;j++){
            if(s[j]>s[j+1]){
                swap(s[j],s[j+1]);
                sorted=false;
            }
        }
        if(sorted){
            break;
        }
    }
    cout<<s;

    return 0;
}