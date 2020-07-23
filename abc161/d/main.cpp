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
  int k; cin >> k;
  vector<ll> ans;
  queue<ll> q;

  for (int i = 1; i<10; i++) q.push(i);

  while(!q.empty()) {
    if (ans.size() > k) break;
    ll n = q.front(); q.pop();
    ans.push_back(n);

    if (f > 0) q.push(n*10+(f-1));
    q.push(n*10+f);
    if (f < 9) q.push(n*10+f+1);
  }

  COUT(ans[k-1]);
  return 0;
}










  /*
  int k; cin >> k;
  vector<ll> a;
  for (int i=1; i<=9; i++) a.push_back(i);
  while(1) {
    if (k <= a.size()) { cout << a[k-1] << endl; return 0; }
    k-=a.size();
    vector<ll> old;
    swap(old,a);
    for (ll x : old) {
      for (int i = -1; i<=1; i++) {
        int d = x%10+i;
        if (d < 0 || d > 9) continue;
        ll nx = x*10 + d;
        a.push_back(nx);
      }
    }
  }
  */
}