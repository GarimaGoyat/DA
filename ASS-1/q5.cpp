#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=a[i][j];
        }
        cout<<"sum of all elements of row "<<i+1<<" : "<<sum<<'\n';
    }
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[j][i];
        }
        cout<<"sum of all elements of column "<<i+1<<" : "<<sum<<'\n';
    }

	return 0;
}