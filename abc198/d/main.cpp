#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

vector<string> s(3);

void solve() {
  set<char> st;
  for(char c: s[0]+s[1]+s[2]) st.insert(c);
  if (10 < st.size()) { cout << "UNSOLVABLE" << endl; return; }

  int i = 0;
  map<char, int> m;
  for(char c: st) { m[c]=i; i++; }

  vector<ll> nums(10);
  iota(nums.begin(), nums.end(), 0);
  do {
    bool skip = nums[ m[s[0][0]] ] == 0 || nums[m[s[1][0]] ] == 0 || nums[m[s[2][0]] ] == 0;
    if (skip) continue;

    vector<ll> ns(3,0);
    REP(i,3) {
      for (char c: s[i]) ns[i] = ns[i]*10+nums[m[c]];
    }
    if (ns[0]+ns[1] == ns[2]) {
      REP(i,3) cout << ns[i] << endl;
      return;
    }
  } while (next_permutation(nums.begin(), nums.end()));

  cout << "UNSOLVABLE" << endl;
  return;
}

int main() {
  REP(i,3) cin >> s[i];
  solve();

  return 0;
}