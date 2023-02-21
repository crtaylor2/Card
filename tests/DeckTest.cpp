#include "Deck.h"

#include <gtest/gtest.h>

TEST(DeckNotContainsTest, DeckNotContainsTest)
{
    Card c1(Card::DIAMOND, Card::EIGHT);
    Card c2(Card::SPADE, Card::ACE);
    Card c3(Card::CLUB, Card::KING);
    Card c4(Card::HEART, Card::SIX);

    Deck testDeck;
    testDeck.push_back(c1);
    testDeck.push_back(c2);

    EXPECT_EQ(testDeck.contains(c3), nullptr);
    EXPECT_EQ(testDeck.contains(c4), nullptr);
}

TEST(DeckContainsTest, DeckContainsTest)
{
    Card c1(Card::DIAMOND, Card::EIGHT);
    Card c2(Card::SPADE, Card::ACE);
    Card c3(Card::CLUB, Card::KING);
    Card c4(Card::HEART, Card::SIX);

    Deck testDeck;
    testDeck.push_back(c1);
    testDeck.push_back(c2);

    EXPECT_EQ(*testDeck.contains(c1), c1);
    EXPECT_EQ(*testDeck.contains(c2), c2);
}
