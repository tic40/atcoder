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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const int m = 1000005;

int main() {
  IOS;
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> cnt(m, 0);

  for (int x: a) {
    if(cnt[x] != 0) {
      cnt[x] = 2;
      continue;
    }
    for (int i = x; i < m; i+=x) cnt[i]++;
  }
  int ans = 0;
  for (int x: a) {
    if (cnt[x] == 1) ans++;
  }
  COUT(ans);
  return 0;
}