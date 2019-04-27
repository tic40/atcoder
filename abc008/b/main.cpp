#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, maxVote = 0;
  string _, result;
  map <string, int> score;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> _;
    score[_] = score[_] ? score[_] + 1 : 1;
  }

  for (auto i = score.begin(); i != score.end(); ++i) {
    if (maxVote < i->second) {
      maxVote = i->second;
      result = i->first;
    }
  }
  cout << result << "\n";
}