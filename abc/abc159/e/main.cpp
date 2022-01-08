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

int c[10][1005];

int main() {
  int h,w,k; cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  int ans = INF;

  REP(div,1<<(h-1)) {
    int g = 0;
    vector<int> id(h);
    REP(i,h) {
      id[i] = g;
      if (div>>i&1) g++;
    }
    g++;

    // 初期化
    REP(i,g) REP(j,w) c[i][j] = 0;
    REP(i,h) REP(j,w) c[id[i]][j] += (s[i][j]-'0');
    bool ok = true;
    REP(i,g) REP(j,w) if (c[i][j] > k) ok = false;
    if (!ok) continue;

    int num = g-1;
    vector<int> now(g);
    auto add = [&](int j) {
      REP(i,g) now[i] += c[i][j];
      REP(i,g) if (now[i] > k) return false;
      return true;
    };
    REP(j,w) {
      if (!add(j)) {
        num++;
        now = vector<int>(g);
        add(j);
      }
    }
    ans = min(ans,num);
  }

  cout << ans << endl;
  return 0;
}