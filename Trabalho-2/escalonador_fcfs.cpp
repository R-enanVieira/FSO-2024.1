#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
typedef vector<int> vi;
#define pb push_back
#define ln "\n"

typedef struct {
  int m;
  vector<int> instr;
} process;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  process p[n + 1];
  queue<int> q;

  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    p[i].m = m;
    q.push(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= p[i].m; j++) {
      int I;
      cin >> I;
      p[i].instr.pb(I);
    }
  }

  int ans = 0;
  vector<int> index(n + 1, 0);

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    int i = index[current];

    while (1) {
      if (i == p[current].instr.size()) {
        cout << current << " (" << ans << ")" << ln;
        break;
      }
      if (p[current].instr[i] == 1) {
        p[current].instr[i] = 0;
        index[current] = i;
        q.push(current);
        break;
      }
      ans += 10;
      i++;
    }
  }

  return 0;
}
