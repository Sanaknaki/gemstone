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

class CardFactory {
    // Variable.
    vector<Card*> d_cards;
    // store different cards in a vector
    static const vector<Card*> GEMSTONES;

public:
    // Constructor.
    CardFactory();

    // Returns pointer to the only instance of CardFactory.
    static CardFactory* getFactory();

    // Returns deck with all 104 cards, [Shuffle it in the Deck class].
    Deck getDeck();

    // return Card pointer according to given char
    Card* getPtr( const char ) const;

    // deconstructor
    ~CardFactory();
};

#endif /* cardfactory_hpp */
