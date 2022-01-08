#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

vector<int> x(4);
string s;

bool check() {
  int ok = false;
  REP(i,3) if (x[0] != x[i+1]) ok = true;

  if (ok) {
    ok = false;
    REP(i,3) if ( (x[i]+1) % 10 != x[i+1] ) ok = true;
  }
  return ok;
}

int main() {
  cin >> s;
  REP(i,4) x[i] = s[i] - '0';

  cout << (check() ? "Strong" : "Weak") << endl;
  return 0;
}