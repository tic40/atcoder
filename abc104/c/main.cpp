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
  int d,g;
  cin >> d >> g;
  int p[d],c[d];
  REP(i,d) cin >> p[i] >> c[i];

  int ans = INF;
  for (int bit = 0; bit < (1 << d); bit++) {
    int cnt = 0, sum = 0;
    REP(i,d) {
      if (bit >> i & 1) {
        sum += 100 * (i+1) * p[i] + c[i];
        cnt += p[i];
      }
    }

    if (g <= sum) {
      ans = min(ans, cnt);
    } else {
      int mxidx;
      for (int i = d-1; 0 <= i; i--) {
        if (bit >> i & 1) continue;
        mxidx = i;
        break;
      }

      REP(j,p[mxidx]) {
        sum += 100 * (mxidx+1);
        cnt++;
        if (g <= sum) ans = min(ans, cnt);
      }
    }
  }

  COUT(ans);
  return 0;
}
