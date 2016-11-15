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

#ifndef chain_h
#define chain_h

#include <stdio.h>
#include <vector>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream;

template <class T>
class Chain{
private:

public:
    Chain( const istream&,CardFactory*);
    Chain<T>& operator+=(Card*);
    int sell();
};

#endif /* chain_h */
