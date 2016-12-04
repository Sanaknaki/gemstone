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

class Deck : public vector<Card*> {
    /*vector<Card*> d_original;
    vector<Card*> d_playable;*/
public:

    // Deck increment operator.
    Deck& operator+=(ostream&);

    // Remove and return top card from deck.
    Card* draw();

    // Add card to the deck.
    void add(Card* _card);

    /***************************
     *  See deck.cpp for details
     ***************************
    // Check if the deck is empty.
    bool isEmpty();

    // Shuffle the deck.
    void shuffle();
    */
};


#endif /* deck_hpp */
