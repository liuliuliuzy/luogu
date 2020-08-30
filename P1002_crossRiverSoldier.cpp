#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int my(int xb, int yb, int xm, int ym){
    vector< vector<int> > dp(xb+1, vector<int>(yb+1, 0));
    // cout<<dp.size()<<dp[0].size()<<endl;
    int dis[8][2] = {{2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    if(xm<=xb && xm>=0 && ym<=yb && ym>=0){
        dp[xm][ym] = -1;
    }
    for(int i=0; i<8; i++){
        int newX = xm+dis[i][0];
        int newY = ym+dis[i][1];
        if(newX<=xb && newX>=0 && newY<=yb && newY>=0){
            dp[newX][newY] = -1;
        }
    }
    dp[0][0] = 1;
    for(int i=1; i<xb+1; i++){
        if(dp[i][0] == -1){
            dp[i][0] = 0;
            continue;
        }
        dp[i][0] = dp[i-1][0];
    }
    for(int i=1; i<yb+1; i++){
        if(dp[0][i] == -1){
            dp[0][i] = 0;
            continue;
        }
        dp[0][i] = dp[0][i-1];
    }
    //for check
    // for(int i=0; i<dp.size(); i++){
    //     for(int j=0; j<dp[0].size(); j++){
    //         if(dp[i][j] < 0){
    //             cout<<dp[i][j];
    //         } 
    //         else {
    //             cout<<" "<<dp[i][j];
    //         }
    //     }
    //     cout<<endl;
    // }
    for(int i=1; i<xb+1; i++){
        for(int j=1; j<yb+1; j++){
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[xb][yb];
    // for(int i=0; i<dp.size(); i++){
    //     for(int j=0; j<dp[0].size(); j++){
    //         if(dp[i][j] < 0){
    //             cout<<dp[i][j];
    //         } 
    //         else {
    //             cout<<" "<<dp[i][j];
    //         }
    //     }
    //     cout<<endl;
    // } 
}

//动态规划，解决网格中存在障碍时的路径条数
int main()
{
    int xb, yb, xm, ym;
    cin>>xb>>yb>>xm>>ym;
    vector< vector<long long> > dp(xb+1, vector<long long>(yb+1, 0));
    // cout<<dp.size()<<dp[0].size()<<endl;
    int dis[8][2] = {{2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    if(xm<=xb && xm>=0 && ym<=yb && ym>=0){
        dp[xm][ym] = -1;
    }
    for(int i=0; i<8; i++){
        int newX = xm+dis[i][0];
        int newY = ym+dis[i][1];
        if(newX<=xb && newX>=0 && newY<=yb && newY>=0){
            dp[newX][newY] = -1;
        }
    }
    dp[0][0] = 1;
    for(int i=1; i<xb+1; i++){
        if(dp[i][0] == -1){
            dp[i][0] = 0;
            continue;
        }
        dp[i][0] = dp[i-1][0];
    }
    for(int i=1; i<yb+1; i++){
        if(dp[0][i] == -1){
            dp[0][i] = 0;
            continue;
        }
        dp[0][i] = dp[0][i-1];
    }
    //for check
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            if(dp[i][j] < 0){
                cout<<dp[i][j];
            } 
            else {
                cout<<" "<<dp[i][j];
            }
        }
        cout<<endl;
    }
    for(int i=1; i<xb+1; i++){
        for(int j=1; j<yb+1; j++){
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[xb][yb]<<endl;
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            if(dp[i][j] < 0){
                cout<<dp[i][j];
            } 
            else {
                cout<<" "<<dp[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}