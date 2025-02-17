#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int bit = 0b1111;
  if (s == "sick") bit &= 0b0011;
  else bit &= ~(0b0011);
  if (t == "sick") bit &= 0b0101;
  else bit &= ~(0b0101);

  REP(i,4) if (bit>>i & 1) { cout << i+1 << endl; break; }
  return 0;
}
