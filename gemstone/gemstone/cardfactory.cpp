// ==========================================================================
//  Project : gemstone
//  File    : cardfactory.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "cardfactory.hpp"
#include <iostream>


CardFactory::CardFactory()
{
    buildDeck();
}

void CardFactory::buildDeck()
{
    int count = 20;
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < count; ++j)
        {
            Card* card = new Card(i);
            d_deck.add(card);
        }
        
        count = count - 2;
    }
    
    d_deck.shuffle();
}

Deck CardFactory::getDeck()
{
    return d_deck;
}
