#include <iostream>
#include <algorithm>
using namespace std;

int calanswer(int *arrival,int *departure,int num){
    int i,j,in,out,savedata[num],counter,maxarrival,mindeparture,maxarrivalcounter,mindeparturecounter;
    for(i=0;i<num;i++){
        maxarrival=-1;mindeparture=1001;in=arrival[i]; out=departure[i];

        maxarrival= *max_element(arrival,arrival+num);
        mindeparture= *min_element(departure,departure+num);

        for(j=0,maxarrivalcounter=1;j<num,j!=i;j++){
            if(arrival[j]<=maxarrival && maxarrival<departure[j]) maxarrivalcounter++;
        }

        for(j=0,mindeparturecounter=1;j<num,j!=i;j++){
            if(arrival[j]<mindeparture && mindeparture<=departure[j]) mindeparturecounter++;
        }

        savedata[i]=max(maxarrivalcounter,mindeparturecounter);
    }
    return *max_element(savedata,savedata+num);
}

int main()
{
    int t,n,*arr,*dept,i,answer;
    cin>>t;
    while(t--){
        cin>>n;

        arr=new int[n];
        dept=new int[n];

        for(i=0;i<n;i++){
            cin>>arr[i];
        }

        for(i=0;i<n;i++){
            cin>>dept[i];
        }
        answer=calanswer(arr,dept,n);
        cout<<answer<<endl;
    }
    return 0;
}
