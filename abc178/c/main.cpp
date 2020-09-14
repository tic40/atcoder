#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n;

ll modpow(ll x, ll y) {
  ll v = 1;
  REP(i,y) {
    v *= x; v %= MOD;
  }
  return v;
}

// 包除原理解法
void solve1() {
  ll p1 = modpow(10, n);
  ll p2 = (modpow(9, n) * 2) % MOD;
  ll p3 = modpow(8, n);
  ll ans = p1 - (p2 - p3);
  ans %= MOD;
  ans = (ans + MOD) % MOD;
  COUT(ans);
}

// DP解法
// dp[桁数][0,9使用状況]
int dp[1000000][1<<2];
void solve2() {
  dp[0][0] = 1;
  REP(i,n) {
    REP(j,1<<2) {
      REP(d,10) {
        int nj = j | ( d == 0 ? 1 : 0 ) | ( d == 9 ? 2 : 0 );
        dp[i+1][nj] += dp[i][j];
        dp[i+1][nj] %= MOD;
      }
    }
  }
  COUT(dp[n][3]);
}

int main() {
  IOS;
  cin >> n;
  // solve1();
  solve2();
  return 0;
}