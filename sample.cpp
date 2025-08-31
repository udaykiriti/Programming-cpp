#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
static const int MAXN = 200000 + 5;

int n;
vector<int> adj[MAXN], adj2[MAXN];
pair<int, int> edges[MAXN];

int parent1[MAXN], subtree1[MAXN], tin[MAXN], tout[MAXN], diffArr[MAXN], smallCount[MAXN];
int timer1;

int subtree3[MAXN], parent3[MAXN], idx3[MAXN], order3[MAXN], order3_sz, nodes_tprime, root_tprime;

bool used3[MAXN];
int group_id[MAXN], color_ans[MAXN];
vector<vector<int>> groups;

void solve()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    adj[i].clear();
  for (int i = 1; i < n; i++)
  {
    int u, v; cin >> u >> v;
    edges[i] = {u, v};
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  timer1 = 0;
  for (int i = 1; i <= n + 1; i++)
    diffArr[i] = 0;
  struct Item
  {
    int v, p, idx;
  };
  vector<Item> st;
  st.reserve(n);
  st.push_back({1, 0, 0});
  parent1[1] = 0;
  while (!st.empty())
  {
    auto &it = st.back();
    int v = it.v, p = it.p;
    if (it.idx == 0)
    {
      parent1[v] = p;
      subtree1[v] = 1;
      tin[v] = ++timer1;
    }
    if (it.idx < (int)adj[v].size())
    {
      int u = adj[v][it.idx++];
      if (u == p)
        continue;
      st.push_back({u, v, 0});
    }
    else
    {
      tout[v] = timer1;
      if (p != 0)
      {
        int sz = subtree1[v];
        int oth = n - sz;
        if (sz <= oth)
        {
          diffArr[tin[v]]++;
          diffArr[tout[v] + 1]--;
        }
        else
        {
          diffArr[1]++;
          diffArr[n + 1]--;
          diffArr[tin[v]]--;
          diffArr[tout[v] + 1]++;
        }
        subtree1[p] += subtree1[v];
      }
      st.pop_back();
    }
  }

  for (int i = 1; i <= n; i++)
    diffArr[i] += diffArr[i - 1];
  for (int v = 1; v <= n; v++)
    smallCount[v] = diffArr[tin[v]];

  long long bestL = LLONG_MAX;
  int A = 1, B = 2;
  for (int i = 1; i < n; i++)
  {
    int x = edges[i].first;
    int y = edges[i].second;
    int a = min(x, y), b = max(x, y);
    int compB;
    if (parent1[b] == a)
      compB = subtree1[b];
    else
      compB = n - subtree1[a];
    int oth = n - compB;
    int orig_min = min(compB, oth);
    bool b_in_small = (compB <= oth);
    long long L = (long long)orig_min + smallCount[b] - (b_in_small ? 1 : 0);
    if (L < bestL)
    {
      bestL = L;
      A = a;
      B = b;
    }
  }

  nodes_tprime = n - 1;
  root_tprime = A;
  for (int i = 1; i <= n; i++)
    adj2[i].clear();

  for (int v = 1; v <= n; v++)
  {
    if (v == B)
      continue;
    for (int u : adj[v])
    {
      if (u == B)
        continue;
      adj2[v].push_back(u);
    }
  }

  for (int u : adj[B])
  {
    if (u == A)
      continue;
    adj2[A].push_back(u);
    adj2[u].push_back(A);
  }

  order3_sz = 0;
  for (int i = 1; i <= n; i++)
  {
    idx3[i] = 0;
    parent3[i] = -1;
  }

  parent3[root_tprime] = 0;
  vector<int> stack3;
  stack3.reserve(nodes_tprime);
  stack3.push_back(root_tprime);
  while (!stack3.empty())
  {
    int v = stack3.back();
    if (idx3[v] < (int)adj2[v].size())
    {
      int u = adj2[v][idx3[v]++];
      if (u == parent3[v])
        continue;
      parent3[u] = v;
      stack3.push_back(u);
    }
    else
    {
      stack3.pop_back();
      order3[order3_sz++] = v;
    }
  }

  for (int i = 0; i < order3_sz; i++)
  {
    int v = order3[i];
    subtree3[v] = 1;
    for (int u : adj2[v])
    {
      if (u == parent3[v])
        continue;
      subtree3[v] += subtree3[u];
    }
  }

  int cent2 = root_tprime, bestHeavy = nodes_tprime;
  for (int idx = 0; idx < order3_sz; idx++)
  {
    int v = order3[idx];
    int heavy = nodes_tprime - subtree3[v];
    for (int u : adj2[v])
    {
      if (u == parent3[v])
        continue;
      heavy = max(heavy, subtree3[u]);
    }
    if (heavy < bestHeavy)
    {
      bestHeavy = heavy;
      cent2 = v;
    }
  }

  for (int i = 1; i <= n; i++)
    used3[i] = false;
  used3[B] = true;
  used3[cent2] = true;

  groups.clear();
  groups.push_back(vector<int>(1, cent2));
  int gid = 1;
  for (int u : adj2[cent2])
  {
    if (used3[u]) continue;
    groups.push_back(vector<int>());
    stack<int> q;
    q.push(u);
    used3[u] = true;
    while (!q.empty())
    {
      int v = q.top();
      q.pop();
      groups[gid].push_back(v);
      for (int w : adj2[v])
      {
        if (!used3[w])
        {
          used3[w] = true; q.push(w);
        }
      }
    }
    gid++;
  }

  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < (int)groups.size(); i++)
  {
    if (!groups[i].empty())
      pq.push({(int)groups[i].size(), i});
  }

  for (int i = 1; i <= n; i++)
    color_ans[i] = 0;
  color_ans[B] = 0;

  int cur_color = 1;
  while (pq.size() > 1)
  {
    auto p1 = pq.top(); pq.pop();
    auto p2 = pq.top(); pq.pop();
    int i1 = p1.second, i2 = p2.second;
    int v1 = groups[i1].back();
    groups[i1].pop_back();
    int v2 = groups[i2].back();
    groups[i2].pop_back();
    color_ans[v1] = cur_color;
    color_ans[v2] = cur_color;
    cur_color++;
    if (!groups[i1].empty())
      pq.push({(int)groups[i1].size(), i1});
    if (!groups[i2].empty())
      pq.push({(int)groups[i2].size(), i2});
  }

  int u_out = A, v_out = B;
  if (max(u_out, v_out) != B)
    swap(u_out, v_out);
  cout << u_out << " " << v_out << "\n";
  for (int i = 1; i <= n; i++)
    cout << color_ans[i] << (i == n ? '\n' : ' ');
}

int main() {
  ios_base::sync_with_stdio(fasle);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}