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