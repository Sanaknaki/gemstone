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

using std::cout; using std::endl;

DiscardPile::DiscardPile() = default;

DiscardPile::DiscardPile( istream& _is, CardFactory* _cardPool)
{
    char card;
    // get individual white space seperated tokens
    while( _is >> card ) // false when end of line or invalid input
    {
        d_cards.push_back( _cardPool->getPtr(card) );
    }
}

DiscardPile& DiscardPile::operator+=( Card* _card )
{
    d_cards.push_back( _card );
    return *this;
}

Card* DiscardPile::pickUp()
{
    if( d_cards.empty() )
    {
        cout << "Discard Pile is empty!";
        return nullptr;
    } else {
        Card* pickUpCard = d_cards.back();
        d_cards.pop_back();
        return pickUpCard;
    }
}

Card* DiscardPile::top() const
{
    if( d_cards.empty() )
    {
        cout << "Discard Pile is empty!";
        return nullptr;
    } else {
        return d_cards.back();
    }
}

void DiscardPile::print( ostream& _os ) const
{
    for( auto card : d_cards )
    {
        card->print( _os );
    }
}

ostream& operator<<( ostream& _os, const DiscardPile& _discardPile )
{
    _discardPile.d_cards.back()->print( _os );
    return _os;
}
