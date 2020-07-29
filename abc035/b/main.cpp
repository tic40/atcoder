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

int main() {
  IOS;
  string s; int t;
  cin >> s >> t;
  int n = s.size();

  P p = {0,0};
  int w = 0;
  REP(i,n) {
    if (s[i] == 'L') p.first--;
    else if (s[i] == 'R') p.first++;
    else if (s[i] == 'U') p.second++;
    else if (s[i] == 'D') p.second--;
    else w++;
  }

  int ans;
  if (t == 1) {
    ans = abs(p.first) + abs(p.second) + w;
  } else {
    int sum = abs(p.first) + abs(p.second);
    if (sum%2 == w%2) ans = max(0, sum - w);
    else ans = max(1, sum - w);
  }
  COUT(ans);
  return 0;
}
