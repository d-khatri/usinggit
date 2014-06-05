#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int> > v(50000);
int h(int n)
{
    return (n%50000);
}
main()
{
    int choice;
    int key;
    int hashval;
    for(int i=0;i<100;++i)
    {
        cin>>choice>>key;
        hashval=h(key);
        list<int>::iterator it=v[hashval].begin();
        switch(choice)
        {
        case 1:
            v[hashval].push_back(key);
            break;
        case 2:
            while(it!=v[hashval].end())
            {
                if(*it==key)
                {
                    v[hashval].erase(it);
                    break;
                }
                ++it;
            }
            if(it==v[hashval].end())
            {
                cout<<"element not present. cannot be deleted."<<endl;
            }
            break;
        case 3:
            while(it!=v[hashval].end())
            {
                if(*it==key)
                {
                    cout<<"element found!"<<endl;
                    break;
                }
                ++it;
            }
            if(it==v[hashval].end())
            {
                cout<<"element not present."<<endl;
            }
            break;
        }
    }
}
