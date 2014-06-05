#include <iostream>
using namespace std;


void calculateP(int* start,int *finish,int* compatible){
compatible[1]=0;


}


int main()
{
    int n,i,j;
    int *starttime,*finishtime,*profit,*lastcompatible,*meomarray;
    cin>>n;

    starttime=new int[n+1];
    finishtime=new int[n+1];
    profit = new int[n+1];
    lastcompatible = new int[n+1];
    meomarray = new int[n+1];

    for(i=1;i<=n;i++)cin>>starttime[i]>>finishtime[i]>>profit[i];

    calclulateP(starttime,finishtime,lastcompatible);
    //make vector of <pair_a,<pair_ba,pair_bb>>
    // a finsih time ba start time and bb profit and sort it by first value and then find compatiblity !


    return 0;
}
