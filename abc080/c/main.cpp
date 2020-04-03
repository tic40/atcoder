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
  int n; cin >> n;
  int f[n][10], p[n][11];
  REP(i,n) REP(j,10) {
    cin >> f[i][j];
  }
  REP(i,n) REP(j,11) {
    cin >> p[i][j];
  }
  int ans=-INF;
  for (int bit=1; bit < 1<<10; bit++) {
    int sum=0;
    REP(i,n) {
      int c=0;
      REP(j,10) if (bit >> j & f[i][j]) c++;
      sum+=p[i][c];
    }
    ans = max(ans,sum);
  }
  COUT(ans);
  return 0;
}
