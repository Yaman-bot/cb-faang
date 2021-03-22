#include <bits/stdc++.h>
using namespace std;

void arrows(int *a,int n){
    stack<int> s;
    stack<int> ans;

    for(int i=0;i<n;i++){
        bool flag = true;
        if(!s.empty()&& s.top()>0 &&a[i]<0){
            while(!s.empty()&& s.top()>0 &&a[i]<0){
                if(abs(a[i])==abs(s.top())){
                    s.pop();
                    flag=false;
                    break;
                }
                else if(abs(a[i])>abs(s.top())){
                    s.pop();
                    flag=true;
                }
                else if(abs(a[i])<abs(s.top())){
                    flag=false;
                    break;
                }
            }
            if(flag){
                s.push(a[i]);
            }
        }
        else{
            s.push(a[i]);
        }
    }

    while(!s.empty()){
        ans.push(s.top());
        s.pop();
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    arrows(a,n);
}