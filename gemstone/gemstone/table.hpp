// ==========================================================================
//  Project : gemstone
//  File    : card-hierarchy.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef table_hpp
#define table_hpp

#include <stdio.h>
#include <iostream>

#include "cardfactory.hpp"

using std::string;
using std::ostream;
using std::istream;

class Table{
private:

public:
    Table(const istream&,CardFactory*);
    bool win(string& _name);
    void print(ostream&);
};

#endif /* table_hpp */
