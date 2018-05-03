// YOUR NAME: Josh Seymore
//
// CS 4318, spring 2018
// Agent Challenge 4: Cricket card game
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

vector<Card> seanPickBluffs(int oppVal, int val, vector<vector<Card> > check);
   // Your function must end up returning a valid int between 0 and numCardsPerHand - 1.
   // No random-number generation allowed!
   // hand.getCard(0) gives the first card in your hand.
   // hand.getCard(0).getNumber() gives the number of that card, 1 to 11.
   // hand.getCard(0).getSuit() gives the suit of that card.
   // match.getRuns(0) gives the number of runs scored by player A so far.
   // numRuns(d) gives the number of runs scored when the card difference is d.
   // See the definitions of Hand, Card and MatchState for more helpful functions.
// Rename and complete this agent function.
Play idiAgentBrace(Hand hand, Play oppLastPlay, int nextNumUp, int discardSize, int handSizes[],  const MatchState &match) {
   Play myPlay;
   Card cards;
   vector<Card> discards;
   // vector<int> numType(13);
   vector<vector<Card> > check(13);
   uint count, size;
   // int val, score, oppScore, oppChance, chance, oppNum, oppVal, choice;
   // int val, score, oppChance, chance, oppNum, choice, oppVal, next, bestScore, numPlay, i;
   int val, score, oppChance, chance, oppNum, oppVal, next, bestScore, numPlay, i;
   // bool bluff, oppBluff, choice;
   bool doubt, bluff;
   
   // cout << "\n\nHERERERE\n" << check[0].size() << " " << check[0][0].getNumber() << endl;
   // cout << "\n\nHERERERE\n" << check[0].size() << endl;
   srand(time(NULL));
   doubt = false;
   // choice = 0;
   // bluff = true;
   // oppBluff = true;
   next = nextNumUp - 1;
   bestScore = INT_MIN;
   numPlay = 0;
   size = hand.getHandSize();
   score = 0;
   chance = (size + size / 2) - discardSize;
   // oppScore = 0;
   oppChance = 0;
   oppNum = oppLastPlay.getNumCards();
   oppVal = oppLastPlay.getCardType();
   
   
   for (count = 0; count < size; count++) {
      cards = hand.getCard(count);
      val = cards.getNumber();
      // numType[val - 1] += 1;
	  if (val - 1 >= 0) {
		check[val - 1].push_back(cards);
	}
      
      // if (cards.getNumber() == nextNumUp) {
         // discards.push_back(cards);
      // }
   }
   
   if (size == 1) {
      discards.push_back(cards);
   } else if (size == check[next].size()) {
      discards = check[next];
   } else if (check[next].size() > 1) {
      // cout << "\n" << next << " " << val - 1 << " " << nextNumUp << " " << check[next].size() << "\n";
      // for (count = 0; count < check[next].size(); count++) {
         // if (cards.getNumber() == nextNumUp) {
         // if (check[next][count].getNumber() == nextNumUp) {
            // discards.push_back(check[next][count]);
            discards = check[next];
         // }
      // }
   } else {
      if (check[next].empty()) {
         chance += 1000;
      } else {
         if (check[next].size() < 2) {
            chance += 12 - (discardSize / 2);
         }
         if (check[next].size() < 3) {
            chance += 5 - discardSize;
         }
      }
      
      if (oppNum > 1) {
         oppChance += 10;
         if (oppNum >= 2) {
            if (check[oppVal - 1].size() > 2) {
               oppChance += 1000;
            // } else if (check[oppVal - 1].size() <= 2) {
            } else {
               oppChance += 10 - (discardSize - handSizes[2]);
            }
         }
         if (handSizes[2] < 5) {
            oppChance += 12;
            if (handSizes[2] < 3) {
               oppChance += 15;
            }
         }
      }
      
      
      
      if (discardSize < 8) {
         chance += 10;
      } else {
         chance -= discardSize;
      }
      
      if (oppChance - chance >= 30) {
         doubt = true;
      } else if (chance - oppChance >= 25) {
         discards = seanPickBluffs(oppVal, next, check);
      } else {
         // choice = check
         // i = 0;
         // while (i < check[next].size()) {
            // if (cards.getNumber() == nextNumUp) {
            // discards.push_back(cards);
            // discards.push_back(check[next][i]);
            discards = check[next];
            // i++;
         // }
      }
   }
   
   if (size != 17 && (handSizes[1] < 2 || handSizes[2] < 2)) {
	cout << handSizes[1] << " " << handSizes[2] << endl;
		for (count = 0; count < size; count++) {
			discards.push_back(hand.getCard(count));
		}
   }
   myPlay.setCardsPlayed(discards.size(), nextNumUp, discards, doubt);
   
   return myPlay;
}


vector<Card> seanPickBluffs(int oppVal, int val, vector<vector<Card> > check) {
   vector<Card> destroy;
   int count, i, score, numPlay, choice, bestScore, next;
   int bluf1, bluf2;
   bluf1 = 55;
   bluf2 = 45;
   bestScore = 0;
   i = 0;
   numPlay = 0;
   choice = 0;
   srand(time(NULL));
   // loop through check, score = number of cards of that val I have, combined somehow with how soon I will be able to play that card.
      numPlay = rand() % 100;
      if (numPlay <= bluf1) {
         numPlay = 1;
      } else if (numPlay > bluf1 && numPlay <= bluf1 + bluf2) {
         numPlay = 2;
      // } else {
         // numPlay = 3;
      }
   // for (count = 0; count < 5; count++) {
   // for (count = 0; count < 10; count += 2) {
   for (count = 0; count < 13; count += 1) {
      score = 0;
      choice = count % 13;
      // choice = next + ((count * 2) % 3) % 13;
      // choice = val + ((count * 2) % 3) % 13;
      // how close am I to playing the card?
      // Example-> start at:  1,    4,    7,    10,      13
      // How many do I have?  ^     ^     ^     ^        ^   
      // score += check[choice].size() * 4;
      // score += check[next].size() * 4;
      // if (score / 4 > numPlay)
      // if (oppVal - 1 == choice) {
         // score += oppVal * 2;
      // }
      score += check[choice].size();
      if (bestScore < score) {
         bestScore = score;
         // as for the rng deciding how many cards I play when bluffing, 1 = 55%, 2 = 40%, 3 = 5% <- may change these to make 3 <= 3%, really don't want
         // to bluff 3 cards, in fact I may completely remove it.
         // cout << "\n********************\n" << choice << " " << i << endl;
         // cout << "\n********************\n" << choice << " " << check[choice].size() << endl;
         // if (destroy.size() < numPlay && !check[choice % 13].empty()) {
         if (destroy.size() < numPlay && !check[choice].empty()) {
            // destroy.push_back(check[choice % 13][i]);
            // if (!destroy.empty()) {
               // // if (numPlay > 1 && check[choice][0] == destroy[0] && count !=) {
                  
               // // }
            // } else {
               // destroy.push_back(check[choice][0]);
            // }
            // destroy.push_back(check[choice][0]);
            destroy = check[choice];
            // i++;
         }
      }
   }
   return destroy;
   // bluff = true;
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
