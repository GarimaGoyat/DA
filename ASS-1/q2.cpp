#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n-cnt-1;i++){
        if(a[i]==a[i+1]){
            int x=i;
            while(x!=n-cnt-1){
                a[x]=a[x+1];
                x++;
            }
            cnt++;
            i--;
        }
    }
    for(int i=0;i<n-cnt;i++){
        cout<<a[i]<<" ";
    }
	return 0;
}