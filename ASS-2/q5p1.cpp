#include <bits/stdc++.h>
using namespace std;

int main() {

	int x;
	cout<<"enter size of the matrix:\n";
	cin>>x;
	int a[x];
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	int y=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(i==j){
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