#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  string s;
  cin >> s;
  cout << (regex_match(s, regex("(dream(er)?|eraser?)+")) ? "YES" : "NO") << endl;
}
