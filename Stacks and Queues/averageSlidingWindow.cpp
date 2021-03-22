#include <iostream>
#include <queue>
using namespace std;

void average(){
    int k;
    cin>>k;
    queue<int> q;

    int n;
    cin>>n;
    int sum=0;
    while(n!=-1){
        sum+=n;
        q.push(n);

        if(q.size()>k){
            sum-=q.front();
            q.pop();
        }
        cout<<(double)(sum)/q.size()<<" ";
        cin>>n;
    }
    cout<<endl;
}

int main(){
    average();
    return 0;
}