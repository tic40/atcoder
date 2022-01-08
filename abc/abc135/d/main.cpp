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

string s;
// dp[i][j] := 先頭 i 文字として考えられるもののうち，13 で割ったあまりが j であるものの数
ll dp[100005][13];

void solve() {
  dp[0][0] = 1;
  int n = s.size();

  REP(i,n) {
    REP(j,13) {
      if (s[i] == '?') {
        REP(k,10) {
          dp[i+1][(j*10+k)%13] += dp[i][j];
        }
      } else {
        int x = s[i]-'0';
        dp[i+1][(j*10+x)%13] += dp[i][j];
      }
    }
    REP(j,13) dp[i+1][j] %= MOD;
  }

  COUT(dp[n][5]);
  return ;
}

int main() {
  IOS;
  cin >> s;
  solve();

  return 0;
}