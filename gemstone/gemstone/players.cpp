// ==========================================================================
//  Project : gemstone
//  File    : players.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "players.hpp"
#include <string>

using namespace std;

// default constructor
Player::Player() = default;

// Constructor.
Player::Player(string& _name) : d_name( _name ) {}

// Return the name of the player.
string Player::getName() const
{
    return d_name;
}

// Return the amount of coins a player has.
int Player::getNumCoins() const
{
    return d_coin;
}

// Add coins to a player.
Player& Player::operator+=(int _coin)
{
    this->d_coin += _coin;
    return *this;
}

// Get the max number of chains.
int Player::getMaxNumChains() const
{
    return d_chains.size();
}

// Get the number of chains a player has.
// counts how many elements are not nullptr in d_chains
// execution takes O(1) time
int Player::getNumChains() const
{
    int numChains = 0;
    for( auto chainRef : d_chains ) {
        if( chainRef != 0 ) ++numChains;
    }
    return numChains;
}

// Return chain at position i.
// vector throws out_of_bounds exception if invalid index is given
Chain_Base& Player::operator[]( int i )
{
    return *( d_chains.at(i) );
}

// Buy a third chain if possible.
void Player::buyThirdChain()
{
    if(d_coin >= 3 && d_chains.size() == 2)
    {
        d_coin -=3;
        d_chains.push_back(nullptr);
        cout << this->d_name << " has bought their 3rd chain!" << endl;
    }else if(d_coin < 3)
    {
        cout << "ERROR : Not enough coins to buy the chain!" << endl;
    }else if(d_chains.size() == 3)
    {
        cout << "ERROR : You already have 3 chains!" << endl;
    }
}

// Print top card or full hand of player.
void Player::printHand( ostream& _os, const bool fullHand ) const
{
    if( !fullHand ) { // prints top card only
        Card* topCard = d_hand.top();
        topCard->print( _os );
    } else { // prints all of d_hand
        _os << d_hand;
    }
}

/*
 *  Insertion operator to print a Player to an std::ostream.
 *  The player's name, the number of coins in the player's possession and each
 *  of the chains (2 or 3, some possibly empty) should be printed. Note that the
 *  Hand is printed with a separate function above.
 */
ostream& operator<<( ostream& _os, const Player& _p )
{
    // print name and number of coins
    _os << _p.d_name << "\t\t" << _p.d_coin << "coin";
    if( _p.d_coin != 1 ) _os << "s";
    _os << endl;
    // print chains
    /*for( auto chain : _p.d_chains ) {
        _os << *chain;
    }*/
    return _os;
}

// constructor which accepts an istream and reconstructs the Player from file
Player::Player( istream& _is, CardFactory* _cardPool )
{
    _is >> d_name >> d_coin; // line containing name and # of coins
    string token, line;
    while( getline( _is, line ) ) { // lines containing chain and hand
        istringstream streamLine(line);
        while( streamLine >> token ) {
            if( token == "Hand" ) d_hand = Hand( _is, _cardPool ); break;
            // else build Chains using Chain::(istream constructor)
        }
        if( token == "Hand" ) break;
    }
}
