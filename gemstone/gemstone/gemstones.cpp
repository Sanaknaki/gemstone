// ==========================================================================
//  Project : gemstone
//  File    : gemstones.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "gemstones.hpp"
Card::Card(){}

Card::Card(int& _name) : d_name("")
{
    if(_name == Gemstone::Q)     { Quartz quartz; quartz.setName("Q"); }
    else if(_name == Gemstone::H){ Hematite hematite; hematite.setName("H"); }
    else if(_name == Gemstone::O){ Obsidian obsidian; obsidian.setName("O"); }
    else if(_name == Gemstone::M){ Malachite malachite; malachite.setName("M"); }
    else if(_name == Gemstone::T){ Turquois turquois; turquois.setName("T"); }
    else if(_name == Gemstone::R){ Ruby ruby; ruby.setName("R"); }
    else if(_name == Gemstone::A){ Amethyst amethyst; amethyst.setName("A"); }
    else                         { Emerald emerald; emerald.setName("E");}
}

string Card::getName()
{
    return d_title;
}

int Card::getCardsPerCoin(int _coins)
{
    return 0;
}
