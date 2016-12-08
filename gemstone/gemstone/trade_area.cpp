// ==========================================================================
//  Project : gemstone
//  File    : trade_area.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "trade_area.hpp"

using namespace std;

// istream constructor
TradeArea::TradeArea( istream& _is, CardFactory* _cardPool )
{
    char card;
    // get individual white space sperated tokens
    while( _is >> card ) // false when end of line or invalid input
    {
        d_cards.push_back( _cardPool->getPtr(card) );
    }
}

// adds the card to the trade area but it does not check if it is legal to place the card
TradeArea& TradeArea::operator+=( Card* _card)
{
    d_cards.push_back( _card );
    if(legal(_card))
    {
        d_types.push_back(_card->getName());
    }
    return *this;
}

// returns true if the card can be legally added to the TradeArea,
// i.e., a card of the same gemstone is already in the TradeArea
bool TradeArea::legal( Card* _card ) const
{
    for( auto cardInTrade : d_cards )
    {
        if( _card->getName() == cardInTrade->getName() ) return true;
    }
    return false;
}

// removes a card of the corresponding gemstone name from the trade area
Card* TradeArea::trade( const string _gemName )
{   // need to use iterators in order to know where to delete in list
    for( auto iter=d_cards.begin(); iter != d_cards.end(); ++iter )
    {
        if( (*iter)->getName() == _gemName ) // card is found with given name
        {
            Card* cardInTrade = *iter;
            d_cards.erase(iter);
            return cardInTrade;
        }
    }

    //instance when no such card is in TradeArea
    //cout << "No such card found in Trade Area!" << endl;
    return nullptr;
}

// returns the number of cards currently in the trade area
int TradeArea::numCards() const
{
    return d_cards.size();
}

// insertion operator to insert all the cards of the trade area to an ostream
ostream& operator<<( ostream& _os, const TradeArea& _tradeArea )
{
    for( auto cardInTrade : _tradeArea.d_cards )
    {
        cardInTrade->print( _os );
        _os << " ";
    }
    return _os;
}
