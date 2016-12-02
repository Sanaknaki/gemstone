// ==========================================================================
//  Project : gemstone
//  File    : cardfactory.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "cardfactory.hpp"
#include <iostream>


CardFactory::CardFactory()
{
    // Initital counter for 20 cards.
    int count = 20;
    
    // Loop through all card types, i = type, count = amount of cards of type 'i' made.
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < count; ++j)
        {
            if(i == 0)
            {
                d_deck.add(new Quartz);
            }else if(i == 1)
            {
                //Hematite* card = new Hematite();
                d_deck.add(new Hematite);
                //d_deck.add(card);
            }else if(i == 2)
            {
                //Obsidian* card = new Obsidian();
                d_deck.add(new Obsidian);
                //d_deck.add(card);
            }else if(i == 3)
            {
                //Malachite* card = new Malachite();
                d_deck.add(new Malachite);
                //d_deck.add(card);
            }else if(i == 4)
            {
                //Turquoise* card = new Turquoise();
                d_deck.add(new Turquoise);
                //d_deck.add(card);
            }else if(i == 5)
            {
                //Ruby* card = new Ruby();
                d_deck.add(new Ruby);
                //d_deck.add(card);
            }else if(i == 6)
            {
                //Amethyst* card = new Amethyst();
                d_deck.add(new Amethyst);
                //d_deck.add(card);
            }else
            {
                //Emerald* card = new Emerald();
                d_deck.add(new Emerald);
                //d_deck.add(card);
            }
        }
        
        // Decrement count for the next type of cards.
        count = count - 2;
    }
    
    // Shuffle the deck.
    d_deck.shuffle();
}

CardFactory* CardFactory::getFactory()
{
    // Create static instant of Cardfactory.
    static CardFactory sendBackFactory;
    
    // Send back reference.
    return &sendBackFactory;
}

Deck CardFactory::getDeck()
{
    // Return deck.
    return d_deck;
}
