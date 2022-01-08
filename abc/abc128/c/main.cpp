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

int main() {
  IOS;
  int n,m; cin >> n >> m;
  vector<int> k(m), p(m);
  vector<vector<int>> s(m);
  REP(i,m) {
    cin >> k[i];
    REP(j,k[i]) {
      int _s;
      cin >> _s;
      s[i].push_back(_s-1);
    }
  }
  REP(i,m) cin >> p[i];

  int ans = 0;
  for (int bit = 0; bit < 1<<n; bit++) {
    vector<int> bits;
    REP(i,n) {
      if (bit >> i & 1) bits.push_back(i);
    }

    int ok = true;
    REP(i, m) {
      int sum = 0;
      REP(j,k[i]) {
        for (auto x: bits) {
          if(x == s[i][j]) { sum++; break; }
        }
      }
      if (sum % 2 != p[i]) { ok = false; break; }
    }
    if (ok) ans++;
  }

  COUT(ans);
  return 0;
}