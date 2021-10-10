#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N];
int b[N];
LL cnt[N], pre[N], suf[N];
int main()
{
    int T, n, c, i;
    LL sum, min_c;
    freopen("80days.in","r",stdin);
    freopen("80days.out","w",stdout);
    cin >> T;
    while(T--)
    {
        min_c = LL(INF) * INF;
        cin >> n >> c;
        for(i=1;i<=n;i++)
            scanf("%d", &a[i]);
        sum = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &b[i]);
            a[i] -= b[i];
            sum += a[i];
            cnt[i] = sum;
            if(cnt[i] < min_c)
            {
                min_c = cnt[i];
            }
            pre[i] = min_c;
            //debug(cnt[i]);
        }
        min_c = LL(INF) * INF;
        for(i=n;i;i--)
        {
            if(cnt[i] < min_c)
            {
                min_c = cnt[i];
            }
            suf[i] = min_c;
        }
        suf[n+1] = LL(INF) * INF;
        pre[0] = LL(INF) * INF;
        if(c + sum < 0)
            printf("-1\n");
        else
        {
            i = n;
            if(suf[i+1]+c >= cnt[i] && pre[i-1] + c + sum - cnt[i] >= 0)
                {
                    printf("%d\n", i%n + 1);
                    continue;
                }
            for(i=1;i<n;i++)
            {
                if(suf[i+1]+c >= cnt[i] && pre[i-1] + c + sum - cnt[i] >= 0)
                {
                    printf("%d\n", i%n + 1);
                    break;
                }
            }
        }
    }
    return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*
2
3 0
3 4 5
5 4 3
3 1
3 4 5
5 5 3

1
16 14
20 12 10 9 3 11 -4 -4 12 17 6 4 2 9 15 0
10 7 8 1 8 0 5 4 6 2 5 1 10 1 3 2

1
2 0


*/
