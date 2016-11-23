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

#include "trade_area.hpp"

TradeArea::TradeArea( const istream& _is, CardFactory* _cardPool )
{
    //read from file
}

TradeArea& TradeArea::operator+=( Card* _card)
{
    d_cards.push_back( _card );
    return *this;
}

bool TradeArea::legal( Card* _card )
{
    for( auto card : d_cards )
    {
        if( _card->getName() == card->getName() )
        {
            return true;
        }
    }
    return false;
}

Card* TradeArea::trade( string _gemName )
{
    Card* cardInTrade = nullptr; //default return if no such card is in TradeArea
    for( auto iter=d_cards.begin(); iter != d_cards.end(); ++iter )
    {
        if( _gemName == (*iter)->getName() )
        {
            cardInTrade = *iter;
            d_cards.erase(iter);
            return cardInTrade;
        }
    }

    //instance when no such card is in TradeArea
    cout << "No such card found in Trade Area!" << endl;
    return cardInTrade;
}

int TradeArea::numCards()
{
    return d_cards.size();
}

ostream& operator<<( ostream& _os, const TradeArea tradeArea )
{
    // output to file
}
