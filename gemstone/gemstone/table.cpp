// ==========================================================================
//  Project : gemstone
//  File    : table.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "table.hpp"
#include <sstream>

using namespace std;

Table::Table( istream& _is, CardFactory* _cardPool )
{
    string line, token;
    // get a line from _is
    while( getline(_is, line) ) {
        istringstream streamLine( line );
        // get individual white space separated tokens
        while( streamLine >> token ) {
            // process token
            if( token == "Player1" ) {
                d_p1 = Player( _is, _cardPool );
                break;
            }
            if( token == "Player2" ) {
                d_p2 = Player( _is, _cardPool );
                break;
            }
            if( token == "DiscardPile" ) {
                d_discardPile = DiscardPile( streamLine, _cardPool );
                break;
            }
            if( token == "TradeArea" ) {
                d_tradeArea = TradeArea( streamLine, _cardPool );
                break;
            }
            if( token == "end" ) break;
            cout << "Unknown token!" << endl;
        }
        if( token == "end" ) break;
    }
}

bool Table::win(string& _name) const
{
    if( d_deck.empty() )
    {
        int p1_coins = d_p1.getNumCoins();
        int p2_coins = d_p2.getNumCoins();

        // check if it's a tie game
        if( p1_coins == p2_coins ) {
            _name = "Tie";
        } else if( p1_coins > p2_coins ) { // check if player1 is the winner
            _name = d_p1.getName(); // player1 is the winner
        } else {
            _name = d_p2.getName(); // player2 is the winner
        }
        return true;
    }
    return false;
}

/*
 *  prints the following to file as an example
 *  Player1
 *  Adam        4 coins
 *  Malachite   M M M M M
 *  Amethyst    A A
 *  Hand        A M Q R T R
 *  Player2
 *  Betty       7 coins
 *  Ruby        R R R R
 *  Quartz      Q Q Q Q Q Q Q
 *  Obsidian    O O O O O
 *  Hand        M A T T A M
 *  DiscardPile A O Q T R M M T Q O E H Q T E M A
 *  TradeArea   O E A E E A O O A O O E E A A A A O
 *  end
 */
void Table::print( ostream& _os ) const
{
    _os << "Player1 " << endl << d_p1; // output player1
    d_p1.printHand( _os, true ); // output player1 hand
    _os << "Player2 " << endl << d_p2; // output player2
    d_p2.printHand( _os, true ); // output player2 hand
    _os << "DiscardPile ";
    d_discardPile.print(_os); // output discardPile
    _os << "TradeArea" << d_tradeArea << endl; // output tradeArea
    _os << "end"; // output end of file
}

ostream& operator<<( ostream& _os, const Table& _table )
{
    _os << "Player 1" << endl << _table.d_p1; // displays player 1
    _os << "Player 2" << endl << _table.d_p2; // displays player 2
    _os << "Trading Area" << endl << _table.d_tradeArea; // displays trade area
    _os << "Discard Pile" << endl << _table.d_discardPile; // displays top card of discard pile
    return _os;
}
