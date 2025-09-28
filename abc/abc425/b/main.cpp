#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n), cnt(n);
  REP(i,n) {
    cin >> a[i]; a[i]--;
    if (a[i] >= 0) cnt[a[i]]++;
  }
  REP(i,n) if (a[i] < 0) {
    REP(j,n) if (cnt[j] == 0) {
      a[i] = j;
      cnt[j] = 1;
      break;
    }
  }
  for(auto v: cnt) if (v != 1) { cout << "No" << endl; return 0; }
  cout << "Yes" << endl;
  for(auto v: a) cout << v+1 << " ";
  return 0;
}