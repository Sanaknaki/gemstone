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

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include <vector>

#include "cardfactory.hpp"
#include "gemstones.hpp"

using std::istream;

class Deck{
private:

public:
    //Deck(const istream&,CardFactory*);
    ~Deck();
    Deck& operator+=(ostream&);
    Card* draw();
};


#endif /* deck_hpp */
