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
  int n,k; cin >> n >> k;
  int x[n];
  REP(i,n) cin >> x[i];

  int ans = INF;
  REP(l,n-k+1) {
    int r = l+k-1;
    int totl = abs(x[l]) + abs(x[r]-x[l]);
    int totr = abs(x[r]) + abs(x[r]-x[l]);
    ans = min(ans, min(totl, totr));
  }
  COUT(ans);
  return 0;
}
