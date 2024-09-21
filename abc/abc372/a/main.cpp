#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string n; cin >> n;
  for(auto c: n) if (c != '.') cout << c;
  return 0;
}