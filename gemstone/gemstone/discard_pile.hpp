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

#ifndef discard_pile_hpp
#define discard_pile_hpp

#include <stdio.h>
#include <vector>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::ostream; using std::istream;

class DiscardPile{

protected:

public:
    // a constructor which accepts an istream and reconstructs the DiscardPile from file.
    DiscardPile( const istream& _is, CardFactory* _cardPool );
    // discard the card to the pile
    DiscardPile& operator+=( Card* _card );
    // returns and removes the top card from the discard pile
    Card* pickUp();
    // returns but does not remove the top card from the discard pile
    Card* top();
    // insert all the cards in the DiscardPile to an std::ostream
    void print( ostream& _os);
};

#endif /* discard_pile_hpp */
