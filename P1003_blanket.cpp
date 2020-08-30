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
    }
    int dotX, dotY;
    cin>>dotX>>dotY;
    cout<<numBlankets<<dotX<<dotY<<endl;
    return 0;
}