#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// vector<int> ff(int n){
//     vector<int> v;
//     while(n>0){
//         if(n%10!=0) v.push_back(n%10);
//         n/=10;
//     }
//     return v;
// }

// int f(int n, vector<int> &dp){
//     // cout<<n<<" ";
//     if(n==0) return 0;
//     if(n==1) return 1;
//     if(dp[n]!=-1) return dp[n];
//     vector<int> v=ff(n);
//     int ans=INT_MAX;
//     for(int i=0; i<v.size(); i++){
//         ans=min(ans,1+f(n-v[i], dp));
//     }
//     return dp[n]=ans;
// }


int f(int n, vector<int> &v, vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=INT_MAX;
    for(int i=0; i<v.size(); i++){
        if(n>=v[i]){
            ans=min(ans,1+f(n-v[i],v,dp));
        }
    }
    return dp[n]=ans;
}

int main(){
    int n,am;
    cin>>n>>am;
    // vector<int> dp(n+1,-1);
    // cout<<f(n,dp)<<endl;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dp(am+1,-1);
    cout<<f(am,v,dp)<<endl;

}