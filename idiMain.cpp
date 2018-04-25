// CS 4318, spring 2018
// Agent Challenge 4: Cricket card game
//
// Here's the main function that plays all agents against each other and
// summarizes the results.

#include "idi.h"

extern const int numAgents;
extern Play (*agentFunc[])(Hand, Play, bool, const MatchState &);
extern string agentStr[];

MatchState playIDICardGameMatch(Play (*agentA)(Hand, Play, bool, const MatchState &), Play (*agentB)(Hand, Play, bool, const MatchState &), Play (*agentC)(Hand, Play, bool, const MatchState &), bool printAllDetails);

int main()
{
   IDIStats playerStats[numAgents];
   int i, numLosses[numAgents], numWins[numAgents], k, j, l,
   order[numAgents];//, temp;
   MatchState match;

   srandom(time(0));

   cout << "Final Project: I Doubt It\n"
        << "Iteration results\n";
   for (i = 0; i < numAgents; i += 1)
   {
      numWins[i] = 0;
      numLosses[i] = 0;
   }
   i = 0;
   j = 1;
   l = 2;
   
   for (k = 0; k <= 5; k += 1)
   {
      cout << "\n"
           << "A = " << agentStr[i] << ", B = " << agentStr[j] << ", C = " << agentStr[l] << ":"
           << "\n"
           << "Exhibition match:\n" << flush;
      match = playIDICardGameMatch(agentFunc[i], agentFunc[j], agentFunc[l], k == 0);
      switch (match.getResult())
      {
         case aWin:
            cout << "   >>> A wins <<<\n";
            break;
         case bWin:
            cout << "   >>> B wins <<<\n";
            break;
         case cWin:
            cout << "   >>> C wins <<<\n";
            break;
      }
      if (k == 0)
      {
         cout << "Official matches:\n";
      }
         else
         {
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
         }
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

   
   /*
   for (i = 0; i < numAgents; i += 1)
   {
      for (j = 0; j < numAgents; j += 1)
      {
         if (i != j)
         {
            cout << "\n"
                 << "A = " << agentStr[i] << ", B = " << agentStr[j] << ", C = " << agentStr[j]":"
                 << "\n"
                 << "Exhibition match:\n" << flush;
            for (k = 0; k <= 200; k += 1)
            {
               match = playIDICardGameMatch(agentFunc[i], agentFunc[j], k == 0);
               cout << "   A " << match.getRuns(0) << "-"
                    << match.getWickets(0) << "(" << match.getBalls(0)
                    << "), B " << match.getRuns(1) << "-"
                    << match.getWickets(1) << "(" << match.getBalls(1)
                    << ")";
               switch (match.getResult())
               {
                  case aWin:
                     cout << "   >>> A wins <<<\n";
                     break;
                  case bWin:
                     cout << "   >>> B wins <<<\n";
                     break;
                  case cWin:
                     cout << "   >>> C wins <<<\n";
                     break;
               }
               if (k == 0)
               {
                  cout << "Official matches:\n";
               }
               else
               {
                  switch (match.getResult())
                  {
                     case aWin:
                        numWins[i] += 1;
                        pointsAsA[i] += 4;
                        numLosses[j] += 1;
                        break;
                     case bWin:
                        numLosses[i] += 1;
                        numWins[j] += 1;
                        pointsAsB[j] += 4;
                        break;
                     case draw:
                        numDraws[i] += 1;
                        pointsAsA[i] += 1;
                        numDraws[j] += 1;
                        pointsAsB[j] += 1;
                        break;
                     case tie:
                        numTies[i] += 1;
                        pointsAsA[i] += 2;
                        numTies[j] += 1;
                        pointsAsB[j] += 2;
                        break;
                  }
                  IDIStats[i].runs += match.getRuns(0);
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
               }
            }
         }
      }
   }

   for (i = 0; i < numAgents; i += 1)
   {
      order[i] = i;
   }
   for (i = 0; i < numAgents - 1; i += 1)
   {
      for (j = i + 1; j < numAgents; j += 1)
      {
         if (pointsAsA[order[i]] + pointsAsB[order[i]] < pointsAsA[order[j]] + pointsAsB[order[j]] || (pointsAsA[order[i]] + pointsAsB[order[i]] == pointsAsA[order[j]] + pointsAsB[order[j]] &&
             agentStr[order[i]] > agentStr[order[j]]))
         {
            temp = order[i];
            order[i] = order[j];
            order[j] = temp;
         }
      }
   } */
   cout << "\n\n"
        << "Overall standings:                              \n"
        << "                         W     L     Bluffs\n";
   cout << fixed;
   for (i = 0; i < numAgents; i += 1)
   {
      cout << setw(20) << left << agentStr[i]
           << " " << setw(5) << right << numWins[i]
           << " " << setw(5) << right << numLosses[i]
           << " " << setprecision(2) << setw(5) << right << playerStats[i].bluffs << "\n";
   } 
   return 0;
}

MatchState playIDICardGameMatch(Play (*agentA)(Hand, Play, bool, const MatchState &), Play (*agentB)(Hand, Play, bool, const MatchState &), Play (*agentC)(Hand, Play, bool, const MatchState &), bool printAllDetails)
{
   // Play a match of the cricket card game between given agents.
   Hand hand1, hand2, hand3, tempHand, discardPile;
   Deck startingDeck;
   //int battingPlay, bowlingPlay, lastBowlingCardNumber;
   Play (*agent1)(Hand, Play, bool, const MatchState &);
   Play (*agent2)(Hand, Play, bool, const MatchState &);
   Play (*agent3)(Hand, Play, bool, const MatchState &);
   Play aPlay, bPlay, cPlay;
   MatchState match;
   int round, iter;
   
   round = 0;
   iter = 0;
   agent1 = agentA;
   agent2 = agentB;
   agent3 = agentC;
   startingDeck.build();
   startingDeck.shuffle();

   while(startingDeck.getDeckSize() > 1)
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
   while (match.stillPlaying())
   {
      if (printAllDetails)
      {
         cout << "_____________________________________________________________________________\n"
              << "A's hand: " << hand1.toString()<< " Hand Size: " << hand1.getHandSize() << "\n"
              << "B's hand: " << hand2.toString() << " Hand Size: " << hand2.getHandSize() << "\n"
              << "C's hand: " << hand3.toString() << " Hand Size: " << hand3.getHandSize() << "\n";
      }
      
      switch(round)
      {
         case 0: // if player A is playing
         {
            aPlay = (*agent1)(hand1, cPlay, true, match);
            if (printAllDetails)
            {
               cout << "A claims they have " << aPlay.getNumCards() << " " << aPlay.getCardType()<< "'s; \n";
            }
            vector<Card> tempDiscs = aPlay.getDiscards();
            if(hand1.getHandSize() == 1)
            {
               hand1.removeCard(0);
               match.updateCardsPossessed(0, hand1.getHandSize());
            }
            if(tempDiscs.size() > 0)
            {
               for(int i = 0; i < hand1.getHandSize(); i++)
               {
                  for(uint j = 0; j < tempDiscs.size(); j++)
                  {
                     if(hand1.getCard(i).equal(tempDiscs[j]))
                     {
                        discardPile.addCard(tempDiscs[j]);
                        hand1.removeCard(i);
                     }
                  }
                  
               }
            }
            round++;
            break;
         }
         case 1: // if player B is playing
           {
            bPlay = (*agent2)(hand2, aPlay, true, match);
            if (printAllDetails)
            {
               cout << "B claims they have " << bPlay.getNumCards() << " " << bPlay.getCardType()<< "'s; \n";
            }
            vector<Card> tempDiscs = bPlay.getDiscards();
            if(hand2.getHandSize() == 1)
            {
               hand2.removeCard(0);
               match.updateCardsPossessed(1, hand2.getHandSize());
            }
            if(tempDiscs.size() > 0)
            {
               for(int i = 0; i < hand2.getHandSize(); i++)
               {
                  for(uint j = 0; j < tempDiscs.size(); j++)
                  {
                     if(hand2.getCard(i).equal(tempDiscs[j]))
                     {
                        discardPile.addCard(tempDiscs[j]);
                        hand2.removeCard(i);
                        
                     }
                  }
                  
               }
            }
            round++;
            break;
         }
         case 2: // if player C is playing
         {
            cPlay = (*agent3)(hand3, bPlay, true, match);
            if (printAllDetails)
            {
               cout << "C claims they have " << cPlay.getNumCards() << " " << cPlay.getCardType()<< "'s; \n";
            }
            vector<Card> tempDiscs = cPlay.getDiscards();
            if(hand3.getHandSize() == 1)
            {
               hand3.removeCard(0);
               match.updateCardsPossessed(2, hand3.getHandSize());
            }
            if(tempDiscs.size() > 0)
            {
               for(int i = 0; i < hand3.getHandSize(); i++)
               {
                  for(uint j = 0; j < tempDiscs.size(); j++)
                  {
                     if(hand3.getCard(i).equal(tempDiscs[j]))
                     {
                        discardPile.addCard(tempDiscs[j]);
                        hand3.removeCard(i);
                     }
                  }
                  
               }
            }
            round = 0;
            break;
         }
      }
      
      match.updateCardsPossessed(0, hand1.getHandSize());
      match.updateCardsPossessed(1, hand2.getHandSize());
      match.updateCardsPossessed(2, hand3.getHandSize());
   }

   return match;
}
