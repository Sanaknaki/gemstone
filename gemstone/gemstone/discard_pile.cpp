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
/*
=======

using std::cout; using std::endl;

<<<<<<< HEAD
DiscardPile::DiscardPile( istream& _is, CardFactory* _cardPool)
=======
>>>>>>> 027a0b0cdf747fa7a0619888fc2d24b123178b26
DiscardPile::DiscardPile( const istream& _is, CardFactory* _cardPool)
>>>>>>> dbc26af54eb2d972c0112ff2c39d0f2738e37986
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
<<<<<<< HEAD
    
=======
    d_cards.push_back( _card );
    return *this;
>>>>>>> 027a0b0cdf747fa7a0619888fc2d24b123178b26
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
*/

void DiscardPile::print( ostream& _os ) const
{
    for( auto card : d_cards )
    {
        card->print( _os );
    }
}

<<<<<<< HEAD
ostream& operator<<( ostream& _os, const DiscardPile& _discardPile )
{
    _discardPile.d_cards.back()->print( _os );
    return _os;
}
=======
/*operator<<( ostream& _os, const DiscardPile& _discardPile )
{
    //output to ostream
}*/
>>>>>>> dbc26af54eb2d972c0112ff2c39d0f2738e37986
