#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key, w;
  unsigned int pr;
  Node *l, *r;
  long long sum, pref, suff, best;
  Node(int k, int _w, unsigned int _pr) : key(k), w(_w), pr(_pr), l(nullptr), r(nullptr),
                                          sum(_w), pref(_w), suff(_w), best(_w) {}
};

const long long NEG = -4e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline long long gsum(Node *t) { return t ? t->sum : 0; }
inline long long gpref(Node *t) { return t ? t->pref : NEG; }
inline long long gsuff(Node *t) { return t ? t->suff : NEG; }
inline long long gbest(Node *t) { return t ? t->best : NEG; }

Node *merge(Node *a, Node *b);
void pull(Node *t)
{
  if (!t)
    return;
  Node *L = t->l, *R = t->r;
  long long ls = gsum(L), rs = gsum(R);
  long long lp = gpref(L), rp = gpref(R);
  long long lsuf = gsuff(L), rsuf = gsuff(R);
  long long lb = gbest(L), rb = gbest(R);
  t->sum = ls + t->w + rs;
  t->pref = max({lp, ls + t->w, ls + t->w + rp});
  t->suff = max({rsuf, rs + t->w, rs + t->w + lsuf});
  t->best = max({lb, rb, (long long)t->w, t->w + rp, lsuf + t->w, lsuf + t->w + rp});
}

void split(Node *t, int key, Node *&a, Node *&b)
{
  if (!t)
  {
    a = b = nullptr;
    return;
  }
  if (t->key < key)
  {
    split(t->r, key, t->r, b);
    a = t;
    pull(a);
  }
  else
  {
    split(t->l, key, a, t->l);
    b = t;
    pull(b);
  }
}

Node *merge(Node *a, Node *b)
{
  if (!a || !b)
    return a ? a : b;
  if (a->pr < b->pr)
  {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  }
  else
  {
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}

Node *insert(Node *t, Node *n)
{
  if (!t)
    return n;
  if (n->pr < t->pr)
  {
    split(t, n->key, n->l, n->r);
    pull(n);
    return n;
  }
  if (n->key < t->key)
    t->l = insert(t->l, n);
  else
    t->r = insert(t->r, n);
  pull(t);
  return t;
}

Node *erase_key(Node *t, int key)
{
  if (!t)
    return t;
  if (t->key == key)
  {
    Node *res = merge(t->l, t->r);
    return res;
  }
  if (key < t->key)
    t->l = erase_key(t->l, key);
  else
    t->r = erase_key(t->r, key);
  pull(t);
  return t;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
  {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<set<int>> pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      pos[a[i]].insert(i);
    }
    vector<Node *> root(n + 1, nullptr);
    vector<int> cur(n + 1, 0);
    multiset<int> best;
    for (int v = 1; v <= n; v++)
    {
      if (pos[v].size() >= 2)
      {
        auto it = pos[v].begin();
        int prev = *it;
        ++it;
        for (; it != pos[v].end(); ++it)
        {
          int nxt = *it;
          int gap = nxt - prev - 1;
          int w = 1 - gap;
          root[v] = insert(root[v], new Node(prev, w, rng()));
          prev = nxt;
        }
      }
      if (pos[v].empty())
      {
        cur[v] = 0;
      }
      else if (pos[v].size() == 1)
      {
        cur[v] = 1;
      }
      else
      {
        long long bw = root[v] ? root[v]->best : NEG;
        if (bw < 0)
          bw = 0;
        cur[v] = (int)(1 + bw);
      }
      if (cur[v] > 0)
        best.insert(cur[v]);
    }
    string out;
    while (q--)
    {
      int idx, x;
      cin >> idx >> x;
      int old = a[idx];
      if (old != x)
      {
        int v = old;
        if (cur[v] > 0)
          best.erase(best.find(cur[v]));
        {
          auto it = pos[v].find(idx);
          auto itPrev = (it == pos[v].begin()) ? pos[v].end() : prev(it);
          auto itNext = next(it);
          if (itPrev != pos[v].end())
          {
            root[v] = erase_key(root[v], *itPrev);
          }
          if (itNext != pos[v].end())
          {
            root[v] = erase_key(root[v], idx);
          }
          if (itPrev != pos[v].end() && itNext != pos[v].end())
          {
            int gap = *itNext - *itPrev - 1;
            int w = 1 - gap;
            root[v] = insert(root[v], new Node(*itPrev, w, rng()));
          }
          pos[v].erase(it);
        }
        if (pos[v].empty())
        {
          cur[v] = 0;
        }
        else if (pos[v].size() == 1)
        {
          cur[v] = 1;
          root[v] = nullptr;
        }
        else
        {
          long long bw = root[v] ? root[v]->best : NEG;
          if (bw < 0)
            bw = 0;
          cur[v] = (int)(1 + bw);
        }
        if (cur[v] > 0)
          best.insert(cur[v]);
        v = x;
        if (cur[v] > 0)
          best.erase(best.find(cur[v]));
        {
          auto it = pos[v].insert(idx).first;
          auto itPrev = (it == pos[v].begin()) ? pos[v].end() : prev(it);
          auto itNext = next(it);
          if (itPrev != pos[v].end() && itNext != pos[v].end())
          {
            root[v] = erase_key(root[v], *itPrev);
          }
          if (itPrev != pos[v].end())
          {
            int gap = idx - *itPrev - 1;
            int w = 1 - gap;
            root[v] = insert(root[v], new Node(*itPrev, w, rng()));
          }
          if (itNext != pos[v].end())
          {
            int gap = *itNext - idx - 1;
            int w = 1 - gap;
            root[v] = insert(root[v], new Node(idx, w, rng()));
          }
        }
        if (pos[v].size() == 1)
        {
          cur[v] = 1;
          root[v] = nullptr;
        }
        else
        {
          long long bw = root[v] ? root[v]->best : NEG;
          if (bw < 0)
            bw = 0;
          cur[v] = (int)(1 + bw);
        }
        if (cur[v] > 0)
          best.insert(cur[v]);
        a[idx] = x;
      }
      int ans = (*best.rbegin()) / 2;
      out += to_string(ans) + ' ';
    }
    cout << out << '\n';
  }
  return 0;
}
