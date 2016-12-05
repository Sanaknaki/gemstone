// ==========================================================================
//  Project : gemstone
//  File    : hand.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "hand.hpp"

using std::cout; using std::endl;

Hand::Hand() = default;

Hand::Hand( istream& _is, CardFactory* _cardPool )
{
    char card;
    // get individual white space seperated tokens
    while( _is >> card )  // false when end of line or invalid input
    {
        d_cards.push( _cardPool->getPtr(card) );
    }
}

Hand& Hand::operator+=( Card* _card )
{
    d_cards.push( _card );
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
        d_cards.pop();
        return playCard;
    }
}

Card* Hand::top() const
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
    queue<Card*> temp = _hand.d_cards; // copy d_cards from _hand to temp
    for( int i=0; i < temp.size(); i++ )
    {
        ( temp.front() )->print( _os ); // print to _os
        _os << " ";
        temp.push(temp.front()); // copy front card to back
        temp.pop(); // remove top card
    }
    return _os;
}

Card* Hand::operator[]( const int i )
{
    if( i >= d_cards.size() )
    {
        cout << "Given index is out of bounds!" << endl;
        return nullptr;
    } else {
        for( int index=0; index < d_cards.size(); index++ )
        {
            if( index == i  ) // if at given index in queue
            {
                return d_cards.front(); // save wanted Card to return
            } else {
                d_cards.push( d_cards.front() ); // push front card to back
            }
            d_cards.pop(); // remove front card
        }
    }
}
