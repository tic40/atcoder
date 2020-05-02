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

int n,m,q;
ll ans = 0;
vector<int> a(101),b(101),c(101),d(101);

void dfs(vector<int> v, int las) {
  if (v.size() == n) {
    ll sum = 0;
    REP(i,q) {
      if (v[b[i]] - v[a[i]] == c[i]) sum += d[i];
    }
    ans = max(ans,sum);
    return;
  }

  for (int i = las; i <= m; i++) {
    vector<int> nv = v;
    nv.push_back(i);
    dfs(nv, i);
  }
}

int main() {
  cin >> n >> m >> q;
  REP(i,q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }
  vector<int> v;
  dfs(v, 1);
  COUT(ans);
  return 0;
}
