// ==========================================================================
//  Project : gemstone
//  File    : card-hierarchy.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "table.hpp"

using std::cout; using std::endl;

Table::Table( istream& _is, CardFactory* _cardPool )
{
    // read from istream
}

bool Table::win(string& _name)
{
    if( d_deck.isEmpty() )
    {
        cout << _name << " is the winner!" << endl;
        return true;
    }
    return false;
}

/*
 *  prints the following to file as an example
 *  Player 1
 *  Adam        4 coins
 *  Malachite   M M M M M
 *  Amethyst    A A
 *  Hand        A M Q R T R
 *  Player 2
 *  Betty       7 coins
 *  Ruby        R R R R
 *  Quartz      Q Q Q Q Q Q Q
 *  Obsidian    O O O O O
 *  Hand        M A T T A M
 *  DiscardPile A O Q T R M M T Q O E H Q T E M A
 *  TradeArea   O E A E E A O O A O O E E A A A A O
 *  end
 */
void Table::print( ostream& _os )
{
    _os << "Player 1 " << endl << d_p1;
    d_p1.printHand( _os, true );
    _os << "Player 2 " << endl << d_p2;
    d_p2.printHand( _os, true );
    _os << "DiscardPile " << d_discardPile << endl;
    _os << "TradeArea" << d_tradeArea << endl;
    _os << "end";
}

ostream& operator<<( ostream& _os, const Table )
{
    _os << "Player 1" << endl << d_p1; // displays player 1
    _os << "Player 2" << endl << d_p2; // displays player 2
    _os << "Trading Area" << endl << d_tradeArea; // displays trade area
    _os << "Discard Pile" << endl << d_discardPile; // displays top card of discard pile
    return _os;
}
