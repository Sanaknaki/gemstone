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

TradeArea::TradeArea( istream& _is, CardFactory* _cardPool )
{
    char tmp, card;
    // get individual white space sperated tokens
    while( _is >> card ) // false when end of line or invalid input
    {
        d_cards.push_back( _cardPool->getPtr(card) );
    }
}

TradeArea& TradeArea::operator+=( Card* _card)
{
    d_cards.push_back( _card );
    return *this;
}

bool TradeArea::legal( Card* _card ) const
{
    for( auto cardInTrade : d_cards )
    {
        if( _card->getName() == cardInTrade->getName() )
        {
            return false;
        }
    }
    return true;
}

Card* TradeArea::trade( const string _gemName )
{
    // need to use iterators in order to know where to delete in list
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
    cout << "No such card found in Trade Area!" << endl;
    return nullptr;
}

int TradeArea::numCards() const
{
    return d_cards.size();
}

ostream& operator<<( ostream& _os, const TradeArea& _tradeArea )
{
    for( auto cardInTrade : _tradeArea.d_cards )
    {
        cardInTrade->print( _os );
        _os << " ";
    }
    return _os;
}
