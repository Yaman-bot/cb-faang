#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> temperature(int *a,int n){
    vector<int> ans;
    stack<int> s;

    for(int i=0;i<n;i++){
        ans.push_back(0);
    }

    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]<a[i]){
            int x=s.top();
            s.pop();
            ans[x]=i-x;
        }
        s.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    vector<int> v;
    v=temperature(a,n);
    for(auto x:v){
        cout<<x<<" ";
    }
}