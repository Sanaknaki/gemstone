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

#ifndef discard_pile_hpp
#define discard_pile_hpp

#include <stdio.h>
#include <vector>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::ostream; using std::istream;

class DiscardPile{
private:
    
public:
    DiscardPile(const istream&,CardFactory*);
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void print(ostream&);
};

#endif /* discard_pile_hpp */
