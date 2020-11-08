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

ll dp[200005];

int main() {
  IOS;
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  ll ans = -LINF;

  vector<ll> s(n+1);
  REP(i,n) {
    s[i+1] = a[i] + s[i];
  }

  // i 時点での最大＋方向
  dp[0] = 0;
  REP(i,n) {
    dp[i+1] = max(dp[i], a[i]+s[i]);
  }

  ll pos = 0;
  REP(i,n+1) {
    chmax(ans, pos + dp[i]);
    pos += s[i];
  }

  COUT(ans);
  return 0;
}