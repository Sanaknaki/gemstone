// ==========================================================================
//  Project : gemstone
//  File    : discard_pile.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef discard_pile_hpp
#define discard_pile_hpp

#include <iostream>
#include <vector>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::ostream; using std::istream; using std::vector;

class DiscardPile;

ostream& operator<<( ostream&, const DiscardPile& );

class DiscardPile
{
    vector<Card*> d_cards;
    
public:
    // default constructor
    DiscardPile(){};
    
    // istream constructor
    DiscardPile( istream& _is, CardFactory* _cardPool );
    
    // discard the card to the discard pile
    DiscardPile& operator+=( Card* _card );
    
    // returns and removes the top card from the discard pile
    Card* pickUp();
    
    // returns but does not remove the top card from the discard pile
    Card* top() const;
    
    // inserts all the cards in the DiscardPile to an ostream
    void print( ostream& _os) const;
    
    // insertion operator to insert only the top card of the discard pile to an ostream
    friend ostream& operator<<( ostream&, const DiscardPile& );
};

#endif /* discard_pile_hpp */
