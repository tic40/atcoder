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
  int m; cin >> m;
  int a[n];
  REP(i,n) cin >> a[i];
  int total = 0;
  REP(i,n) total+=a[i];
  double v = total / (4.0*m);
  int cnt=0;
  REP(i,n) {
    if (a[i] >= v) cnt++;
  }
  if (cnt >= m) COUT("Yes");
  else COUT("No");
  return 0;
}
