#include "bst.h"
#include <utility>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "Built tree" << endl;
    bst<int,int> tree;
    std::pair<bst<int,int>::iterator,bool> tt = tree.insert({8,8});
    tt = tree.insert({3,3});
    tt = tree.insert({10,10});
    tt = tree.insert({1,1});
    tt = tree.insert({6,6});
    tt = tree.insert({14,14});
    tt = tree.insert({4,4});
    tt = tree.insert({7,7});
    tt = tree.insert({100,100});
    
    for(auto x : tree) cout << "Key value: " << x.first << endl;
          cout << "Tree: " << tree << endl;
    
    tree.balance();
    for(auto x : tree) cout << "Key value: " << x.first << endl;
       cout << "Tree: " << tree << endl;
    tree.clear();

    
    


    return 0;
    
}

