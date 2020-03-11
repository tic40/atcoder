#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int n[100];
int main() {
  string s; cin >> s;
  for (char c : s) {
    n[c-'a']++;
    if (n[c-'a'] > 1) { cout << "no" << endl; return 0; }
  }
  cout << "yes" << endl;
  return 0;
}
