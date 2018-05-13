#include <iostream>
#include <map>
#include <string>
using namespace std;

void show(pair<int,string> temp)
{
   
    cout<<temp.first<<"   "<<temp.second<<endl;
}
int main()
{
    // for_each,  insert , make_pare
    multimap<int, string> mmap;

    for (int i=0;i<10;i++)
    {
        mmap.insert(make_pair(i,"hello"));
    }
    for_each(mmap.begin(), mmap.end(), show);
    multimap<int, string>::iterator it;
    //count
    if(mmap.count(12))
    {
        cout<<"True";
    }
    else
        cout<<"False";
    cout<<endl;
    
    // equal_range()
    pair<std::multimap<int,string>::iterator, std::multimap<int,string>::iterator> pops;
    pops=mmap.equal_range(5);
    cout<<pops.first->first<<" "<<pops.first->second<<endl;
    cout<<pops.second->first<<" "<<pops.second->second;
    // erase()
    multimap<int, string> mini;
    
    for(multimap<int, string>::iterator p=mmap.begin();p!=mmap.end();p++)
    {
        mini.insert(make_pair(p->first,p->second));
    }
    
    
    for_each(mini.begin(), mini.end(), show);
    int z=0;
    while (z<7)
    {
        mini.erase(z);
        z++;
    }
    cout<<endl;
    for_each(mini.begin(), mini.end(), show);
    // find () // pair<>
    mini.erase(mini.find(7));
    cout<<endl;
    for_each(mini.begin(), mini.end(), show);\
    pair<int, string> k(9,"hello");
    pair<int, string> p(10,"Privet");
    mini.insert(k);
    mini.insert(p);
    for_each(mini.begin(), mini.end(), show);
    //swap
    mini.swap(mmap);
    for_each(mini.begin(), mini.end(), show);
    for_each(mmap.begin(), mmap.end(), show);
}
