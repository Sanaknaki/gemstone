// ==========================================================================
//  Project : gemstone
//  File    : hand.hpp
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
#include <queue>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream; using std::ostream; using std::queue;

class Hand;

ostream& operator<<( ostream&, const Hand& );

class Hand {
    queue<Card*> d_cards;

protected:

public:
    // default constructor
    Hand();
    // Hand needs a constructor which accepts an istream and reconstructs the Hand from file.
    Hand( istream&, CardFactory* );
    // adds the card to the rear of the hand
    Hand& operator+=( Card* _card );
    // returns and removes the top card from the player's hand
    Card* play();
    // returns but does not remove the top card from the player's hand
    Card* top() const;
    // insertion operator to print Hand on an std::ostream
    // the hand should print all the cards in order
    friend ostream& operator<<( ostream&, const Hand& );
    // returns and removes the Card at a given index
    Card* operator[]( const int i );
};

#endif /* hand_hpp */
