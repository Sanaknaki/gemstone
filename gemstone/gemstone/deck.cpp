// ==========================================================================
//  Project : gemstone
//  File    : deck.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "deck.hpp"

using namespace std;

// constructor using given vector
Deck::Deck( const vector<Card*>& _cards ) : vector( _cards ) {}

// istream constructor
Deck::Deck( istream& _is, CardFactory* _cardPool )
{
    char card, temp;
    _is >> temp; // temp should store ':'
    // get individual white space seperated tokens
    while( _is >> card )  // false when end of line or invalid input
    {
        this->push_back( _cardPool->getPtr(card) );
    }
}

// Draw card form the deck.
Card* Deck::draw()
{   // Initial size check.
    if(this->size() < 0)
    {
        // Return.
        cout << "ERR : Deck is empty! " << endl;
        return nullptr;
    }
    else
    {   // Set top card, remove, return it.
        Card* top = this->back();
        this->pop_back();
        return top;
    }
}

// insertion operator
ostream& operator<<( ostream& _os, const Deck& _deck )
{
    for( auto card : _deck ) {
        card->print(_os); _os << " ";
    }
    return _os;
}
