#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,a; cin >> n;
  vector<int> o,e;
  REP(i,n) {
    cin >> a;
    if (i%2) o.push_back(a);
    else e.push_back(a);
  }

  M mo,me;
  REP(i,o.size()) mo[o[i]]++;
  REP(i,e.size()) me[e[i]]++;

  int o1=0,o1k;
  REP(i,o.size()) {
    if (o1 < mo[o[i]]) {
      o1 = mo[o[i]];
      o1k = o[i];
    }
  }
  mo[o1k] = 0;
  int o2=0;
  REP(i,o.size()) o2 = max(o2,mo[o[i]]);

  int e1=0,e1k;
  REP(i,e.size()) {
    if (e1 < me[e[i]]) {
      e1 = me[e[i]];
      e1k = e[i];
    }
  }
  me[e1k] = 0;
  int e2=0;
  REP(i,e.size()) e2 = max(e2,me[e[i]]);

  int ans = INF;
  int tot = o.size()+e.size();
  if (o1k==e1k) {
    if (e2==0) ans = tot - o1;
    else ans = tot - o1 - e2;

    if (o2==0) ans = min(ans, tot - e1);
    else ans = min(ans, tot -o2 - e1);

  } else ans = tot - (e1+o1);
  COUT(ans);
  return 0;
}
