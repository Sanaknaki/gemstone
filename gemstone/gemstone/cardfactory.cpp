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
#include <algorithm>
#include <random>

using namespace std;

// enum for gemstones
enum { Q = 0, H = 1, O = 2, M = 3, T = 4, R = 5, A = 6, E = 7 };

// only instance of each Card type
vector<Card*> CardFactory::GEMSTONES = { new Quartz(), new Hematite(), new Obsidian(), new Malachite(),
                                            new Turquoise(), new Ruby(), new Amethyst(), new Emerald() };

//constructor
CardFactory::CardFactory()
{
    // Initital counter for 20 cards.
    int count = 20;

    // Loop through all card types, count = amount of cards of type to make.
    for(int type = 0; type < 8; ++type)
    {
        for(int j = 0; j < count; ++j)
        {
            d_cards.push_back( GEMSTONES[type] );
        }

        // Decrement count for the next type of cards.
        count -= 2;
    }
}

// returns pointer to the only instance of CardFactory
CardFactory* CardFactory::getFactory()
{
    // Create static instant of Cardfactory.
    static CardFactory sendBackFactory;

    // Send back reference.
    return &sendBackFactory;
}

// returns deck with all 104 cards
Deck CardFactory::getDeck()
{
    Deck returnDeck{ d_cards };
    // Shuffle the deck.
    // See address below for example
    // http://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    auto engine = default_random_engine{};
    shuffle( returnDeck.begin(), returnDeck.end(), engine );
    // Return deck.
    return returnDeck;
}

// return Card pointer according to given char
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
    // default return
    return nullptr;
}

// destructor
CardFactory::~CardFactory()
{
    for( auto gemstone : GEMSTONES ) delete gemstone;
}
