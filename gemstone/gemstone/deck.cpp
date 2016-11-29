// ==========================================================================
//  Project : gemstone
//  File    : deck.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "deck.hpp"

using std::out_of_range; using std::random_shuffle;
using std::cout; using std::endl;
Deck::Deck(){}

Card* Deck::draw()
{
    if(this->size() < 0)
    {
        cout << "Deck is empty! " << endl;
        return nullptr;
    }else{
        Card* top = this->back();
        (*this).pop_back();
        return top;
    }
    /*if(d_playable.empty())
    {
        out_of_range("The deck is empty!");
    }
    
    Card* top(d_playable.back());
    d_playable.pop_back();
    return top;*/
}

void Deck::add(Card* _card)
{
    (*this).push_back(_card);
    /*d_original.push_back(_card);
    d_playable.push_back(_card);*/
}

bool Deck::isEmpty()
{
    if(this->empty())
    {
        return true;
    }
    
    return false;
    
    /*if(d_playable.empty())
    {
        return true;
    }
    
    return false;*/
}

void Deck::shuffle()
{
    if(!this->empty())
    {
        random_shuffle(this->begin(), this->end());
    }
}
