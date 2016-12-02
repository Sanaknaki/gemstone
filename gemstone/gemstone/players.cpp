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

using std::string;

// Constructor.
Player::Player(string& _name)
{
    d_name = _name;
    d_coin = 0;
    d_chain = 2;
    Hand hand;
    //Chain chain; --Each player has a chain.--
}

// Return the name of the player.
string Player::getName()
{
    return d_name;
}

// Return the amount of coins a player has.
int Player::getNumCoins()
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
int Player::getMaxNumChains()
{
    return d_chain;
}

// Get the number of chains a player has.
int Player::getNumChains()
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

// Print top card of full hand of player.
void printHand(ostream& , bool)
{
    
}
