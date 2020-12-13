#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  IOS;
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  a.push_back(n+1);
  sort(ALL(a));

  int cur = 1;
  vector<int> s;

  REP(i,m+1) {
    int w = a[i] - cur;
    if (0 < w) s.push_back(w);
    cur = a[i]+1;
  }
  int k = n;
  for (int w: s) k = min(k, w);

  int ans = 0;
  for(int w: s) ans += (w+k-1)/k;
  COUT(ans);
  return 0;
}