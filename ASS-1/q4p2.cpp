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
    int p,q;
    cin>>p>>q;
    int b[p][q];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>b[i][j];
        }
    }
    int c[n][q];
    if(m!=p){
        cout<<"can't be mutiplied\n";
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<m;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<'\n';
    }

	return 0;
}