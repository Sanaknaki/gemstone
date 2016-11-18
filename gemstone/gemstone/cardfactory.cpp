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
            if(i == 0)
            {
                Quartz* card = new Quartz();
                card->setName("Q");
                d_deck.add(card);
            }else if(i == 1)
            {
                Hematite* card = new Hematite();
                card->setName("H");
                d_deck.add(card);
            }else if(i == 2)
            {
                Obsidian* card = new Obsidian();
                card->setName("O");
                d_deck.add(card);
            }else if(i == 3)
            {
                Malachite* card = new Malachite();
                card->setName("M");
                d_deck.add(card);
            }else if(i == 4)
            {
                Turquois* card = new Turquois();
                card->setName("T");
                d_deck.add(card);
            }else if(i == 5)
            {
                Ruby* card = new Ruby();
                card->setName("R");
                d_deck.add(card);
            }else if(i == 6)
            {
                Amethyst* card = new Amethyst();
                card->setName("A");
                d_deck.add(card);
            }else
            {
                Emerald* card = new Emerald();
                card->setName("E");
                d_deck.add(card);
            }
        }
        
        count = count - 2;
    }
    
    d_deck.shuffle();
}

Deck CardFactory::getDeck()
{
    return d_deck;
}
