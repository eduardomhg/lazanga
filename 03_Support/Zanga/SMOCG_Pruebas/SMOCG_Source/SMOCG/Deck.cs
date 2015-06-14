#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// A Deck represents a deck of 52 <see cref="Card">Cards</see>
    /// </summary>
    public class Deck {
        private bool _TRACE = false;

        private CardGameScene _game; // a reference to the card game scene object

        static int _numCards = 52; // the number of cards in the deck
        private int _numCardsLeftInDeck = 0; // the number of cards left in the deck

        private string _shuffleOverNetwork; // a string to send the cards shuffle pos over the network

        private List<Card> _cards = new List<Card>(52); // create the array to hold the cards
        private List<Card> _deckCards = new List<Card>(52); // create a list to hold the cards left in the deck
        private List<Card> _pickUpCards = new List<Card>(52); // create a list to hold the cards in the pickup pile
        private List<Card> _burnedCards = new List<Card>(52); // create a list to hold the burned cards

        private Random rand = new Random();

        #region GetSet Parameters

        /// <summary>
        /// Get the cards
        /// </summary>
        public List<Card> Cards {
            get { return _cards; }
        }

        /// <summary>
        /// Get the pickup pile
        /// </summary>
        public List<Card> PickupPile {
            get { return this._pickUpCards; }
        }

        /// <summary>
        /// Set the camera for the cards
        /// </summary>
        public BasicCamera Camera {
            set {
                foreach (Card c in this._cards)
                    c.Camera = value;
            }
        }

        /// <summary>
        /// Get the shuffled position of the cards, so they can be sent over the network
        /// </summary>
        public string ShufflePos {
            get { return this._shuffleOverNetwork; }
        }

        #endregion

        /// <summary>
        /// Constructor - create each card
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="cardGame">A reference to the CardGameScene object</param>
        /// <param name="camera">A camera object to view the deck with</param>
        public Deck(SMOCGGame game, CardGameScene cardGame, BasicCamera camera) {
            this._game = cardGame; // keep a reference of the card game scene object

            // create the cards
            for (int i = 0; i < _numCards; i++) {
                float angle = MathHelper.Pi / (_numCards - 1);
                Vector3 pos = new Vector3(0.0f, 20.0f, 1.0f * i);
                Vector3 rot = new Vector3(0.0f);
                this._cards.Add(new Card(game, camera, pos, rot, new Vector3(0.2f, 0.2f, 0.1f)));
            }
        }

        /// <summary>
        /// Return a specific card
        /// </summary>
        /// <param name="num">The number of the card to return</param>
        /// <returns>A <see cref="Card">Card</see> object specified</returns>
        public Card GetCard(int num) {
            return this._cards[num];
        }

        /// <summary>
        /// Add a card to the pickup pile
        /// </summary>
        /// <param name="player">The player adding the cards to the pile</param>
        /// <param name="cards">The cards to add</param>
        public void AddToPickUpPile(Player player, List<Card> cards) {
            foreach (Card card in cards) {
                this._pickUpCards.Insert(0, card);
                card.CardType = CardType.InPickupPileCard;
            }
            // see if the player needs cards
            if (this._deckCards.Count > 0 && player.NumberOfCardsInHand < 3) {
                if (this._deckCards.Count >= 3 - player.NumberOfCardsInHand) {
                    Card[] cardsToGive = new Card[3 - player.NumberOfCardsInHand];
                    for (int i = 0; i < 3 - player.NumberOfCardsInHand; i++) {
                        this._deckCards[0].CardType = CardType.InHandCard; // set the card to an in hand card
                        cardsToGive[i] = this._deckCards[0]; // add it to the array
                        this._deckCards.RemoveAt(0); // remove it from the deckcards array
                    }
                    player.GiveCards(cardsToGive, false); // give the player the cards
                } else {
                    Card[] cardsToGive = new Card[this._deckCards.Count];
                    int i = 0;
                    foreach (Card card in this._deckCards) { // go through the deck cards and transfer them
                        card.CardType = CardType.InHandCard;
                        cardsToGive[i++] = card;
                    }
                    this._deckCards.Clear();
                    player.GiveCards(cardsToGive, false); // give the player the cards
                }
            }
            CheckIfShouldBurn(player);
        }

        /// <summary>
        /// Check if the deck should burn the pickup pile
        /// </summary>
        /// <param name="player">The player who's just placed the last card</param>
        private void CheckIfShouldBurn(Player player) {
            //if the top card is a ten, then burn the pile
            if (this._pickUpCards[0].CardValue == CardValue.Ten) {
                // log the message
                this._game.HUD.AddLogMessage(player.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_clear_pickup_ten], player.SkinColor);
                BurnCards();
                if(this._TRACE) Console.WriteLine("***** PLAYER " + player.PlayerNumber + " JUST BURNED THE PICKUP PILE *****");
                player.JustCancelledPile = true;
            } else if (this._pickUpCards.Count >= 4) {
                if (this._pickUpCards[0].CardValue == this._pickUpCards[1].CardValue &&
                    this._pickUpCards[0].CardValue == this._pickUpCards[2].CardValue &&
                    this._pickUpCards[0].CardValue == this._pickUpCards[3].CardValue) {
                    // log the message
                    this._game.HUD.AddLogMessage(player.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_clear_pickup_4_cards] + this._pickUpCards[0].CardValue + "s", player.SkinColor);
                    BurnCards();
                    if(this._TRACE) Console.WriteLine("***** PLAYER " + player.PlayerNumber + " JUST BURNED THE PICKUP PILE *****");
                    player.JustCancelledPile = true;
                }
            }
        }

        /// <summary>
        /// Burns all the pickup pile cards
        /// </summary>
        public void BurnCards() {
            this.BurnSpecificCards(this._pickUpCards);
        }

        /// <summary>
        /// Burns a specific list of cards
        /// </summary>
        /// <param name="cards">The cards to burn</param>
        public void BurnSpecificCards(List<Card> cards) {
            Console.WriteLine("+++");
            foreach (Card card in cards) {
                card.CardType = CardType.InDisposedPileCard;
                card.CanShowValue = false;
                card.CanMove = false;
                Console.WriteLine("\tBurning card " + card.CardDescription);
            }
            Console.WriteLine("+++");

            this._burnedCards.AddRange(cards);
            cards.Clear();
        }

        /// <summary>
        /// Shuffle the cards
        /// </summary>
        public void Shuffle() {
            // create a temp array of positions
            List<int> tempPos = new List<int>(_numCards);
            for (int i = 0; i < _numCards; i++)
                tempPos.Add(i);

            StringBuilder sb = new StringBuilder(300);

            int j = 0;
            // go through the card order array, and randomise the order
            foreach (Card card in this._cards) {
                int newPos = rand.Next(tempPos.Count); // get a random position
                sb.Append(j++ + " "); // add the cards original number so it can be identified
                card.Place = tempPos[newPos]; // switch the order
                sb.Append(card.Place + " "); // add the cards new place so we can switch them later
                tempPos.RemoveAt(newPos);
            }

            this.SortAndReset();

            this._shuffleOverNetwork = sb.ToString(); // hold the shuffle pos
            Console.WriteLine(this._shuffleOverNetwork);

            Console.WriteLine("===");
            foreach (Card card in this._cards)
                Console.WriteLine(card.CardDescription + " has a place of " + card.Place);
            Console.WriteLine("===");
        }

        /// <summary>
        /// Arrange the cards in the order received from the network
        /// </summary>
        /// <param name="sp">The card order in string form</param>
        public void FNArrangeShuffledCards(string sp) {
            string[] split = sp.Split(' '); // first split the string so the numbers can be arranged
            int i = 0;
            lock (this._cards) {
                foreach (Card card in this._cards) {
                    int pos = int.Parse(split[i++]); // get the position of the card to change
                    this._cards[pos].Place = int.Parse(split[i++]); // change the card pos
                }
                this.SortAndReset();
            }
        }

        /// <summary>
        /// Sort the cards, and reset the various properties and lists
        /// </summary>
        private void SortAndReset() {
            Console.WriteLine("Sorting and reseting the deck");
            // go through the card array, and reset the various flags
            foreach (Card card in this._cards) {
                card.CardType = CardType.InDeckCard; // make sure all of the cards in the deck are specified InDeckCards
                card.CanMove = true;
                card.CanShowValue = true;
                card.WithUser = false;
                card.Selected = false;
            }

            this._cards.Sort(); // sort the deck so the cards are in the right order

            this._numCardsLeftInDeck = 52; // reset the number of cards left in the deck
            this._deckCards.Clear(); // clear the references in the deck card array
            this._pickUpCards.Clear(); // clear the references in the pickup card array
            this._burnedCards.Clear(); // clear the references in the burned card array
        }

        /// <summary>
        /// Reset the deck
        /// </summary>
        public void Reset() {
            lock (this._cards) {
                foreach (Card card in this._cards)
                    card.Place = card.OriginalCardNum; // reset the place
                this.SortAndReset();
            }
        }

        /// <summary>
        /// Deal the cards out to each player
        /// </summary>
        /// <param name="shuffle">Whether the deck should be shuffled before hand or not</param>
        public void Deal(bool shuffle) {
            if(shuffle) Shuffle();
            //int range = 52;
            //Card[] cards = new Card[range];
            //for (int i = 0; i < range; i++) {
            //    this._cards[i].CardType = CardType.InHandCard;
            //    cards[i] = this._cards[i];
            //}
            //this._game.GetPlayer(0).GiveCards(cards, true);
            for (int i = 0; i < this._game.NumberOfPlayers; i++) {
                Card[] cards = new Card[9]; // create a temporary array
                for (int j = 0; j < 9; j++) { // nine cards are dealt to each player at the start

                    int n = (this._game.NumberOfPlayers * j) + i;
                    if (j < 3) {
                        this._cards[n].CardType = CardType.FaceDownCard; // if it's in the first three received, then it's face down
                        this._cards[n].CanShowValue = false; // can't show it's value when focused
                    } else if (j < 6)
                        this._cards[n].CardType = CardType.FaceUpCard; // if it's in the second three received, then it's face up
                    else
                        this._cards[n].CardType = CardType.InHandCard; // if it's in the final three received, then it's in the player's hand

                    cards[j] = this._cards[n]; // add the card to the temp array
                }
                Player player = this._game.GetPlayerAtPos(i);
                if (player != null) {
                    player.ClearAllCards(); // clear any cards that the player may already have
                    player.GiveCards(cards, true); // give the cards to the player
                } else
                    Console.WriteLine("There is no player with player number " + i + " so we can't give any cards");
            }
            this._numCardsLeftInDeck = 52 - (this._game.NumberOfPlayers * 9); // hold the number of cards left in the deck

            // go through the cards left in the pack for the deck cards
            foreach (Card card in this._cards)
                if (card.CardType == CardType.InDeckCard)
                    this._deckCards.Add(card);
            this._deckCards.Reverse(); // reverse the deck cards, so we pick from the top
        }

        /// <summary>
        /// Call update on each of the cards
        /// </summary>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        public void Update(TimeSpan deltaTime) {
            int j = 1;
            int k = this._pickUpCards.Count;
            int l = 1;
            lock(this._pickUpCards)
                foreach (Card card in this._pickUpCards) {
                    Vector3 pos = new Vector3(0.0f, 1.0f, 0.0f);
                    pos.Y += 0.2f * k;
                    card.Position = card.StartingPosition = pos;
                    card.QRotation = Quaternion.CreateFromYawPitchRoll(0.0f, -MathHelper.PiOver2, 0.0f);
                    k--;
                }
            lock(this._burnedCards)
                foreach (Card card in this._burnedCards) {
                    Vector3 pos = new Vector3(-25.0f, 1.0f, 0.0f);
                    pos.Y += 0.2f * l;
                    card.Position = card.StartingPosition = pos;
                    card.QRotation = Quaternion.CreateFromYawPitchRoll(0.0f, MathHelper.PiOver2, 0.0f);
                    l++;
                }
            for (int i = 0; i < _numCards; i++) {
                if (this._cards[i].CardType == CardType.InDeckCard) {
                    Vector3 pos = new Vector3(25.0f, 1.0f, 0.0f);// this._game.Table.Position;
                    pos.Y += 0.1f * j;
                    this._cards[i].Position = this._cards[i].StartingPosition = pos;
                    this._cards[i].QRotation = Quaternion.CreateFromYawPitchRoll(0.0f, MathHelper.PiOver2, 0.0f);
                    j++;
                }
                this._cards[i].Update(deltaTime);
            }
        }

        /// <summary>
        /// Render each card
        /// </summary>
        public void Render() {
            for (int i = 0; i < _numCards; i++)
                this._cards[i].Render();
        }
    }
}
