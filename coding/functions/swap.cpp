#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter two no. : ";
    cin>>a>>b;
    int temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b;

}