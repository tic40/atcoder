#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n;
void f(int i, int l, string s) {
  if (l < 0) return;
  if (i == n) {
    if (l == 0) cout << s << endl;
    return;
  }

  f(i+1, l+1, s+'(');
  f(i+1, l-1, s+')');

  return;
}

int main() {
  cin >> n;
  f(1,1,"(");
  return 0;
}