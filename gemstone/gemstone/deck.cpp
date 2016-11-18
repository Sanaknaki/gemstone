// ==========================================================================
//  Project : gemstone
//  File    : deck.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "deck.hpp"

using std::out_of_range; using std::random_shuffle;

Deck::Deck(){}

Card* Deck::draw()
{
    if(d_playable.empty())
    {
        out_of_range("The deck is empty!");
    }
    
    Card* top(d_playable.back());
    d_playable.pop_back();
    return top;
}

void Deck::add(Card* _card)
{
    d_original.push_back(_card);
    d_playable.push_back(_card);
}

bool Deck::isEmpty()
{
    if(d_playable.empty())
    {
        return true;
    }
    
    return false;
}

void Deck::shuffle()
{
    if(!d_playable.empty())
    {
        random_shuffle(d_playable.begin(), d_playable.end());
    }
}
