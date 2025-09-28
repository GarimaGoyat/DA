#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n-1];
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(i!=a[i-1]){
            cout<<i;
            break;
        }
    }
    return 0;
}

/*
    int n;
    cin>>n;
    vector<int> a(n);
    int mini=INT_MAX;
    int maxi=INT_MIN;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
        s.insert(a[i]);
    }
    vector<int> v;
    for(auto it:s){
        v.push_back(it);
    }
    int x=0;
    for(int i=mini;i<=maxi;i++){
        if(v[x]!=i){
            cout<<i<<" ";
        }
        else{
            x++;
        }
    }
*/