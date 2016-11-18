// ==========================================================================
//  Project : gemstone
//  File    : deck.hpp
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

#include "gemstones.hpp"

using std::istream; using std::vector;

class Deck{
    vector<Card*> d_original;
    vector<Card*> d_playable;
public:
    Deck();
    //~Deck();
    Deck& operator+=(ostream&);
    Card* draw();
    void add(Card* _card);
    bool isEmpty();
    void shuffle();
};


#endif /* deck_hpp */
