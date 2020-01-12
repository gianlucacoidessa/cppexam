#include "bst.h"
#include <utility>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <map>

int main(int argc,char *argv[])
{
    int N,i,k;
    if(argc!=2) std::cout<<"Insert proper number of args. Give the number N of nodes"<<std::endl;
    std::srand(std::time(nullptr));
    std::vector<int> v;
    bst<int,int> albero{};
    std::map<int,int> mappa{};
    N = std::atoi(argv[1]);
    
    for(i=0;i<N;++i)
    {
        k= std::rand() % 100; //to print small numbers
        v.push_back(k);
        albero.emplace(k,k);
        mappa.emplace(k,k);
    }
    
    //print tree
    //std::cout<<"This is the tree just created with "<<N<< " nodes"<<std::endl;
    //std::cout << "Random values:";
    //for(auto x : v) std::cout<<x<<" ";
    //std::cout<<std::endl;
    //std::cout<<" " ::endl;
    //std::cout << "Tree: " << albero << std::endl;
    
    //std::cout<<"Elapsed time non balance tree"<<std::endl;
    //time resolution
    for(i=0;i<10;++i)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        albero.find(i);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto elaps = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1);
        std::cout /*<<"Elapsed "*/<< elaps.count() /*<< " [ns]"*/<< std::endl;
    }
    
    //std::cout<<"Balancing tree..."<<std::endl;
    albero.balance();
    //std::cout<<"Elapsed time balance tree"<<std::endl;

    std::cout<<" "<<std::endl;
    
    for(i=0;i<10;++i)
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        albero.find(i);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto elaps = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1);
        std::cout /*<<"Elapsed "*/<< elaps.count() /*<< " [ns]"*/<< std::endl;
    }
    std::cout<<" "<<std::endl;
    //std::cout<<"Elapsed time balance tree with std::map"<<std::endl;
    for(i=0;i<10;++i)
     {
         auto t1 = std::chrono::high_resolution_clock::now();
         mappa.find(i);
         auto t2 = std::chrono::high_resolution_clock::now();
         auto elaps = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1);
         std::cout <</*"Elapsed "<<*/ elaps.count() /*<< " [ns]"*/<< std::endl;
     }
    
    albero.clear();
    return 0;
    
}

