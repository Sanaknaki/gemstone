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

using namespace std;

// istream constructor
Hand::Hand( istream& _is, CardFactory* _cardPool )
{
    char card;
    // get individual white space seperated tokens
    while( _is >> card )  // false when end of line or invalid input
    {
        d_cards.push( _cardPool->getPtr(card) );
    }
}

// adds the card to the rear of the hand
Hand& Hand::operator+=( Card* _card )
{
    d_cards.push( _card );
    return *this;
}

// returns and removes the top card from the player's hand
Card* Hand::play()
{   // check if Hand is empty
    if( d_cards.empty() ) cout << "You have no cards in your hand!" << endl;
    else
    {   // store top card, pop top card, return stored card
        Card* playCard = d_cards.front();
        d_cards.pop();
        return playCard;
    }
    // returns null if Hand is empty
    return nullptr;
}

// returns but does not remove the top card from the player's hand
Card* Hand::top() const
{   // check if Hand is empty
    if( d_cards.empty() ) cout << "You have no cards in your hand!" << endl;
    else return d_cards.front();
    // returns null if Hand is empty
    return nullptr;
}

// Insertion operator to print Hand on an ostream.
// The hand should print all the cards in order.
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

// returns and removes the Card at a given index
Card* Hand::operator[]( const int i )
{
    Card* cardAtIndex = nullptr;
    if( i >= d_cards.size() || i < 0 ) cout << "Given index is out of bounds!" << endl;
    else
    {
        for( int index=0; index <= d_cards.size(); index++ )
        {   // if at given index in queue
            if( index == i  ) cardAtIndex = d_cards.front(); // store Card
            else d_cards.push( d_cards.front() ); // copy front card to back
            d_cards.pop(); // remove front card
        }
    }
    // returns null if index is out of bounds
    return cardAtIndex;
}
