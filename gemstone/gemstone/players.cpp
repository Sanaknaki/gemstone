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

Player::Player(string& _name)
{
    d_name = _name;
    d_coin = 0;
    d_chain = 2;
    //Hand hand;  --Each player has a hand.--
}

string Player::getName()
{
    return d_name;
}

int Player::getNumCoins()
{
    return d_coin;
}

Player& Player::operator+=(int _coin)
{
    this->d_coin += _coin;
    return *this;
}

int Player::getMaxNumChains()
{
    return d_chain;
}

int Player::getNumChains()
{
    return d_chain;
}

/*Chain<Card>& Player::operator[](int i)
{
    return 0;
}*/

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
