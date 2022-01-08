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
  int a;
  M m;
  REP(i,n) {
    cin >> a;
    if (m[a]) m[a]++;
    else m[a] = 1;
  }

  ll ans = 0;
  for (auto x = m.begin(); x!=m.end(); x++) {
    int k = x->first;
    int v = x->second;
    if (v>k) ans+=v-k;
    else if (v<k) ans+=v;
  }
  cout << ans << endl;
  return 0;
}
