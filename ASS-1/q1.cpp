#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];

void create(){
    cout<<"enter size of array:\n";
    cin>>n;
    cout<<"enter all array elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"created\n";
}

void display(){
    if(n==0){
        cout<<"no elements present in the array\n";
        return;
    }
    cout<<"the elements of the array are:\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\ndisplayed\n";
}

void insert(){
    int x;
    cout<<"enter element you want to insert:\n";
    cin>>x;
    int p;
    cout<<"enter the pos or index of element you want in array:\n";
    cin>>p;
    for(int i=n;i>p;i--){
        a[i]=a[i-1];
    }
    a[p]=x;
    n++;
    cout<<"inserted\n";
}

void DeleteElement(){
    int x;
    cout<<"enter the element want to delete:\n";
    cin>>x;
    int p;
    cout<<"enter the index of the element:\n";
    cin>>p;
    for(int i=p;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    cout<<"deleted\n";
}

void linearsearch(){
    int x;
    cout<<"enter the element want to search:\n";
    cin>>x;
    bool found=false;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            cout<<"the position of x in the array is : "<<i<<'\n';
            found=true;
        }
    }
    if(found) cout<<"found\n";
    else cout<<"not found\n";
}


int main() {

    cout<<"the menu is like this:\n";
    cout<<"1. create\n";
    cout<<"2. display\n";
    cout<<"3. insert\n";
    cout<<"4. DeleteElement\n";
    cout<<"5. linearsearch\n";
    cout<<"6. exit\n";
    int x;
    do{
        cout<<"Enter which operation from the menu you want to do:";
        cin>>x;
        switch(x){
            case 1:create();break;
            case 2:display();break;
            case 3:insert();break;
            case 4:DeleteElement();break;
            case 5:linearsearch();break; 
            case 6:cout<<"exiting\n";break;   
        }
    }while(x!=6);

	return 0;
}