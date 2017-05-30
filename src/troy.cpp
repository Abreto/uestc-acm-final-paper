/* Codeforces Hello 2015 (Div.2). Problem F-TROY Query, by Abreto <m@abreto.net> */
#include <cstdio>
#include <map>

using namespace std;

#define MAXN    100001
#define MAXT    (MAXN<<2)

typedef long long int ll;

int n = 0;
int nuniquexs = 0, nuniqueys = 0;   /* positive for rows, negative for cols. */
map<ll,int> real2virtual;
int par[MAXT];

#define R(x)    (2*(x)-1)
#define C(y)    (MAXT+2*(y))
#define nt(e)   ((e)+1)
void init_disjointsets(void)
{
    int i = 0;
    for(i = 0;i < (MAXN<<2);++i)
        par[i] = i;
}
int fdr(int i)
{
    return (i == par[i])?(i):(par[i] = fdr(par[i]));
}
int uni(int i, int j)
{
    return par[ fdr(i) ] = fdr(j);
}
int check(int i)
{
    return (fdr(i) == fdr(nt(i)));
}

int main(void)
{
    int i = 0;
    ll xi = 0, yi = 0;
    int vx = 0, vy = 0, axy = 0, bxy = 0;
    char failed = 0;
    scanf("%d", &n);
    init_disjointsets();
    for(i = 0;i < n;++i)
    {
        if( failed )
            printf("No\n");
        else
        {
            scanf("%I64d %I64d %d %d", &xi, &yi, &axy, &bxy);
            if( real2virtual.count(xi) )
                vx = real2virtual[xi];
            else
                vx = (real2virtual[xi] = ++nuniquexs);
            if( real2virtual.count(-yi) )
                vy = real2virtual[-yi];
            else
                vy = (real2virtual[-yi] = --nuniqueys);
            (axy == bxy)?
            (uni(R(vx),C(vy)), uni(nt(R(vx)),nt(C(vy)))):
            (uni(nt(R(vx)),C(vy)), uni(R(vx),nt(C(vy))));
            printf("%s\n", (check(R(vx))||check(C(vy)))?(failed=1,"No"):"Yes");
        }
    }
    return 0;
}
