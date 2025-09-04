#include <bits/stdc++.h>
using namespace std;

int main() {

    int x;
    cout<<"enter the size of matrix:\n";
    cin>>x;
    int size=x*(x+1)/2;
    int mapidx[x][x];
    int k=0;

    for(int i=0;i<x;i++){
        for(int j=i;j<x;j++){
            mapidx[i][j]=k;
            mapidx[j][i]=k;
            k++;
        }
    }
    int a[size];
    cout<<"enter the "<<size<<" elements of upper tri matrix row wise:\n";
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<"the symmetric matrix is:\n";
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<a[mapidx[i][j]]<<" ";
        }
        cout<<'\n';
    }

	return 0;
}