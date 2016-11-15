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

#ifndef trade_area_hpp
#define trade_area_hpp

#include <stdio.h>
#include <iostream>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream;

class TradeArea{
private:
    
public:
    TradeArea(const istream&,CardFactory*);
    TradeArea& operator+=(Card*);
    bool legal(Card*);
    Card trade(string);
    int numCards();
};

#endif /* trade_area_hpp */
