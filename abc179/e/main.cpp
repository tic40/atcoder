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

ll n,x,m;

int main() {
  IOS;
  cin >> n >> x >> m;
  int start, loop;

  vector<int> a(n), s(n), pre(100010,-1);
  a[1] = s[1] = x;
  pre[x] = 1;

  for (int i = 2; i <= n; i++) {
    a[i] = a[i-1] * a[i-1] % m;
    s[i] = s[i-1] + a[i];
    if (i == n) {
      COUT(s[i]);
      return 0; // ループ検知前にnに達したら答えを出力して終了
    }
    if (pre[a[i]] >= 0) {
      start = pre[a[i]]; // loop スタート
      loop = i-pre[a[i]]; // loop の長さ
      break; // ループ検知したら終了
    }
    pre[a[i]] = i;
  }

  ll ans = 0;
  ll lp = (n-start)/loop;
  ans += lp * (s[start + loop] - s[start]);
  n -= lp * loop;
  ans += s[n];
  COUT(ans);

  return 0;
}