// ==========================================================================
//  Project : gemstone
//  File    : cardfactory.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef cardfactory_hpp
#define cardfactory_hpp

#include <stdio.h>

#include "deck.hpp"
#include "gemstones.hpp"

using std::vector;

class Deck;

class CardFactory
{
    vector<Card*> d_cards;

    // store only instance of cards in a static vector
    static vector<Card*> GEMSTONES;

public:
    // constructor
    CardFactory();

    // returns pointer to the only instance of CardFactory
    static CardFactory* getFactory();

    // returns deck with all 104 cards
    Deck getDeck();

    // return Card pointer according to given char
    Card* getPtr( const char ) const;

    // deconstructor
    ~CardFactory();
};

#endif /* cardfactory_hpp */
