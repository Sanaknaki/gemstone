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

using std::out_of_range; // using std::random_shuffle;
using std::cout; using std::endl;

// istream constructor
Deck::Deck( istream& _is, CardFactory* _cardPool )
{
    char card;
    // get individual white space seperated tokens
    while( _is >> card )  // false when end of line or invalid input
    {
        (this*).push( _cardPool->getPtr(card) );
    }
}

// Draw card form the deck.
Card* Deck::draw()
{
    // Initial size check.
    if(this->size() < 0)
    {
        // Return.
        cout << "ERR : Deck is empty! " << endl;
        return nullptr;
    }else{

        // Set top card, remove, return it.
        Card* top = this->back();
        (*this).pop_back();
        return top;
    }
    /*if(d_playable.empty())
    {
        out_of_range("The deck is empty!");
    }

    Card* top(d_playable.back());
    d_playable.pop_back();
    return top;*/
}

// Add card to the deck.
void Deck::add(Card*_card)
{
    // Push back card to deck.
    (*this).push_back(_card);
    /*d_original.push_back(_card);
    d_playable.push_back(_card);*/
}

// insertion operator
ostream& operator<<( ostream& _os, const Deck& _deck )
{
    for( auto card : _deck ) {
        card->print(_os);
    }
    return _os;
}

/*****************************************************
 *  Since Deck extends vector, no need for this method
 *****************************************************
// Check if the deck is empty.
bool Deck::isEmpty()
{
    // Condition.
    if(this->empty())
    {
        // Return.
        return true;
    }

    // Return.
    return false;

    /*if(d_playable.empty())
    {
        return true;
    }

    return false;
}
*/

/**************************************************
 *  Moved shuffle function to inside of CardFactory
 **************************************************
// Shuffle the deck.
void Deck::shuffle()
{
    // Check if the deck is empty.
    if(!this->empty())
    {
        // Shuffle it.
        random_shuffle(this->begin(), this->end());
    }else{

        // Error.
        cout << "ERR : Cannot shuffle an empty deck!" << endl;
    }
}
*/
