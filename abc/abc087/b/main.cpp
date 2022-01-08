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
  int a,b,c,x;
  cin >> a >> b >> c >> x;

  ll ans = 0;
  REP(i,a+1) {
    REP(j,b+1) {
      int diff = x - (500*i + 100*j);
      if (diff < 0) continue;
      if (diff % 50 == 0 && diff / 50 <= c) ans++;
    }
  }
  COUT(ans);
  return 0;
}
