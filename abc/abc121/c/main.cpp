#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

void show(vector<P> v) {
  REP(i,v.size()) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}

int main() {
  int n,m; cin >> n >> m;
  vector<P> x(n);
  int a,b;
  REP(i,n) { cin >> a >> b; x[i] = {a,b}; }

  sort(x.begin(), x.end());

  ll ans = 0;
  for (int i = 0; i < n && m > 0; i++) {
    int price = x[i].first;
    int num = x[i].second;

    ans += (ll)price * min(num, m);
    m-=num;
  }
  COUT(ans);
  return 0;
}
