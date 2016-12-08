// ==========================================================================
//  Project : gemstone
//  File    : trade_area.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef trade_area_hpp
#define trade_area_hpp

#include <iostream>
#include <list>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream; using std::ostream; using std::list; using std::string;

class TradeArea;

ostream& operator<<( ostream&, const TradeArea& );

class TradeArea
{
    list<Card*> d_cards;

public:
    // types of cards in TradeArea
    vector<string> d_types;

    // default constructor
    TradeArea(){};

    // istream constructor
    TradeArea( istream& _is, CardFactory* _cardPool );

    // adds the card to the trade area but it does not check if it is legal to place the card
    TradeArea& operator+=( Card* _card );

    // adds to type vector if given card is unique
    void addToType( Card* _card );

    // returns true if the card can be legally added to the TradeArea,
    // i.e., a card of the same gemstone is already in the TradeArea
    bool legal( Card* _card ) const;

    // removes a card of the corresponding gemstone name from the trade area
    Card* trade( const string _gemName );

    // returns the number of cards currently in the trade area
    int numCards() const;

    // insertion operator to insert all the cards of the trade area to an ostream
    friend ostream& operator<<( ostream&, const TradeArea& );
};

#endif /* trade_area_hpp */
