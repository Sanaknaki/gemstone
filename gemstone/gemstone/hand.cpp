// ==========================================================================
//  Project : gemstone
//  File    : hand.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "hand.hpp"

using std::cout; using std::endl;

Hand& Hand::operator+=(Card* _card)
{
    this->d_cards.push_back(_card);
    return *this;
}

Card* Hand::top()
{
    if(d_cards.empty())
    {
        cout << "You have no cards in your hand!" << endl;
        return 0;
    }else{
        return d_cards.front();
    }
}

Card* Hand::play()
{
    if(d_cards.empty())
    {
        cout << "You have no cards in your hands!" << endl;
        return 0;
    }else{
        Card* playCard = d_cards.front();
        d_cards.erase(d_cards.begin());
        return playCard;
    }
}
