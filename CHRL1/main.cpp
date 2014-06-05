#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


template<template <typename> class P = std::less >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
        return P<T2>()(left.second, right.second);
    }
};

bool cmp( const Person a, const Person b )
{
    return a.age < b.age ;
}

int main()
{
    int i,j,tempweightsum,tempcostsum,t,n,k,costi,weighti;
    cin>>t;
    vector< pair<int,int> >input;
    vector<int>data;
    while(t--){

        data.clear();
        cin>>n>>k;

        for(i=0;i<n;i++){
            cin>>costi>>weighti;
            input.push_back(make_pair(costi,weighti));
        }

        sort(input.begin(),input.end(),compare_pair_second<>());

        cout<<input[0].second<<endl;

    }
    return 0;
}
