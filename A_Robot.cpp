#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int D = 1005;
char c[N][D];
bool vis[N][D];
int dis[N][D];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int ci, int cj)
{
    if (ci < 1 || ci > n || cj < 1 || cj > m)
    {
        return false;
    }
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int aa = par.first;
        int bb = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = aa + d[i].first;
            int cj = bb + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && c[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[aa][bb] + 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(n, m);

    int k;
    cin >> k;
    vector<int>s(k);
    multiset<int>ss;
    for (int i = 0; i < k; i++)
    {
        int si, sj;
        cin >> si >> sj;
        s[i]=dis[si][sj];
        if(s[i] != -1)
        {
           ss.insert(s[i]);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        t--;
        if (s[t] != -1) {
            auto it = ss.find(s[t]);
            if (it != ss.end()) 
            {
                ss.erase(it);
            }
        }
        
        if(ss.empty())
        {
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<*ss.begin()<<endl;
        }
        if(s[t] !=-1)
        {
            ss.insert(s[t]);
        }

    }

    
    
    return 0;
}
