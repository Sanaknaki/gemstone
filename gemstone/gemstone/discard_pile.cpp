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

#include "discard_pile.hpp"

using std::cout; using std::endl;

DiscardPile::DiscardPile( const istream& _is, CardFactory* _cardPool)
{
    //read from file
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

Card* DiscardPile::top()
{
    if( d_cards.empty() )
    {
        cout << "Discard Pile is empty!";
        return nullptr;
    } else {
        return d_cards.back();
    }
}

void DiscardPile::print( ostream& _os )
{
    for( auto card : d_cards )
    {
        _os << ;
    }
}
