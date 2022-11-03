#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,t;
    cin>>n;
    vector<int>num;
    for(int i=0;i<n;i++){
        cin>>t;
        num.push_back(t);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(num[j]<num[j+1]){
                num[j]=num[j]^num[j+1];
                num[j+1]=num[j+1]^num[j];
                num[j]=num[j]^num[j+1];
            }
        }
    }
    cout<<num[(n-1)/2]<<endl;
    return 0;
}
