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
enum matchResult {aWin, bWin, unfinished};

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
   };
   Card();
   int getNumber() const {return number;}
   cardSuit getSuit() const {return suit;}
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
		for(int i = 0; i < 4; i++)
		{
			for(int j = 1; j < 14; j++)
			{
				switch(i)
				{
					case 0: deckOCards.push_back(Card(j, spades));
							break;
					case 1: deckOCards.push_back(Card(j, clubs));
							break;
					case 2: deckOCards.push_back(Card(j, hearts));
							break;
					case 3: deckOCards.push_back(Card(j, diamonds));
							break;
				}
			}
		}
	}
   
   // void removeCard(int n, vector<Card> &cards) {
   void removeCard(int n) {
      deckOCards.erase(deckOCards.begin() + n);
   }
   
   void deal(vector<Card> &player) {
      int n;
      
      n = random() % deckOCards.size();
      
      // card = deckOCards[n];
      player.push_back(deckOCards[n]);
      // removeCard(n, deckOCards);
      removeCard(n);
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
      if(which > 0 && which <= cards.size())
         return cards[which];
      else
         return errorCard;
   }
   
   void removeCard(int n) {
      cards.erase(cards.begin() + n);
   }
   
   void addCard(Card add) {
      cards.push_back(add);
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
   int numOfCardsPlayed;
   vector<Card> discards;
   bool claimBluff;
   
   public:
      Play() {
         cout << "\nHELLO THERE\n";
      }
      void setCardsPlayed(int num, vector<Card> dis, bool dou)
      {
         numOfCardsPlayed = num;
         discards = dis;
         claimBluff = dou;
         return;
      }
      int getNumCards()
      {
         return numOfCardsPlayed;
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
   bool stillPlaying() const {return result == unfinished;}
};

#endif // #ifndef CCG_H
