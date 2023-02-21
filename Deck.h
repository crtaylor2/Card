#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck : public std::vector<Card>
{
    public:
        Card* contains(const Card& card);
        void remove(const Card& card);

        void searchForRuns();
        void searchForSets();

        void createDeck();
        void shuffle();
};

using Hand = Deck;

#endif
