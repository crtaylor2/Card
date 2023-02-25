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

        void sortByRuns();
        void sortBySets();

        void createDeck();
        void shuffle();

        void deal(Deck &hand, int count);
};

using Hand = Deck;

#endif
