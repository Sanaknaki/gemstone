// ==========================================================================
//  Project : gemstone
//  File    : table.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef table_hpp
#define table_hpp

#include <iostream>

#include "cardfactory.hpp"
#include "players.hpp"
#include "discard_pile.hpp"
#include "trade_area.hpp"

using std::string; using std::ostream; using std::istream;

class Table;

ostream& operator<<( ostream&, const Table& );

class Table
{
    Player d_p1, d_p2;
    Deck d_deck;
    DiscardPile d_discardPile;
    TradeArea d_tradeArea;

public:
    // default constructor
    Table(){};

    // accepts an istream and reconstruct the Table from file
    Table( istream&, CardFactory* );

    /*
     *  Returns true when a player has won.
     *  Conditions are as follows:
     *  - deck is empty
     *  - player with the most card wins
    */
    bool win( string& _name ) const;

    // Prints the complete table with all content.
    // Intended for serialization to file.
    void print( ostream& _os) const;

    /*
     *  Insertion operator to print a Table to an ostream.
     *  The two players, the discardpile, the trading area should be printed.
     *  This is the top level print out. Note that a complete output with all
     *  cards for the pause functionality is printed with the separate function print above.
    */
    friend ostream& operator<<( ostream&, const Table& );
};

#endif /* table_hpp */
