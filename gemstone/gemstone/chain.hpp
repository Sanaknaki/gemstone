// ==========================================================================
//  Project : gemstone
//  File    : chain.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef chain_h
#define chain_h

#include <stdio.h>
#include <vector>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream; using std::ostream; using std::vector; using std::cout; using std::endl;

template <class T>
class Chain{
private:
    vector<Card*> d_cards;
public:
    
    Chain(){}
    
    Chain<T>& operator+=( Card* _card)
    {
        string chainType = typeid(T).name();
        string cardType  = typeid(*_card).name();
        
        if(chainType != cardType)
        {
            cout << "Chain and Card are not the same gem type!" << endl;
        }else { d_cards.push_back(_card); return this; }
    }
    
    int sell()
    {
        return (int)((new T)->getCardsPerCoin((d_cards.size())));
    }
    
    Chain(const istream& in, CardFactory* cFactory())
    {
        // No clue how to implement this, coming back to it later.
    }
    
    
};

    /*vector<Card*> d_cards;
    int size() = 0;
    void print(ostream&) = 0;
public:
    Chain()
    {
        
    }
    
    Chain(const istream&, CardFactory* cardFactory)
    {
        
    }
    
    Chain<T>& operator+=(Card* _card)
    {
        string chainType = typeid(T).name();
        string cardType  = typeid(*_card).name();
        
        if(chainType != cardType)
        {
            cout << "Chain and Card are not the same gem type!" << endl;
        }else{
            d_cards.push_back(_card);
            return this;
        }
    }
    
    int sell()
    {
        return(int)(new T)->getCoinsPerCard((d_cards.size()));
    }
};*/

#endif /* chain_h */
