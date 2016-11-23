// ==========================================================================
//  Project : gemstone
//  File    : card-hierarchy.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include <vector>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream; using std::ostream; using std::vector;

class Hand;

ostream& operator<<( ostram&, const Hand& );

class Hand {
    vector<Card*> d_cards;

protected:

public:
    // Hand needs a constructor which accepts an istream and reconstructs the Hand from file.
    Hand( const istream&, CardFactory* );
    virtual ~Hand();
    // adds the card to the rear of the hand
    Hand& operator+=( Card* _card );
    // returns and removes the top card from the player's hand
    Card* play();
    // returns but does not remove the top card from the player's hand
    Card* top();
    // insertion operator to print Hand on an std::ostream
    // the hand should print all the cards in order
    friend ostream& operator<<( ostream&, const Hand& );
    // returns and removes the Card at a given index
    Card* operator[]( int i );
};

#endif /* hand_hpp */
