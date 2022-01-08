#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n; cin >> n;
  string s; int t;
  vector<pair<int, string>> pa(n);

  REP(i,n) {
    cin >> s >> t;
    pa[i] = {t,s};
  }

  sort(pa.rbegin(), pa.rend());
  cout << pa[1].second << endl;
  return 0;
}