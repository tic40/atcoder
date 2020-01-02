#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  string s;
  cin >> s;
	regex po("(ch|o|k|u)+");
  cout << regex_match(s, po) << endl;
	cout << (regex_match(s, po) ? "YES" : "NO") << endl;
}