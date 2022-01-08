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
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  ll ans = 0;

  int ma = min(a,k);
  ans += ma;
  k-=ma;

  int mb = min(b,k);
  k-=mb;

  int mc = min(c,k);
  ans += mc*-1;
  COUT(ans);
  return 0;
}
