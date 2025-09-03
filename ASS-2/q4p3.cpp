#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin>>s;
    int n=s.size();
    int count=0;
    string a;
    for(int i=0;i<n;i++){
        int c=tolower(s[i]);
        if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='y'){
            a.push_back(s[i]);
        }
    }
    cout<<a;

    return 0;
}