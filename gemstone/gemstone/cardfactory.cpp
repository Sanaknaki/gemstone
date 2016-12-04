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

using namespace std;

// enum for gemstones
enum { Q = 0, H = 1, O = 2, M = 3, T = 4, R = 5, A = 6, E = 7 };

const vector<Card*> CardFactory::GEMSTONES = { new Quartz(), new Hematite(), new Obsidian(), new Malachite(),
                                                new Turquoise(), new Ruby(), new Amethyst(), new Emerald() };

CardFactory::CardFactory()
{
    // Initital counter for 20 cards.
    int count = 20;

    // Loop through all card types, count = amount of cards of type to make.
    for(int type = 0; type < 8; ++type)
    {
        for(int j = 0; j < count; ++j)
        {
            d_deck.push_back( GEMSTONES[type] );
        }

        // Decrement count for the next type of cards.
        count -= 2;
    }
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
    // Shuffle the deck.
    d_deck.shuffle();
    // Return deck.
    return d_deck;
}

Card* CardFactory::getPtr( const char card ) const
{
    switch ( card ) {
        case 'Q': return GEMSTONES[Q];
        case 'H': return GEMSTONES[H];
        case 'O': return GEMSTONES[O];
        case 'M': return GEMSTONES[M];
        case 'T': return GEMSTONES[T];
        case 'R': return GEMSTONES[R];
        case 'A': return GEMSTONES[A];
        case 'E': return GEMSTONES[E];
        default: cout << "Invalid Card!" << endl;
    }
    return nullptr; // default return
}

CardFactory::~CardFactory() {
    for( auto gemstone : GEMSTONES ) {
        delete gemstone;
    }
}
