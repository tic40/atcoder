#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();

  double ans = 0;
  REP(i,n) if (s[i] == 't') {
    int cnt = 1;
    for(int j = i+1; j < n; j++) if (s[j] == 't') {
      cnt++;
      if (j-i+1-2 > 0) ans = max(ans, (double)(cnt-2)/(j-i+1-2));
    }
  }
  printf("%.10f\n",ans);
  return 0;
}