#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> s(n);
  REP(i,m) {
    int l,r; cin >> l >> r; l--; r--;
    s[l]++; s[r+1]--;
  }
  REP(i,n-1) s[i+1] += s[i];
  cout << *min_element(s.begin(),s.end()) << endl;
  return 0;
}