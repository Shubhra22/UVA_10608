
#include <iostream>
#include <queue>
#define Max 30005

using namespace std;
int par[Max];
int ans[Max];
int kount, Num_of_graph;
priority_queue<int> pq;

void makeSet(int n)
{
    par[n] = n;
    ans[n] = 1;
}

int Find(int x)
{
    if(par[x] == x) return  x;
    par[x] = Find(par[x]);
    return par[x];
}

void Union(int x, int y)
{
    int u = Find(x);
    int v = Find(y);
    if(u!=v)
    {
        par[u] = v;
        ans[v]+= ans[u];
        //Num_of_graph--;
    }
}
int main(int argc, const char * argv[])
{
    int t_case;
    int N, M,f1,f2;
    cin >> t_case;
    while (t_case--)
    {
        kount = 0;
        cin >> N >> M;
        Num_of_graph = N;
        for (int i = 1; i <= N; i++)
        {
            makeSet(i);
        }
        while (M--)
        {
            cin >> f1 >>f2;
            Union(f1, f2);
            
        }
        int max = 0;
        for (int i = 1; i <= N; i++)
        {
            if (max < ans[i])
            {
                max = ans[i];
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
