#include <bits/stdc++.h>
using namespace std;

void unique(){
    char a[1000];
    cin>>a;

    int lastIndex[26]={0};
    bool presentInStack[26];

    stack<char> s;

    for(int i=0;a[i]!='\0';i++){
        lastIndex[a[i]-'a']=i;
        presentInStack[a[i]-'a']=false;
    }

    for(int i=0;a[i]!='\0';i++){
        char ch=a[i];
        if(!presentInStack[ch-'a']){
            while(!s.empty() && ch<s.top() && lastIndex[s.top()-'a']>i){
                presentInStack[s.top()-'a']=false;
                s.pop();
            }
            presentInStack[ch-'a']=true;
            s.push(ch);    
        }
    }

    int k=s.size();
    char *ans=new char[k+1];
    ans[k--]='\0';
    while(!s.empty()){
        ans[k]=s.top();
        s.pop();
        k--;
    }

    cout<<ans;
}

int main(){
    unique();
}