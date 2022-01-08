#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
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
  int h,w; cin >> h >> w;
  string a[h];
  REP(i,h) cin >> a[i];

  vector<bool> he(h,1),we(w,1);
  REP(i,h) REP(j,w) {
    if (a[i][j] == '#') he[i] = false;
  }

  REP(i,w) REP(j,h) {
    if (a[j][i] == '#') we[i] = false;
  }

  REP(i,h) {
    if (he[i]) continue;
    REP(j,w) if (!we[j]) cout << a[i][j];
    cout << endl;
  }
  return 0;
}
