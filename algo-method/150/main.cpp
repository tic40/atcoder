#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s = "0011010010";
  REP(i,s.size()) {
    if (s[i] == '1') {
      cout << s.size() - 1 - i << endl;
      break;
    }
  }
  return 0;
}