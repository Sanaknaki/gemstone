// ==========================================================================
//  Project : gemstone
//  File    : deck.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include <vector>

#include "gemstones.hpp"

using std::istream; using std::vector;

class Deck : vector<Card*> {
    /*vector<Card*> d_original;
    vector<Card*> d_playable;*/
public:
    Deck();
    //~Deck();
    Deck& operator+=(ostream&);
    Card* draw(); // Return and removes top card
    void add(Card* _card); // Add cards to the deck
    bool isEmpty(); // Check if deck is empty;
    void shuffle(); // Shuffle the deck
};


#endif /* deck_hpp */
