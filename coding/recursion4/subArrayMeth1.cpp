#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={2,-2,-2,0,-2,2,2};
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            for(int k=i; k<=j; k++){
                cout<<v[k]<<" ";
            }
            cout<<f<<endl;
        }
    }
}