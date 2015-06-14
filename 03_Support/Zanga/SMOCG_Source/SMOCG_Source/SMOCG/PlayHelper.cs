#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG {
    /// <summary>
    /// The static class PlayHelper is used to determine whether a card can be focused on
    /// by the player, and if it can be played
    /// </summary>
    public static class PlayHelper {
        private static bool _TRACE = false;

        /// <summary>
        /// Returns a bool that determines whether the player is allowed to focus on a card or not
        /// </summary>
        /// <param name="player">The player to check</param>
        /// <param name="card">The card to check</param>
        /// <returns>Whether the player can focus the card or not</returns>
        public static bool CanFocusCard(Player player, Card card){
            // if the player hasn't gotten any cards yet, then return false
            if (player.GameState == PlayerInGameState.None)
                return false;

            bool inPlayersHand = player.HasCard(card); // see is the card in the player's hand

            // if the player has gotten his cards, and the card is in his hand or
            // one of his face up cards, then let him.
            // alternatively, if it's one of the oppositions cards, then only let him focus
            // if it's a faceup card
            if (player.GameState == PlayerInGameState.PreGame || 
                player.GameState == PlayerInGameState.HandCards ||
                player.GameState == PlayerInGameState.FaceUpCards) {
                if (inPlayersHand && (card.CardType == CardType.InHandCard || card.CardType == CardType.FaceUpCard))
                    return true;
            } else if (player.GameState == PlayerInGameState.FaceDownCards) {
                if (inPlayersHand && card.CardType == CardType.FaceDownCard)
                    return true;
            }
            if (!inPlayersHand && (card.CardType == CardType.FaceUpCard || 
                                   card.CardType == CardType.InPickupPileCard))
                return true;

            // not allowed to focus on card
            return false;
        }

        /// <summary>
        /// Returns a bool that determines whether the player is allowed to select a card or not
        /// </summary>
        /// <param name="player">The player to check</param>
        /// <param name="card">The card to check</param>
        /// <returns>Whether the player can select the card or not</returns>
        public static bool CanSelectCard(Player player, Card card) {
            if (player.GameState == PlayerInGameState.None)
                return false;

            bool inPlayersHand = player.HasCard(card); // see if the card is in the player's hand

            if (player.GameState == PlayerInGameState.PreGame) {
                if (inPlayersHand && (card.CardType == CardType.InHandCard || card.CardType == CardType.FaceUpCard))
                    return true;
            } else if (player.GameState == PlayerInGameState.HandCards) { // playing from the hand cards
                if (inPlayersHand && card.CardType == CardType.InHandCard) {
                    if (!player.IsMyTurn) // if it's not the player's turn, let him swap his cards around
                        return true;
                    else {
                        if (player.CurrentlySelectedCards.Count == 0) // if the player hasn't selected anything yet
                            return true;
                        // else, only allow him to select equal value cards
                        else if (player.CurrentlySelectedCards[0].CardValue == card.CardValue)
                            return true;
                        // else, clear all previously selected cards and select the new one
                        else if (player.CurrentlySelectedCards[0].CardValue != card.CardValue) {
                            player.ClearAllSelectedCards();
                            return true;
                        }
                    }
                }
            } else if (player.GameState == PlayerInGameState.FaceUpCards) { // playing from face up cards
                if (inPlayersHand && card.CardType == CardType.FaceUpCard) {
                    if (!player.IsMyTurn) // if it's not the player turn, let him swap his cards around
                        return true;
                    else {
                        if (player.CurrentlySelectedCards.Count == 0) // if the player hasn't selected anything yet
                            return true;
                        // else, only allow him to select equal value cards
                        else if (player.CurrentlySelectedCards[0].CardValue == card.CardValue)
                            return true;
                        // else, clear all previously selected cards and select the new one
                        else if (player.CurrentlySelectedCards[0].CardValue != card.CardValue) {
                            player.ClearAllSelectedCards();
                            return true;
                        }
                    }
                }
            } else if (player.GameState == PlayerInGameState.FaceDownCards) { // playing from face down cards
                if (inPlayersHand && card.CardType == CardType.FaceDownCard) {
                    if (player.IsMyTurn && player.CurrentlySelectedCards.Count == 0)
                        return true; // can only select a card if it's the player's turn
                    else if (player.IsMyTurn && player.CurrentlySelectedCards.Count > 0) {
                        player.ClearAllSelectedCards();
                        return true;
                    }
                }
            }

            // not allowed to select card
            return false;
        }

        /// <summary>
        /// Returns a bool that determines whether the player is allowed to place a card or not
        /// </summary>
        /// <param name="player">The player thats placing the card</param>
        /// <param name="card">The card being placed</param>
        /// <param name="deck">The deck of cards - we need to know the last card placed</param>
        /// <returns>Whether the card can be placed or not</returns>
        public static bool CanPlaceCard(Player player, Card card, Deck deck) {

            bool inPlayersHand = player.HasCard(card); // see if the card is in the player's hand

            if (inPlayersHand && deck.PickupPile.Count == 0) // if it's the first card, allow it
                return true;

            Card lastPlayed = deck.PickupPile[0]; // the last played card
            if(_TRACE) Console.WriteLine("\tCard being checked = " + card.CardDescription + ", Last played card = " + lastPlayed.CardDescription);

            if (inPlayersHand && (card.CardValue == CardValue.Two || // if it's a two
                                    card.CardValue == CardValue.Seven || // a seven
                                    card.CardValue == CardValue.Eight || // an eight
                                    card.CardValue == CardValue.Ten)) {// or a ten, then play it
                if(_TRACE) Console.WriteLine("\tAllowing special card - " + card.CardDescription);
                return true;
            }

            // if the last card was an eight, then find the card to mirror
            if (inPlayersHand && lastPlayed.CardValue == CardValue.Eight) {
                if (deck.PickupPile.Count == 1) {// if there's only the eight, then play any card
                    if(_TRACE) Console.WriteLine("\tAn eight on nothing, so letting " + card.CardDescription + " play");
                    return true;
                } else {
                    //Card cardToMirror = lastPlayed; // currently mirroring the eight
                    for (int i = 0; i < deck.PickupPile.Count; i++) {
                        // go down through the pickup pile and look for a card that's not 8 (as they may have put eight on eight on...)
                        if (deck.PickupPile[i].CardValue != CardValue.Eight) {
                            lastPlayed = deck.PickupPile[i]; // we've found one
                            break;
                        }
                    }
                    // if we didn't find a card to mirror - i.e. the pickup pile consists of nothing but eights then
                    // let the player play any card
                    if (lastPlayed.CardValue == CardValue.Eight) {
                        if(_TRACE) Console.WriteLine("\tMirror card was a eight, so letting card " + card.CardDescription + " play");
                        return true;
                    }
                    //// if the card to mirror was a seven, then only let him play a seven
                    //else if (cardToMirror.CardValue == CardValue.Seven && card.CardValue < cardToMirror.CardValue)
                    //    return true;
                    //// else the player's card has to be greater in value than the one we're mirroring
                    //else if (card.CardValue >= cardToMirror.CardValue)
                    //    return true;
                }
            }

            // NOTE: from this point, lastPlayed could have been changed (by a eight mirroring a card below it)

            // if the last card was a seven, then only let him play under seven
            if (inPlayersHand && lastPlayed.CardValue == CardValue.Seven && card.CardValue < lastPlayed.CardValue) {
                if(_TRACE) Console.WriteLine("\tcard value is less than seven, letting " + card.CardDescription + " play");
                return true;
            }

            // the card has to be greater than the last played card
            if (lastPlayed.CardValue != CardValue.Seven && inPlayersHand && card.CardValue >= lastPlayed.CardValue) {
                if(_TRACE) Console.WriteLine("\tcard value is greater than last played, letting " + card.CardDescription + " play");
                return true;
            }

            return false;
        }

        /// <summary>
        /// Sees if the player can play a valid card
        /// </summary>
        /// <param name="player">The player to check</param>
        /// <param name="cards">The cards in the player's hand</param>
        /// <param name="deck">The deck of cards - we need to know the last card placed</param>
        /// <returns>The index of the first card that can be played, or -1 if no card can be played</returns>
        public static int AnyValidCards(Player player, List<Card> cards, Deck deck) {
            if (deck.PickupPile.Count == 0)
                return 0;

            int i = -1;
            for(int j=0; j<cards.Count; j++){
                if (PlayHelper.CanPlaceCard(player, cards[j], deck)) {
                    i = j;
                    break;
                }
            }

            if (_TRACE) {
                if (i == -1)
                    Console.WriteLine("No valid card for player " + player.PlayerNumber + " found");
                else
                    Console.WriteLine("\t\tFirst valid card for player " + player.PlayerNumber + " is " + cards[i].CardDescription);
            }

            return i;
        }
    }
}
