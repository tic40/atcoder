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
const int MOD = 1e9+7;
const ll LINF = 1e18;

string s;
int x,y;
const int MAXN = 16010;
int dp[2][MAXN][MAXN];
const int BASE = MAXN/2;

int main() {
  IOS;
  cin >> s >> x >> y;

  vector<int> a;
  int cnt = 0;
  REP(i,s.size()) {
    if (s[i] == 'F') { cnt++; continue; }
    a.push_back(cnt);
    cnt = 0;
  }
  a.push_back(cnt);

  dp[0][0][BASE] = 1;
  dp[1][0][BASE] = 1;

  int d = 0; // x: 0, y: 1
  int counter[2] = { 0, 0 };

  REP(i,a.size()) {
    counter[d]++;
    cnt = counter[d];

    REP(j, MAXN) {
      if (dp[d][cnt-1][j]) {
        if (j+a[i] < MAXN) dp[d][cnt][j+a[i]] = 1;
        if (i > 0 && j-a[i] >= 0) dp[d][cnt][j-a[i]] = 1;
      }
    }
    d = !d; // 方向反転
  }

  Yes( dp[0][counter[0]][x+BASE] && dp[1][counter[1]][y+BASE] );
  return 0;
}