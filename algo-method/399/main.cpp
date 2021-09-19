#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  vector<int> sw = w;
  sort(sw.begin(),sw.end());
  REP(i,n) {
    auto it = lower_bound(sw.begin(),sw.end(),w[i]);
    cout << it - sw.begin() << endl;
  }
  return 0;
}