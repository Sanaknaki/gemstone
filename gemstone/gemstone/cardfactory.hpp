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

#ifndef cardfactory_hpp
#define cardfactory_hpp

#include <stdio.h>

#include "deck.hpp"

class CardFactory{
private:

public:
    static CardFactory* getFactory();
    //Deck getDeck();
};

#endif /* cardfactory_hpp */
