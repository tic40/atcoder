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

string S;
int K,N;
set<string> ans;

void dfs(string s, int i) {
  if (s.size() > K || i >= N) { ans.insert(s); return; }
  dfs(s+S[i],i+1);
  if (!s.empty()) ans.insert(s);
}

int main() {
  cin >> S >> K;
  N = S.size();

  REP(i,N) {
    string s;
    dfs(s, i);
  }

  auto it = ans.begin();
  REP(i,K-1) it++;
  COUT(*it);
  return 0;
}