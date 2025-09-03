#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int x;
    cin>>x;
    int a[n];
    for(int i=0;i<n;i++){
     cin>>a[i];
    }
    int high=n-1;
    int low=0;
    int mid;
    bool found=false;
    while(low<=high){
    mid=(low+high)/2;
    if(a[mid]==x){
        found=true;
        break;
    }
    if(a[mid]<x){
        low=mid+1;
    }
    else if(a[mid]>x){
        high=mid-1;
    }
    }
    if(found){
        cout<<mid;
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}