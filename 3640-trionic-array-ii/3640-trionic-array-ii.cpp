class Solution{
public:
    bool isTrionic(vector<int>&a){
        int n=a.size();
        if(n<4)return false;

        long long p=-1,q=-1;

        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1])return false;
            if(a[i]>a[i+1]){p=i;break;}
        }
        if(p==-1||p==0)return false;

        for(int j=(int)p;j<n-1;j++){
            if(a[j]==a[j+1])return false;
            if(a[j]<a[j+1]){q=j;break;}
        }
        if(q==-1||q==p||q>=n-2)return false;

        for(int k=(int)q+1;k<n-1;k++){
            if(a[k]>=a[k+1])return false;
        }
        return true;
    }

    long long maxSumTrionic(vector<int>&a){
        int n=a.size();
        if(n<4)return LLONG_MIN;

        const long long neg=-(1LL<<60);

        long long u=neg,ud=neg,udu=neg,ans=neg;

        for(int i=1;i<n;i++){
            long long nu=neg,nud=neg,nudu=neg;

            if(a[i-1]<a[i]){
                nu=max(1LL*a[i-1]+a[i],(u==neg?neg:u+a[i]));
                if(ud!=neg)nudu=max(nudu,ud+a[i]);
                if(udu!=neg)nudu=max(nudu,udu+a[i]);
            }

            if(a[i-1]>a[i]){
                if(u!=neg)nud=max(nud,u+a[i]);
                if(ud!=neg)nud=max(nud,ud+a[i]);
            }

            u=nu;ud=nud;udu=nudu;
            ans=max(ans,udu);
        }
        return ans;
    }
};
