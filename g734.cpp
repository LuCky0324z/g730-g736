#include <bits/stdc++.h>
#define MustGoFast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    MustGoFast;
    int n,c,temp;
    vector<int>h,d,l,r,la,ra;
    d.push_back(0);
    vector<int>ps;//prefix sum
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>temp;
        h.push_back(temp);
    }
    for(int i=0;i<n-1;i++){
        cin>>temp;
        d.push_back(temp);
    }
    l.assign(n,-1);
    r.assign(n,-1);
    la.assign(n,-1);
    ra.assign(n,-1);

    ps.assign(n,0);
    ps[0]=0;
    for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+d[i];
    }

    //left
    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0){
            if(h[i]<=h[j]){
                l[i]=j;
                break;
            }else{
                if(l[j]>-1){
                    j=l[j];
                }else{
                    l[i]=-1;
                    break;
                }
            }
        }
    }

    //right
    for(int i=n-2;i>-1;i--){
        int j=i+1;
        while (j<n){
            if(h[i]<=h[j]){
                r[i]=j;
                break;
            }else{
                if(r[j]>-1){
                    j=r[j];
                }else{
                    r[i]=-1;
                    break;
                }
            }
        }
    }

    int max_v=INT_MAX;
    int min_a=max_v;

    for(int i=0;i<n;i++){
        //計算  與右隔板圍成的面積 
        if (r[i]!=-1) 
            ra[i] = h[i]*(ps[r[i]]-ps[i]);
        //檢查是否為目前最小面積
        if (ra[i]>=c && ra[i]<min_a)
            min_a = ra[i];

        //計算  與左隔板圍成的面積
        if (l[i]!=-1)
            la[i] = h[i]*(ps[i]-ps[l[i]]);
        //檢查是否為目前最小面積
        if (la[i]>=c && la[i]<min_a)
            min_a = la[i];
        
        //提早結束
        if (min_a==c)  
            break;        
    }

    if(min_a==max_v){
        cout<<-1<<endl;
    }else{
        cout<<min_a<<endl;
    }

    return 0;
}
