#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n),s(n+1);
  REP(i,n) cin >> a[i];
  REP(i,n) s[i+1] = s[i] + a[i];
  int q; cin >> q;
  REP(_,q) {
    int l,r; cin >> l >> r;
    l--; r--;
    int win = s[r+1] - s[l];
    int lose = r-l+1-win;
    if (win > lose) cout << "win";
    else if (win == lose) cout << "draw";
    else cout << "lose";
    cout << endl;
  }
  return 0;
}