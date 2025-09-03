#include <iostream>
using namespace std;
// CAN DO USING SET ALSO
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
// sort the array
    for(int i=0;i<n-1;i++){
        bool sorted=true;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                sorted=false;
            }
        }
        if(sorted) break;
    }
// check for distinct numbers
    int count=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]) count++;
    }
    cout<<count<<'\n';

    return 0;
}