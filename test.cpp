#include<iostream>
using namespace std;
int n, m, cx, cy;
long long f[40][40], g[40][40];//注意尽量使用long long不然容易超出数据范围
int main()
{
    cin>>n>>m>>cx>>cy;
    f[0][0]=1;
    //以下考虑马的控制点有无越界
    g[cx][cy]=1;
    if(cx-1>=0&&cy-2>=0)g[cx-1][cy-2]=1;
    if(cx+1<=n&&cy-2>=0)g[cx+1][cy-2]=1;
    if(cx-2>=0&&cy-1>=0)g[cx-2][cy-1]=1;
    if(cx+2<=n&&cy-1>=0)g[cx+2][cy-1]=1;
    if(cx-2>=0&&cy+1<=m)g[cx-2][cy+1]=1;
    if(cx+2<=n&&cy+1<=m)g[cx+2][cy+1]=1;
    if(cx-1>=0&&cy+2<=m)g[cx-1][cy+2]=1;
    if(cx+1<=n&&cy+2<=m)g[cx+1][cy+2]=1;

    //以下为递推边界
    for(int i=1; i<=n; i++)
        if(!g[i][0])f[i][0]=f[i-1][0];
    for(int j=1; j<=m; j++)
        if(!g[0][j])f[0][j]=f[0][j-1];
    //以下为递推关系式，相对简单能想到
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(g[i][j])f[i][j]=0;
            if(!g[i][j])f[i][j]=f[i][j-1]+f[i-1][j];
        }
//调试代码所用
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)cout<<f[i][j]<<" ";
        cout<<endl;
    }
    cout<<f[n][m];
    return 0;
}