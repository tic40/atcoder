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

void solver(int n, int k, vector<int> p, vector<int> c) {
  REP(i,n) p[i]--; // 0-index

  ll ans = -LINF;

  REP(i,n) {
    ll cycle_sum = 0;
    int cycle_cnt = 0, v = i;
    while(1) {
      cycle_cnt++;
      cycle_sum += c[p[v]];
      v = p[v];
      if (v == i) break;
    }

    ll path = 0;
    int cnt = 0, v = i;
    while(1) {
      cnt++;
      path += c[p[v]];

      if (cnt > k) break;

      int num = (k - cnt) / cycle_cnt;
      ll score = path + max(0ll, cycle_sum) * num;
      chmax(ans, score);
      v = p[v];
      if (v == i) break;
    }
  }

  COUT(ans);
  return;
}

int main() {
  IOS;
  int n, k; cin >> n >> k;
  vector<int> p(n),c(n);
  REP(i,n) cin >> p[i];
  REP(i,n) cin >> c[i];

  solver(n,k,p,c);

  return 0;
}