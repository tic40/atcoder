#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  string s;
  cin >> n >> s;

  REP(i,n) {
    if (s[i] == '0') continue;

    if (i%2 == 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    break;
  }

  return 0;
}