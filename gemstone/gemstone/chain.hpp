// ==========================================================================
//  Project : gemstone
//  File    : chain.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef chain_h
#define chain_h

#include <stdio.h>
#include <vector>
#include <exception>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using namespace std;

template <class T>
class Chain{
private:
    // Chain will hold the T type cards by pointer in a vector<T*>
    vector<T*> d_cards;
public:
    // default constructor
    Chain() = default;

    // istream constructor
    Chain( istream& _is, CardFactory* _cardPool )
    {
        char card;
        // get individual white space seperated tokens
        while( _is >> card ) {
            d_cards.push( dynamic_cast<T*>( _cardPool->getPtr(card) ) );
        }
    }

    Chain<T>& operator+=( Card* _card )
    {
        T* cardT;
        // try to convert _card to T type card
        try {
            cardT = dynamic_cast<T*>( _card );
            // check if conversion worked
            if ( cardT == 0 ) throw IllegalType();
        } catch ( IllegalType& e ) { // conversion didn't work!
            cout << e.what() << endl;
            return *this;
        }
        // conversion successful!
        d_cards.push_back( cardT );
        return *this;

        /*
        string chainType = typeid(T).name();
        string cardType  = typeid(*_card).name();

        if(chainType != cardType)
        {
            cout << "Chain and Card are not the same gem type!" << endl;
        }else { d_cards.push_back(_card); return this; }
        */
    }

    // using binary search to determine amount of coins to return
    int sell() const
    {
        int chainLength = d_cards.size();
        // if chain worth less than 2 coins
        if( chainLength < T::getCardsPerCoin(2) ) {
            // if chain worth less than 1 coin
            if( chainLength < T::getCardsPerCoin(1) ) return 0;
            else return 1;
        }
        // chain worth 2 or more coins
        else {
            // if chain worth less than 3 coins
            if( chainLength < T::getCardsPerCoin(3) ) return 2;
            else {
                // if chain worth less than 4 coins
                if( chainLength < T::getCardsPerCoin(4) ) return 3;
                else return 4;
            }
        }
    }

    // new exception named IllegalType
    // followed "Define New Exceptions" in address below
    // https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
    struct IllegalType : public exception {
        const char * what () const throw () {
            return "Chain and Card are not the same gem type!";
        }
    };

};

    /*vector<Card*> d_cards;
    int size() = 0;
    void print(ostream&) = 0;
public:
    Chain()
    {

    }

    Chain(const istream&, CardFactory* cardFactory)
    {

    }

    Chain<T>& operator+=(Card* _card)
    {
        string chainType = typeid(T).name();
        string cardType  = typeid(*_card).name();

        if(chainType != cardType)
        {
            cout << "Chain and Card are not the same gem type!" << endl;
        }else{
            d_cards.push_back(_card);
            return this;
        }
    }

    int sell()
    {
        return(int)(new T)->getCoinsPerCard((d_cards.size()));
    }
};*/

#endif /* chain_h */
