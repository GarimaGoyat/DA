#include <iostream>
using namespace std;

int main() {
    char s1[100],s2[100];
    cin>>s1;
    cin>>s2;
    char s[200];
    int i=0,x=0,j=0;
    while(s1[i]!='\0'){
        s[x]=s1[i];
        i++;
        x++;
    }
    while(s2[j]!='\0'){
        s[x]=s2[j];
        j++;
        x++;
    }
    cout<<s;
    return 0;
}