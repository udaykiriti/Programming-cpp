
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define input1(x) cin >> x
#define input2(x, y) cin >> x >> y
#define output(x) cout << x << endl
#define fi first
#define se second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;

// --- Fast IO ---
void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main()
{
  FastIO();
  int n; cin>>n;
  vector<psi> rounds;
  msi scores;

  FOR(i, 0, n)
  {
    string name;
    int score;
    cin>>name>>score;
    rounds.pb({name, score});
    scores[name] += score;
  }

  int max_score = INT_MIN;
  for (auto &entry : scores)
  {
    max_score = max(max_score, entry.se);
  }

  msi running_score;
  for (auto &round : rounds)
  {
    string name = round.fi;
    int score = round.se;
    running_score[name] += score;
    if (scores[name] == max_score && running_score[name] >= max_score)
    {
      cout<<name<<endl;
      break;
    }
  }

  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define pb push_back
// #define all(x) x.begin(), x.end()
// #define FOR(i, a, b) for (int i = a; i < b; ++i)
// #define input1(x) cin >> x
// #define input2(x, y) cin >> x >> y
// #define output(x) cout << x << endl

// void FastIO()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
// }

// int main()
// {
//   FastIO();
//   int n;
//   input1(n);

//   vector<pair<string, int>> rounds;
//   map<string, int> scores;

//   FOR(i, 0, n)
//   {
//     string name;
//     int score;
//     input2(name, score);
//     rounds.pb({name, score});
//     scores[name] += score;
//   }

//   int max_score = -1e9;
//   for (auto &entry : scores)
//   {
//     if (entry.second > max_score)
//       max_score = entry.second;
//   }

//   map<string, int> running_score;
//   for (auto &round : rounds)
//   {
//     string name = round.first;
//     int score = round.second;
//     running_score[name] += score;
//     if (scores[name] == max_score && running_score[name] >= max_score)
//     {
//       output(name);
//       break;
//     }
//   }

//   return 0;
// }
