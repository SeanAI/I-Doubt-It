// CS 4318, spring 2018
// Final Project: I Doubt It
//
// Here are the #includes and definitions available to each agent.

#ifndef CCG_H
#define CCG_H

#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int numBallsPerMatch = 1080;
const int numCardsPerSuit = 13;
const int numSuits = 4;

// Type to keep track of card suits.
enum cardSuit {spades, clubs, hearts, diamonds};

// Type to keep track of the result of one cricket match.
enum matchResult {aWin, bWin, cWin, unfinished};

// Keeps track of one card used in the game.
class Card
{
private:
   int number;
   cardSuit suit;
   static int randomInt(int n);
public:
   Card(int numCard, cardSuit suitCard)
   {
      makeCard(numCard, suitCard);
   }
   Card() {};
   int getNumber() const {return number;}
   cardSuit getSuit() const {return suit;}
   bool equal(Card card2)
   {
      if(getSuit() == card2.getSuit() && getNumber() == card2.getNumber())
      {
         return true;
      }
      else 
      {
         return false;
      }
   }
   void makeCard(int cardNum, cardSuit cardSuit) 
   {
	   number = cardNum; 
	   suit = cardSuit;
      return;
   } 
   string toString() const;
};

class Deck
{
	private:
	vector<Card> deckOCards;
	public:
	
	void build()
	{
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 13; j++)
			{
				switch(i)
				{
					case 1: deckOCards.push_back(Card(j, spades));
							break;
					case 2: deckOCards.push_back(Card(j, clubs));
							break;
					case 3: deckOCards.push_back(Card(j, hearts));
							break;
					case 4: deckOCards.push_back(Card(j, diamonds));
							break;
				}
			}
		}
	}
	int getDeckSize()
	{
		return deckOCards.size();
	}
   void removeDumbCard()
   {
      for(uint i = 0; i < deckOCards.size(); i++)
      {
         if(deckOCards[i].getNumber() == 0)
         {
            deckOCards.erase(deckOCards.begin() + i);
         }
      }
   }
	void shuffle() 
	{
		Card temp;
		int randomInt(52);
        int p = randomInt;
		for(int i = 51; i > 0; i--)
		{
			Card temp = deckOCards[i];
			deckOCards[i] = deckOCards[p];
         deckOCards[p] = temp;
		}
	}
	
   Card deal() {
      // int n;
      Card card;
      
      // n = random() % deckOCards.size();
      
      card = deckOCards[0];
      deckOCards.erase(deckOCards.begin());
      
      return card;
   }
	
};
// Keeps track of one player's hand of cards.
class Hand
{
private:
   vector<Card> cards;
public:
   Hand();
   Card getCard(uint which) const 
   {
      Card errorCard;
      if(which >= 0 && which < cards.size())
         return cards[which];
      else
         return errorCard;
   }
   void removeCard(uint which)
   {
	   Card removedCard;
      
     if(cards.size() == 1)
      {
         cards.pop_back();
      }
      else if(which > 0 && which <= cards.size())
	  {
		  removedCard = cards[which];
		  cards.erase(cards.begin() + which);
	  } 
   }
   int getHandSize()
   {
	   return cards.size();
   }
   void addCard(Card add)
   {
	   cards.push_back(add);
   }
   void removeDumbCard()
   {
      for(uint i = 0; i < cards.size(); i++)
      {
         if(cards[i].getNumber() == 0)
         {
            cards.erase(cards.begin() + i);
         }
      }
   }
   
   string toString() const;
};

// Keeps track of basic cricket statistics.
struct IDIStats
{
   int cardsPossessed;
   int bluffs;
   
   IDIStats() {cardsPossessed = 0; bluffs = 0;}
};

class Play
{
   private:
   int numOfCardsPlayed, cardType;
   vector<Card> discards;
   bool claimBluff;
   
   public:
      Play();
      void setCardsPlayed(int num, int type, vector<Card> dis, bool dou)
      {
         numOfCardsPlayed = num;
         cardType = type;
         discards = dis;
         claimBluff = dou;
         return;
      }
      int getNumCards()
      {
         return numOfCardsPlayed;
      }
      int getCardType()
      {
         return cardType;
      }
      vector<Card> getDiscards()
      {
         return discards;
      }
      bool getClaim()
      {
         return claimBluff;
      }
};
// Keeps track of one match.
class MatchState
{
private:
   IDIStats stats[3];
   matchResult result;
   void checkForResult();
public:
   MatchState();
   int getResult() const {return result;}
   bool stillPlaying() const {return result == unfinished;}
   void updateCardsPossessed(int agent, int as);
};

#endif // #ifndef CCG_H
