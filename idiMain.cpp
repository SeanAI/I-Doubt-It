// CS 4318, spring 2018
// Agent Challenge 4: Cricket card game
//
// Here's the main function that plays all agents against each other and
// summarizes the results.

#include "idi.h"

extern const int numAgents;
extern Play (*agentFunc[])(Hand, Play, int, int, int[], const MatchState &);
extern string agentStr[];

// MatchState playIDICardGameMatch(Play (*agentA)(Hand, Play, int, int, int[],const MatchState &), Play (*agentB)(Hand, Play, int, int, int[], const MatchState &), Play (*agentC)(Hand, Play, int, int, int[], const MatchState &), bool printAllDetails, IDIStats playerStats[]);
MatchState playIDICardGameMatch(Play (*agentA)(Hand, Play, int, int, int[],const MatchState &), Play (*agentB)(Hand, Play, int, int, int[], const MatchState &), Play (*agentC)(Hand, Play, int, int, int[], const MatchState &), bool printAllDetails, IDIStats playerStats[]);

int main()
{
   IDIStats playerStats[numAgents];
   int i, numLosses[numAgents], numWins[numAgents], numBluffs[numAgents], k, j, l;
   MatchState match;

   srandom(time(0));

   cout << "Final Project: I Doubt It\n"
        << "Iteration results\n";
   for (i = 0; i < numAgents; i += 1)
   {
      numWins[i] = 0;
      numLosses[i] = 0;
	  numBluffs[i] = 0;
    }
   i = 0; // brace
   j = 1; // meza
   l = 2; // seymore
   
   for (k = 0; k < 100; k += 1)
   {
      if (k == 0)
      {
		cout << "\n"
           << "A = " << agentStr[i] << ", B = " << agentStr[j] << ", C = " << agentStr[l] << ":"
           << "\n"
           << "Exhibition match:\n" << flush;
      } else if (k == 1) {
        cout << "\nOfficial matches:\n";
	  }
      match = playIDICardGameMatch(agentFunc[i], agentFunc[j], agentFunc[l], k == 0, playerStats);
      numBluffs[i] += match.getStats(0).bluffs;
      numBluffs[j] += match.getStats(1).bluffs;
	  numBluffs[l] += match.getStats(2).bluffs;
      switch (match.getResult())
      {
         case aWin:
            cout << "\n   >>> A wins <<<\n"  << " A: Cards Possessed: " << match.getStats(0).cardsPossessed << " | Bluffs: " << match.getStats(0).bluffs  << "\n"
										<< " B: Cards Possessed: " << match.getStats(1).cardsPossessed << " | Bluffs: " << match.getStats(1).bluffs << "\n"
										<< " C: Cards Possessed: " << match.getStats(2).cardsPossessed << " | Bluffs: " << match.getStats(2).bluffs << "\n";
            break;
         case bWin:
			cout << "\n   >>> B wins <<<\n"  << " A: Cards Possessed: " << match.getStats(0).cardsPossessed << " | Bluffs: " << match.getStats(0).bluffs  << "\n"
							<< " B: Cards Possessed: " << match.getStats(1).cardsPossessed << " | Bluffs: " << match.getStats(1).bluffs << "\n"
							<< " C: Cards Possessed: " << match.getStats(2).cardsPossessed << " | Bluffs: " << match.getStats(2).bluffs << "\n";
            break;
         case cWin:
			cout << "\n   >>> C wins <<<\n"  << " A: Cards Possessed: " << match.getStats(0).cardsPossessed << " | Bluffs: " << match.getStats(0).bluffs  << "\n"
							<< " B: Cards Possessed: " << match.getStats(1).cardsPossessed << " | Bluffs: " << match.getStats(1).bluffs << "\n"
							<< " C: Cards Possessed: " << match.getStats(2).cardsPossessed << " | Bluffs: " << match.getStats(2).bluffs << "\n";
            break;
      }
         // else
         // {
            switch (match.getResult())
            {
               case aWin:
                  numWins[i] += 1;
                  numLosses[j] += 1;
                  numLosses[l] += 1;
                  break;
               case bWin:
                  numWins[j] += 1;
                  numLosses[i] += 1;
                  numLosses[l] += 1;
                  break;
               case cWin:
                  numWins[l] += 1;
                  numLosses[j] += 1;
                  numLosses[i] += 1;
                  break;
            }
         // }
            /*IDIStats[i].runs += match.getRuns(0);
            IDIStats[i].wickets += match.getWickets(0);
            IDIStats[i].balls += match.getBalls(0);
            IDIStats[i].runs += match.getRuns(1);
            IDIStats[i].wickets += match.getWickets(1);
            IDIStats[i].balls += match.getBalls(1);
            IDIStats[j].runs += match.getRuns(1);
            IDIStats[j].wickets += match.getWickets(1);
            IDIStats[j].balls += match.getBalls(1);
            IDIStats[j].runs += match.getRuns(0);
            IDIStats[j].wickets += match.getWickets(0);
            IDIStats[j].balls += match.getBalls(0);
            */
     
   }
   cout << "\n\n"
        << "Overall standings:                              \n"
        << "                         W     L     Bluffs\n";
   cout << fixed;
   for (i = 0; i < numAgents; i += 1)
   {
      cout << setw(20) << left << agentStr[i]
           << " " << setw(5) << right << numWins[i]
           << " " << setw(5) << right << numLosses[i]
           << " " << setw(10) << right << numBluffs[i] << "\n";
           // << " " << setprecision(2) << setw(5) << right << playerStats[i].bluffs << "\n";
   } 
   return 0;
}

MatchState playIDICardGameMatch(Play (*agentA)(Hand, Play, int, int, int[], const MatchState &), Play (*agentB)(Hand, Play, int, int, int[], const MatchState &), Play (*agentC)(Hand, Play, int, int, int[], const MatchState &), bool printAllDetails, IDIStats playerStats[])
{
   // Play a match of the cricket card game between given agents.
   Hand hand1, hand2, hand3, tempHand;
   Deck startingDeck; 
   vector<Card> discardPile, firstDiscard;
   //int battingPlay, bowlingPlay, lastBowlingCardNumber;
   Play (*agent1)(Hand, Play, int, int, int[], const MatchState &);
   Play (*agent2)(Hand, Play, int, int, int[], const MatchState &);
   Play (*agent3)(Hand, Play, int, int, int[], const MatchState &);
   Play aPlay, bPlay, cPlay, firstPlay;
   MatchState match;
   int round, iter;
   int handSizes[3];
   bool firstRound, bluffed;
   
   
   //initialize
   firstRound = true;
   firstPlay.setCardsPlayed(0, 0 , firstDiscard, false);
   round = 0;
   iter = 0;
   handSizes[0] = hand1.getHandSize();
   handSizes[1] = hand2.getHandSize();
   handSizes[2] = hand3.getHandSize();
   agent1 = agentA;
   agent2 = agentB;
   agent3 = agentC;
   startingDeck.build();
   startingDeck.shuffle();
   startingDeck.removeDumbCard();

   while(startingDeck.getDeckSize() != 0)
   {
	   if(iter == 3)
	   {
		   iter = 0;
	   }
	   switch(iter)
	   {
			case 0:
				hand1.addCard(startingDeck.deal());
				iter++;
				break;
			case 1:
				hand2.addCard(startingDeck.deal());
				iter++;
				break;
			case 2:
				hand3.addCard(startingDeck.deal());
				iter++;
				break;
	   }
   }
   discardPile.push_back(startingDeck.getLastCard());
   iter = 1; //reset for use
   
   while (match.stillPlaying())
   {
     
      if(iter > 13)
      {
         iter = 1;
      }
      if (printAllDetails)
      {   
		  cout << "_____________________________________________________________________________\n\n"
		  << "Discards: ";
		  for(uint i = 0; i < discardPile.size(); i++)
		  {
			 cout << discardPile[i].toString();
		  }
		  cout << " | Number of Discards: " << discardPile.size() << "\n\n";
		  
          cout << "A's hand: " << hand1.toString()<< " Hand Size: " << hand1.getHandSize() << "\n"
              << "B's hand: " << hand2.toString() << " Hand Size: " << hand2.getHandSize() << "\n"
              << "C's hand: " << hand3.toString() << " Hand Size: " << hand3.getHandSize() << "\n\n";
      }
      
      switch(round)
      {
         case 0: // if player A is playing
         {
            if(firstRound)
            {
               aPlay = (*agent1)(hand1, firstPlay, iter, discardPile.size(), handSizes, match);
            }
            else
            {
               aPlay = (*agent1)(hand1, cPlay, iter, discardPile.size(), handSizes, match);
            }
            vector<Card> oppDiscs = cPlay.getDiscards();
            vector<Card> tempDiscs = aPlay.getDiscards();
            if (printAllDetails)
            {
               if(aPlay.getClaim() && !firstRound)
               {
                  cout << "A doubts it!\n";
                  
                  uint i = 0;
                  // bool bluffed = false;
                  while(i < oppDiscs.size() && !bluffed)
                  {
                     if(oppDiscs[i].getNumber() != cPlay.getCardType())
                     {
                        bluffed = true;
                        // playerStats[0].bluffs += 1;
                        cout << "C was bluffing! C must add all of the discard pile to their hand. \n";
                        while(!discardPile.empty())
                        {
                           hand3.addCard(discardPile.back());
                           discardPile.pop_back();
                        }
                        break;
                     }
                     i++;
                  }
                  if(!bluffed)
                  {
                      cout << "C was telling the truth! A must add all of the discard pile to their hand. \n";
                     while(!discardPile.empty())
                     {
                        hand1.addCard(discardPile.back());
                        discardPile.pop_back();
                     }
                  }
                  round++;
                  break;
               }
               else
               {
                  cout << "A claims they have " << aPlay.getNumCards() << " " << aPlay.getCardType()<< "'s; \n";
               }
            }
            if(hand1.getHandSize() == 1)
            {
               hand1.removeCard(0);
               // match.updateStats(0, hand1.getHandSize(), bluffed);
            }
            if(tempDiscs.size() > 0)
            {
			   for(int i = 0; i < hand1.getHandSize(); i++)
               {
                  for(uint j = 0; j < tempDiscs.size(); j++)
                  {
                     if(hand1.getCard(i).equal(tempDiscs[j]))
                     {
                        discardPile.push_back(tempDiscs[j]);
                        hand1.removeCard(i);
                     }
                  }
                  
               }
			  for(uint j = 0; j < tempDiscs.size(); j++)
			  {
				 if(tempDiscs[j].getNumber() != aPlay.getCardType())
				 {
					bluffed = true;
					
					for(int i = 0; i < hand1.getHandSize(); i++)
					{
						if(hand1.getCard(i).equal(tempDiscs[j]))
						{
							discardPile.push_back(tempDiscs[j]);
							hand1.removeCard(i);
						}
					}                        
				}
			  }
               if(bluffed)
               {
                  match.updateStats(0, hand1.getHandSize(), true);
               }
            }
            round++;
            if(firstRound)
            {
               firstRound = false;
            }
            break;
         }
         case 1: // if player B is playing
           {
            bPlay = (*agent2)(hand2, aPlay, iter, discardPile.size(), handSizes, match);
            vector<Card> oppDiscs = aPlay.getDiscards();
            vector<Card> tempDiscs = bPlay.getDiscards();
            if (printAllDetails)
            {
               if(bPlay.getClaim() && !firstRound)
               {
                  cout << "B doubts it!\n";
                  
                  uint i = 0;
                  // bool bluffed = false;
                  while(i < oppDiscs.size() && !bluffed)
                  {
                     if(oppDiscs[i].getNumber() != cPlay.getCardType())
                     {
                        bluffed = true;
                        cout << "A was bluffing! A must add all of the discard pile to their hand. \n";
                        while(!discardPile.empty())
                        {
                           hand1.addCard(discardPile.back());
                           discardPile.pop_back();
                        }
                        break;
                     }
                     i++;
                  }
                  if(!bluffed)
                  {
                      cout << "A was telling the truth! B must add all of the discard pile to their hand. \n";
                     while(!discardPile.empty())
                     {
                        hand2.addCard(discardPile.back());
                        discardPile.pop_back();
                     }
                  }
                  round++;
                  break;
               }
               else
               {
                  cout << "B claims they have " << bPlay.getNumCards() << " " << bPlay.getCardType()<< "'s; \n";
               }
               
            }
            
            if(hand2.getHandSize() == 1)
            {
               hand2.removeCard(0);
               // match.updateStats(1, hand2.getHandSize(), bluffed);
            }
            if(tempDiscs.size() > 0)
            {
               for(int i = 0; i < hand2.getHandSize(); i++)
               {
                  for(uint j = 0; j < tempDiscs.size(); j++)
                  {
                     if(hand2.getCard(i).equal(tempDiscs[j]))
                     {
                        discardPile.push_back(tempDiscs[j]);
                        hand2.removeCard(i);
                     }
                  }
                  
               }
			   for(uint j = 0; j < tempDiscs.size(); j++)
			   {
				 if(tempDiscs[j].getNumber() != bPlay.getCardType())
				 {
					bluffed = true;
					for(int i = 0; i < hand2.getHandSize(); i++)
					{
						if(hand2.getCard(i).equal(tempDiscs[j]))
						{
							discardPile.push_back(tempDiscs[j]);
							hand2.removeCard(i);
						}
					}                        
				}
			  }
               if(bluffed)
               {
                  match.updateStats(1, hand2.getHandSize(), true);
               }
            }
            round++;
            break;
         }
         case 2: // if player C is playing
         {
            cPlay = (*agent3)(hand3, bPlay, iter, discardPile.size(), handSizes, match);
            vector<Card> oppDiscs = bPlay.getDiscards();
            vector<Card> tempDiscs = cPlay.getDiscards();
            
            if (printAllDetails)
            {
               if(cPlay.getClaim() && !firstRound)
               {
                  cout << "C doubts it!\n";
                  
                  uint i = 0;
                  // bool bluffed = false;
                  while(i < oppDiscs.size() && !bluffed)
                  {
                     if(oppDiscs[i].getNumber() != bPlay.getCardType())
                     {
                        bluffed = true;
                        cout << "B was bluffing! B must add all of the discard pile to their hand. \n";
                        while(!discardPile.empty())
                        {
                           hand2.addCard(discardPile.back());
                           discardPile.pop_back();
                        }
                        break;
                     }
                     i++;
                  }
                  if(!bluffed)
                  {
                      cout << "B was telling the truth! C must add all of the discard pile to their hand. \n";
                     while(!discardPile.empty())
                     {
                        hand3.addCard(discardPile.back());
                        discardPile.pop_back();
                     }
                  }
                  round = 0;
                  break;
               }
               else
               {
                 cout << "C claims they have " << cPlay.getNumCards() << " " << cPlay.getCardType()<< "'s; \n";
               }
               
            }
            if(hand3.getHandSize() == 1)
            {
               hand3.removeCard(0);
               // match.updateStats(2, hand3.getHandSize(), bluffed);
            }
            if(tempDiscs.size() > 0)
            {
               for(int i = 0; i < hand3.getHandSize(); i++)
               {
                  for(uint j = 0; j < tempDiscs.size(); j++)
                  {
					 if(hand3.getCard(i).equal(tempDiscs[j]))
                     {
                        discardPile.push_back(tempDiscs[j]);
                        hand3.removeCard(i);
                     }
                  }
                  
               }
			   for(uint j = 0; j < tempDiscs.size(); j++)
			   {
				 if(tempDiscs[j].getNumber() != cPlay.getCardType())
				 {
					bluffed = true;
					for(int i = 0; i < hand3.getHandSize(); i++)
					{
						if(hand3.getCard(i).equal(tempDiscs[j]))
						{
							discardPile.push_back(tempDiscs[j]);
							hand3.removeCard(i);
						}
					}                        
				}
			  }
               if(bluffed)
               {
                  match.updateStats(2, hand3.getHandSize(), true);
               }
            }
			round = 0;
            break;
		} 
       }
	  bluffed = false;
      match.updateStats(0, hand1.getHandSize(), bluffed);
      match.updateStats(1, hand2.getHandSize(), bluffed);
      match.updateStats(2, hand3.getHandSize(), bluffed);
	  handSizes[0] = hand1.getHandSize();
	  handSizes[1] = hand2.getHandSize();
      handSizes[2] = hand3.getHandSize();
      iter++;
      hand1.removeDumbCard();
      hand2.removeDumbCard();
      hand3.removeDumbCard();
	  
    }

   return match;
}
