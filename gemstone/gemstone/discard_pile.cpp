// ==========================================================================
//  Project : gemstone
//  File    : discard_pile.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "discard_pile.hpp"

using namespace std;

// istream constructor
DiscardPile::DiscardPile( istream& _is, CardFactory* _cardPool)
{
    char card;
    // get individual white space seperated tokens
    while( _is >> card ) // false when end of line or invalid input
    {
        d_cards.push_back( _cardPool->getPtr(card) );
    }
}

// discards the card to the discard pile
DiscardPile& DiscardPile::operator+=( Card* _card )
{
    d_cards.push_back( _card );
    return *this;
}

// returns and removes the top card from the discard pile
Card* DiscardPile::pickUp()
{   // check if discard pile is not empty
    if( !d_cards.empty() )
    {   // store last Card, pop last Card, return stored Card
        Card* pickUpCard = d_cards.back();
        d_cards.pop_back();
        return pickUpCard;
    }
    // returns null if discard pile is empty
    return nullptr;
}

// returns but does not remove the top card from the discard pile
Card* DiscardPile::top() const
{   // check if discard pile is not empty
    if( !d_cards.empty() ) return d_cards.back();
    // return null if discard pile is empty
    return nullptr;
}

// inserts all the cards in the DiscardPile to an ostream
void DiscardPile::print( ostream& _os ) const
{
    for( auto card : d_cards ) {
        card->print( _os );
        _os << " ";
    }
}

// insertion operator to insert only the top card of the discard pile to an ostream
ostream& operator<<( ostream& _os, const DiscardPile& _discardPile )
{
    Card* topCard = _discardPile.top();
    if( topCard != nullptr ) topCard->print( _os );
    return _os;
}
