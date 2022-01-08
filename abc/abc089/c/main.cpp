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

char c[] = {'M','A','R','C','H'};

int main() {
  int n; cin >> n;
  string s;
  map<char,int> m;

  REP(i,n) { cin >> s; m[s[0]]++; }

  ll ans = 0;
  for (ll bit = 0; bit < (1<<5); bit++) {
    if (__builtin_popcount(bit) != 3) continue;
    ll sum = 1;
    REP (i,5) {
      if (bit >> i & 1) sum*=m[c[i]];
    }
    ans+=sum;
  }
  COUT(ans);
  return 0;
}
