#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int main()
{
    int numBlankets;
    vector< vector<int> > blankets;
    cin>>numBlankets;
    for(int i=0; i<numBlankets; i++){
        int x, y, xLen, yLen;
        cin>>x>>y>>xLen>>yLen;
        vector<int> tmpItem = {x, y, xLen, yLen};
        blankets.push_back(tmpItem);
    }
    int dotX, dotY;
    cin>>dotX>>dotY;
    cout<<numBlankets<<dotX<<dotY<<endl;
    int ans = -1;
    for(int i=0; i<numBlankets; i++){
        if(blankets[i][0]<=dotX && blankets[i][0]+blankets[i][2]>=dotX && blankets[i][1]<=dotY && blankets[i][1]+blankets[i][3]>=dotY){
            ans = i+1;
        }
    }
    cout<<ans;
    return 0;
}