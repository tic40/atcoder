#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  string s; cin >> s;
  int l=0, r=s.size()-1, ans=0;

  while(1) {
    if (r <= l) break;

    if (s[l] == s[r]) { l++; r--; }
    else if (s[l] == 'x') { l++; ans++; }
    else if (s[r] == 'x') { r--; ans++; }
    else { ans = -1; break; }
  }

  cout << ans << endl;
  return 0;
}