#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  ll n,k; cin >> n >> k;
  vector<pair<int, int>> q;

  REP(i,n) {
    int a,b; cin >> a >> b;
    q.push_back(make_pair(a,b));
  }

  sort(q.begin(), q.end());
  ll sum = 0;
  REP(i,n) {
    sum+=q[i].second;
    if (k <= sum) { cout << q[i].first << endl; return 0; }
  }
  return 0;
}
