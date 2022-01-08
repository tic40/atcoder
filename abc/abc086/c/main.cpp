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
  int t[n+1],x[n+1],y[n+1];
  t[0]=0; x[0]=0; y[0]=0;
  REP(i,n) cin >> t[i+1] >> x[i+1] >> y[i+1];

  int ok = 1;
  for (int i = 1; i <= n; i++) {
    int d = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
    int td = t[i] - t[i-1];
    if (td < d) ok = 0;
    else if(td > d && (td-d)%2) ok = 0;
  }
  COUT(ok ? "Yes" : "No");
  return 0;
}
