#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  int ans = 0;
  REP(i,n) for(int l = 1; l <= (n-1-i)/2; l++) {
    int j = i+l;
    int k = j+l;
    if (s[i] == 'A' && s[j] == 'B' && s[k] == 'C') ans++;
  }
  cout << ans << endl;
  return 0;
}
