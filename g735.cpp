//#include <iostream>
//#include <vector>
#include <bits/stdc++.h>

#define iip pair<int,int>

using namespace std;

int main(){
    vector<iip>score;
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        score.push_back({temp,1});
    }
    int poi=101;
    for(int i=0;i<n;i++){
        poi=score[i].first;
        for(int j=0;j<n;j++){
            if( (score[j].first<poi)&&(score[j].first!=poi) ){
                score[j].second++;
            }else if(score[j].first==poi){
                continue;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<score[i].second<<' ';
    }
    return 0;
}
