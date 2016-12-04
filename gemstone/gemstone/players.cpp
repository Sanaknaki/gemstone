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
#include "hand.hpp"
#include <string>

using std::string;

// Constructor.
Player::Player(string& _name) : d_name{ _name }
{
    //Chain chain; --Each player has a chain.--
}

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
    return d_chain;
}

// Get the number of chains a player has.
int Player::getNumChains() const
{
    return d_chain;
}

// Return chain a position i.
/*Chain<Card>& Player::operator[](int i)
{
    return 0;
}*/

// Buy a third chain if possible.
void Player::buyThirdChain()
{
    if(d_coin >= 3 && d_chain == 2)
    {
        d_coin -=3;
        d_chain +=1;
        cout << this->d_name << " has bought their 3 chain!" << endl;
    }else if(d_coin < 3)
    {
        cout << "ERROR : Not enough coins to buy the chain!" << endl;
    }else if(d_chain == 3)
    {
        cout << "ERROR : You already have 3 chains!" << endl;
    }
}

// Print top card or full hand of player.
void printHand( ostream& _os, const bool fullHand ) const
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
    if( d_coin != 1 ) _os << "s";
    _os << endl;
    // print chains

    return _os;
}

// constructor which accepts an istream and reconstructs the Player from file
Player::Player( istream& _is, CardFactory* _cardPool )
{
    string token, line;
    // get a line
    while( getLine(_is, line) ) {
        istringstream streamLine(line);
        // get individual white space seperated token
        while( streamLine >> token ) {
            // process token
            
        }
    }
}
