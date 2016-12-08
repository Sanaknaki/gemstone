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
    string line, token, temp;
    // get a line from _is
    while( getline(_is, line) ) {
        istringstream streamLine( line );
        // get individual white space separated tokens
        while( streamLine >> token ) {
            // process token
            if( token == "Player1" ) {
                d_p1 = *new Player( _is, _cardPool );
                break;
            }
            if( token == "Player2" ) {
                d_p2 = *new Player( _is, _cardPool );
                break;
            }
            if( token == "TradeArea" ) {
                streamLine >> temp;
                d_tradeArea = TradeArea( streamLine, _cardPool );
                break;
            }
            if( token == "DiscardPile" ) {
                streamLine >> temp;
                d_discardPile = DiscardPile( streamLine, _cardPool );
                break;
            }
            if( token == "Deck" ) {
                streamLine >> temp;
                d_deck = Deck( streamLine, _cardPool );
                break;
            }
            if( token == "end" ) break;
            cout << "Unknown token!" << endl;
        }
        if( token == "end" ) break;
    }
}

bool Table::win(string& _name) const
{   // check if deck is empty
    if( d_deck.empty() )
    {
        int p1_coins = d_p1.getNumCoins();
        int p2_coins = d_p2.getNumCoins();

        // check if it's a tie game
        if( p1_coins == p2_coins ) _name = "Tie";

        // check if player1 is the winner
        else if( p1_coins > p2_coins ) _name = d_p1.getName(); // player1 is the winner
        else _name = d_p2.getName(); // player2 is the winner
        return true;
    }
    return false;
}

/*
 *  prints the following to file as an example
 *  Player1
 *  Name: Adam
 *  Coin(s): 4
 *  Chains
 *  0 -  Malachite : M M M M M
 *  1 - Amethyst : A A
 *  Hand : A M Q R T R
 *
 *  Player2
 *  Name: Betty
 *  Coin(s): 7
 *  Chains
 *  0 - Ruby : R R R R
 *  1 - Quartz : Q Q Q Q Q Q Q
 *  2 - Obsidian : O O O O O
 *  Hand : M A T T A M

 *  TradeArea : O E A E E A O O A O O E E A A A A O
 *  DiscardPile : A O Q T R M M T Q O E H Q T E M A
 *  Deck : etc...
 *  end
 */
void Table::print( ostream& _os ) const
{
    _os << "Player1 " << endl << d_p1; // output player1
    _os << "Hand : "; d_p1.printHand( _os, true ); _os << endl; // output player1 hand
    _os << endl;
    _os << "Player2 " << endl << d_p2; // output player2
    _os << "Hand : "; d_p2.printHand( _os, true ); _os << endl; // output player2 hand
    _os << endl;
    _os << "TradeArea : " << d_tradeArea << endl; // output tradeArea
    _os << "DiscardPile : "; d_discardPile.print(_os); _os << endl; // output discardPile
    _os << "Deck : " << d_deck << endl; // output deck
    _os << "end"; // output end of file
}

ostream& operator<<( ostream& _os, const Table& _table )
{
    _os << "Player 1" << endl << _table.d_p1 << endl; // displays player 1
    _os << "Player 2" << endl << _table.d_p2 << endl; // displays player 2
    _os << "Trading Area: " << _table.d_tradeArea << endl; // displays trade area
    _os << "Discard Pile: " << _table.d_discardPile << endl; // displays top card of discard pile
    return _os;
}
