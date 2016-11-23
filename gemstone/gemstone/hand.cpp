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

#include "hand.hpp"

using std::cout; using std::endl;

Hand::Hand( const istream& _is, CardFactor* _cardPool )
{
    // read from file
}

Hand& Hand::operator+=( Card* _card )
{
    d_cards.push_back( _card );
    return *this;
}

Card* Hand::play()
{
    if( d_cards.empty() )
    {
        cout << "You have no cards in your hand!" << endl;
        return nullptr;
    } else {
        Card* playCard = d_cards.front();
        d_cards.erase(d_cards.begin());
        return playCard;
    }
}

Card* Hand::top()
{
    if( d_cards.empty() )
    {
        cout << "You have no cards in your hand!" << endl;
        return nullptr;
    } else {
        return d_cards.front();
    }
}

ostream& operator<<( ostream& _os, const Hand& _hand )
{
    for( auto card : _hand.d_cards )
    {
        //print card
    }
}

Card* Hand::operator[]( int i )
{
    if( i >= d_cards.size() )
    {
        cout << "Given index is out of bounds!" << endl;
        return nullptr;
    } else {
        Card* cardAtIndex = d_cards[i];
        d_cards.erase(d_cards.begin()+i);
        return cardAtIndex;
    }
}
