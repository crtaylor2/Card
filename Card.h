#ifndef CARD_H
#define CARD_H

#include <string>

class Card {

public:
    enum Suit {
        DIAMOND,
        CLUB,
        HEART,
        SPADE
    };

    enum Value {
        ACE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    enum MeldStatus
    {
        NOTMELD,
        RUNMELD,
        SETMELD
    };

    Card(Suit s, Value v);

    Suit suit;
    Value value;
    MeldStatus meld;
    double probOfMeld;
    int OneFromMeld;
    int TwoFromMeld;

    bool isMeld() const;

    std::string CardToString() const;
    int CardPoints() const;

    static bool CompareForSets(Card Card1, Card Card2);
    static bool CompareForRuns(Card Card1, Card Card2);

    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
};

#endif // CARD_H