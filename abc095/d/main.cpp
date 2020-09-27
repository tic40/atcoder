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

ll n,c;

int main() {
  IOS;
  cin >> n >> c;
  vector<ll> x(n),v(n);
  REP(i,n) cin >> x[i] >> v[i];

  ll ans = 0;
  vector<pair<ll,ll>> s(n+1); // 累積和 <oa, 2oa>
  REP(i,n) {
    s[i+1].first = s[i].first + v[i] - x[i];
    s[i+1].second = s[i].second + v[i] - x[i]*2;
    if (0 < i) {
      s[i+1].first += x[i-1];
      s[i+1].second += x[i-1]*2;
    }
    chmax(ans,s[i+1].first);
  }

  vector<pair<ll,ll>> dp(n+1); // dp[i] = iまでの最大値. <oa, 2oa>
  REP(i,n) {
    dp[i+1] = {
      max(dp[i].first,s[i+1].first),
      max(dp[i].second,s[i+1].second)
    };
  }

  ll sum = 0;
  for (int i = n-1; 0 <= i; i--) {
    sum += v[i];
    chmax(ans, sum - (c-x[i]) + dp[i].second);
    chmax(ans, sum - (c-x[i])*2 + dp[i].first);
  }

  COUT(ans);
  return 0;
}