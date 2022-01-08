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
  int a,b;
  string s;
  cin >> a >> b >> s;
  int i = 0;
  int ok = true;
  REP(i,s.size()) {
    char c = s[i];
    if (i == a) {
      if (c != '-') ok = false;
    } else {
      int cn= c-'0';
      if (cn < 0 || cn > 9) ok = false;
    }
  }
  COUT(ok ? "Yes" : "No");
  return 0;
}
