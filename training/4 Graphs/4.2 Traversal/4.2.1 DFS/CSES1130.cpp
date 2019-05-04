#include<bits/stdc++.h>
using namespace std;struct Q{int f,s;};int n;set<int>g[500001];
Q d(int u,int p){int m=0;Q a=Q();for (int v:g[u]){if(v-p){Q c=d(v,u);a.s+=c.f;m=max(m,-c.f+c.s+1);}}a.f=a.s+m;return a;}int main(){cin>>n;for(int i=n-1,u,v;i--;){cin>>u>>v;g[u].insert(v);g[v].insert(u);}Q a=d(1,0);cout<<a.f;}