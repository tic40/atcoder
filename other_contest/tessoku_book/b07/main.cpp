#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int t,n; cin >> t >> n;
  vector<int> s(t+1);
  REP(i,n) {
    int l,r; cin >> l >> r;
    s[l]++;
    s[r]--;
  }
  REP(i,t) s[i+1] += s[i];
  REP(i,t) cout << s[i] << endl;
  return 0;
}