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

<<<<<<< HEAD
Hand::Hand( istream& _is, CardFactory* _cardPool )
=======
Hand::Hand( istream& _is, CardFactor* _cardPool )
>>>>>>> dbc26af54eb2d972c0112ff2c39d0f2738e37986
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
<<<<<<< HEAD
    queue<Card*> temp = _hand.d_cards; // copy d_cards from _hand to temp
    for( int i=0; i < temp.size(); i++ )
    {
        ( temp.front() )->print( _os ); // print to _os
        _os << " ";
        temp.push(temp.front()); // copy front card to back
        temp.pop(); // remove top card
    }
=======
    queue<Card*> temp_d_cards;
    for( int i=0; !d_cards.empty(); i++ )
    {
        ( d_cards.front() )->print( _os ); // print to _os
        _os << " ";
        temp_d_cards.push(d_cards.front()); // store into temporary queue
        d_cards.pop(); // remove from current queue
    }
    d_cards = temp_d_cards;
>>>>>>> dbc26af54eb2d972c0112ff2c39d0f2738e37986
    return _os;
}

Card* Hand::operator[]( const int i ) const
{
    if( i >= d_cards.size() )
    {
        cout << "Given index is out of bounds!" << endl;
        return nullptr;
    } else {
<<<<<<< HEAD
        queue<Card*> temp = d_cards; // copy d_cards to temp
        for( int index=0; index < temp.size(); index++ )
        {
            if( index == i  ) // if at given index in queue
            {
                return temp.front(); // save wanted Card to return
            } else {
                temp.push( temp.front() ); // push front card to back
            }
            temp.pop(); // remove front card
        }
=======
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
>>>>>>> dbc26af54eb2d972c0112ff2c39d0f2738e37986
    }
}
