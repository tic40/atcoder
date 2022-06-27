#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; string s;
  cin >> n >> s;

  int addL = 0;
  int cnt = 0;
  REP(i,n) {
    if (s[i] == '(') cnt++;
    if (s[i] == ')') {
      if (0 < cnt) cnt--;
      else addL++;
    }
  }
  cout << string(addL, '(') + s + string(cnt, ')');
  return 0;
}
