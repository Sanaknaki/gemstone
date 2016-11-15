// ==========================================================================
//  Project : gemstone
//  File    : card-hierarchy.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream; using std::vector;

class Hand{
    vector<Card*> d_cards;
    
private:

public:
    Hand(const istream&,CardFactory*);
    virtual ~Hand();
    Hand& operator+=(Card* _card);
    Card* play();
    Card* top();
    Card* operator[](int i);
};

#endif /* hand_hpp */
