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
    queue<Card*> temp_d_cards;
    for( int i=0; !d_cards.empty(); i++ )
    {
        ( d_cards.front() )->print( _os ); // print to _os
        temp_d_cards.push(d_cards.front()); // store into temporary queue
        d_cards.pop(); // remove from current queue
    }
    d_cards = temp_d_cards;
    return _os;
}

Card* Hand::operator[]( int i )
{
    if( i >= d_cards.size() )
    {
        cout << "Given index is out of bounds!" << endl;
        return nullptr;
    } else {
        queue<Card*> temp_d_cards; // store popped Cards to temporary queue
        for( int index=0; !d_cards.empty(); i++ )
        {
            if( index == i  ) // if at given index in queue
            {
                Card* cardAtIndex = d_cards.front(); // save wanted Card to return
            } else {
                temp_d_cards.push(d_cards.front()); // push front to temp queue
            }
            d_cards.pop(); // remove Card from current queue
        }
        d_cards = temp_d_cards;
        return cardAtIndex;
    }
}
