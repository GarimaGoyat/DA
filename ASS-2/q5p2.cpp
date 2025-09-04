#include <bits/stdc++.h>
using namespace std;

int main() {

	int x;
	cout<<"enter size of the matrix:\n";
	cin>>x;
	int a[3*x-2];
    
	for(int i=0;i<3*x-2;i++){
		cin>>a[i];
	}
	int y=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(i==j||i==j+1||i==j-1){
				cout<<a[y++]<<" ";
			}
			else{
				cout<<0<<" ";
			}
		}
		cout<<'\n';
	}

	return 0;
}