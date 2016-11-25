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

>>>>>>> 027a0b0cdf747fa7a0619888fc2d24b123178b26
DiscardPile::DiscardPile( const istream& _is, CardFactory* _cardPool)
{
    //read from file
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
*/

void DiscardPile::print( ostream& _os )
{
    for( auto card : d_cards )
    {
        card->print( _os );
    }
}

/*operator<<( ostream& _os, const DiscardPile& _discardPile )
{
    //output to ostream
}*/
