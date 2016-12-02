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

void Table::print( ostream& _os )
{

}

ostream& operator<<( ostream& _os, const Table )
{

}
