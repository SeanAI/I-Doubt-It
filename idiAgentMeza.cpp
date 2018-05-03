// YOUR NAME: Leah Meza
//
// CS 4318, spring 2018
// Final Project: I Doubt It
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this ccgAgentSmith.cpp file to ccgAgentJones.cpp and the
// ccgAgentSmith function below to ccgAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Random-number generation is not
// allowed; your agent must be entirely deterministic.  Feel free to create
// other agents--each in a separate .cpp file--for yours to play against,
// but turn in only one.  Test your agent(s) with
//
//    nice bash ccgBuild.bash
//
// and then
//
//    nice ./ccgRunSim
//
// Each submitted agent will play each other, batting first and batting
// second an equal number of times, to determine the standings, which will
// be posted soon after the agents are due.

#include "idi.h"
#include "math.h"
#include "iostream"

bool callOutBluff(Play oppPlay, Hand myHand, int discardSize, int oppPlaySize);
// Rename and complete this agent function.
Play idiAgentMeza(Hand hand, Play lastBowledCard, int nextNumUp, int discardPileSize, int handSize[], const MatchState &match)
{
   // Your function must end up returning a valid int between 0 and numCardsPerHand - 1.
   // No random-number generation allowed!
   // hand.getCard(0) gives the first card in your hand.
   // hand.getCard(0).getNumber() gives the number of that card, 1 to 13.
   // hand.getCard(0).getSuit() gives the suit of that card.
   // match.getRuns(0) gives the number of runs scored by player A so far.
   // numRuns(d) gives the number of runs scored when the card difference is d.
   // See the definitions of Hand, Card and MatchState for more helpful functions.
   
   Play myPlay;
   vector<Card> discards;
   int aces = 0;
   int twos = 0;
   int threes = 0;
   int fours = 0;
   int fives = 0;
   int sixes = 0;
   int sevens = 0;
   int eights = 0;
   int nines = 0;
   int tens = 0;
   int jacks = 0;
   int queens = 0;
   int kings = 0;

   if(hand.getHandSize() >= 10)
   {
	   for (int i = 0; i < hand.getHandSize(); i++)
	   {
		   for(int j = 1; j < 14; j++)
		   {
				if (hand.getCard(i).getNumber() ==  j)
				{
					if (j == 1)
					{
						aces++;
					}
					if (j == 2)
					{
						twos++;
					}
					if (j == 3)
					{
						threes++;
					}
					if (j == 4)
					{
						fours++;
					}
					if (j == 5)
					{
						fives++;
					}
					if (j == 6)
					{
						sixes++;
					}
					if (j == 7)
					{
						sevens++;
					}
					if (j == 8)
					{
						eights++;
					}
					if (j == 9)
					{
						nines++;
					}
					if (j == 10)
					{
						tens++;
					}
					if (j == 11)
					{
						jacks++;
					}
					if (j == 12)
					{
						queens++;
					}
					if (j == 13)
					{
						kings++;
					}
					else {
						//do nothing
					}
				}
		   }
	   }
	   if (aces >= 1 && aces < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 1)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			aces = 0;
	   }
	   else if (twos >= 1 && twos < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 2)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			twos = 0;
	   }
	   else if (threes >= 1 && threes < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 3)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			threes = 0;
	   }
	   else if (fours >= 1 && fours < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 4)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			fours = 0;
	   }
	   else if (fives >= 1 && fives < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 5)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			fives = 0;
	   }
	   else if (sixes >= 1 && sixes < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 6)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			sixes = 0;
	   }
	   else if (sevens >= 1 && sevens < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 7)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			sevens = 0;
	   }
	   else if (eights >= 1 && eights < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 8)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			eights = 0;
	   }
	   else if (nines >= 1 && nines < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 9)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			nines = 0;
	   }
	   else if (tens >= 1 && tens < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 10)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			tens = 0;
	   }
	   else if (jacks >= 1 && jacks < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 11)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			jacks = 0;
	   }
	   else if (queens >= 1 && queens < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 12)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			queens = 0;
	   }
	   else if (kings >= 1 && kings < 3)
	   {
		   for(int k = 0; k < hand.getHandSize(); k++)
			{
				if(hand.getCard(k).getNumber() == 13)
				{
					discards.push_back(hand.getCard(k));
				}
			}
			kings = 0;
	   }
	   else
		{
				discards.push_back(hand.getCard(0));
		}
   }
   else {
		if (hand.getHandSize() >= 5 && hand.getHandSize() < 10)
		{
			discards.push_back(hand.getCard(0));
			discards.push_back(hand.getCard(1));
		}
		else if (hand.getHandSize() <= 4 && hand.getHandSize() >= 1)
		{
			for (int i = 0; i < hand.getHandSize(); i++)
			{
				discards.push_back(hand.getCard(i));
			}
		}
		else if (hand.getHandSize() < 1)
		{
			discards.push_back(hand.getCard(0));
		}
   }
	
   myPlay.setCardsPlayed(discards.size(), nextNumUp, discards, callOutBluff(lastBowledCard, hand, discardPileSize, lastBowledCard.getNumCards()));
   return myPlay;
   
}
//determines whether or not to call a bluff on someone
/* Mostly determined by if an opponent claims more than 2 cards or claims a card that I also have*/
//If neither of these qualifications are met, then the agent will not call out a bluff
//As well, it will not call out a bluff if the person before it claimed a bluff because that would not make any sense since 
//they did not play a card
bool callOutBluff(Play oppPlay, Hand myHand, int discardSize, int oppPlaySize){
	int selectedCards, bluff;
	
	//local variables
	selectedCards = oppPlay.getCardType();
	bluff = 0;
	
		for(int i = 0; i < myHand.getHandSize(); i++)
		{
			if (selectedCards == myHand.getCard(i).getNumber())
			{
				bluff++;
			}
		}
		if (oppPlay.getClaim())
		{
			return false;
		}
		if (oppPlaySize > 2)
		{
			return true;
		}
		if (bluff >= 1)
		{
			return true;
		}
		else{
			return false;
		}
}
/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.
   
   For the second iteration of this assignment, I tried to do the same ideas as I did for 
   the last assignment but make some improvements. 
   
   First off, I fixed the holes in my batter to make sure that my agent avoids giving the batter
   free runs from Wides and Byes. I'm not sure how much not having these holes in the first iteration would
   have helped. However, I did see a number of them in my results from last time, so I think that's fixed.
   
   I did the same attempt at using genetic development of my agent by using the best numbers from each generation.
   That being said, I decided to revert back to the numbers that I had from the previous generation. No matter how
   I changed the numbers this time, the original numbers always performed better than the other dummy agents that I used
   to test the generations.
   
   One thing I also implemented was losing condition for my hand at the end of my batting section. At the end of the decision to bat,
   I check if the round is impossible to win. If it's not, then I decide to throw away the lowest valued card. One thing I noticed in some 
   of the other player's agents was that they tended to do drop their lower value cards more often, so I decided to implement something 
   like that in my code. After the implementation, my current agent performed better than the other copies, so I decided to run with this
   agent.
*/
