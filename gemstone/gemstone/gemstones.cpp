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
    if(_name == Gemstone::Q)     { d_name = "Q"; }
    else if(_name == Gemstone::H){ d_name = "H"; }
    else if(_name == Gemstone::O){ d_name = "O"; }
    else if(_name == Gemstone::M){ d_name = "M"; }
    else if(_name == Gemstone::T){ d_name = "T"; }
    else if(_name == Gemstone::R){ d_name = "R"; }
    else if(_name == Gemstone::A){ d_name = "A"; }
    else                         { d_name = "E"; }
}

string Card::getName()
{
    if(d_name == "Q")
    {
        return "Quartz";
    }else if(d_name == "H")
    {
        return "Hematite";
    }else if(d_name == "O")
    {
        return "Obsidian";
    }else if(d_name == "M")
    {
        return "Malachite";
    }else if(d_name == "T")
    {
        return "Turquois";
    }else if(d_name == "R")
    {
        return "Ruby";
    }else if(d_name == "A")
    {
        return "Amethyst";
    }else
    {
        return "Emerald";
    }
}

int Card::getCardsPerCoin(int _coins)
{
    return 0;
}
