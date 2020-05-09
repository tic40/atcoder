#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  string s; cin >> s;
  bool ok = true;

  if (s[0] != 'A') ok = false;
  int cnt=0;
  for (int i = 2; i < s.size()-1; i++) if (s[i] == 'C') cnt++;
  if (cnt != 1) ok = false;
  for (char c: s) {
    if (c=='A' || c == 'C') continue;
    if (isupper(c)) ok = false;
  }
  COUT(ok?"AC":"WA");
  return 0;
}
