using System;
using System.Collections.Generic;
using System.Text;

namespace SMOCG {
    /// <summary>
    /// This enum is for the state transitions in the game
    /// </summary>
    public enum GameState {
        /// <summary>
        /// default value, nothing is set yet
        /// </summary>
        None,

        /// <summary>
        /// Game has started but nothing is initialised yet
        /// </summary>
        Started,

        /// <summary>
        /// at the games splash screen
        /// </summary>
        SplashScreen,

        /// <summary>
        /// at the games main menu screen
        /// </summary>
        MainMenuScreen,

        /// <summary>
        /// where the player gets customised
        /// </summary>
        CustomisePlayer,

        /// <summary>
        /// choosing options
        /// </summary>
        Options,

        /// <summary>
        /// currently playing in a game
        /// </summary>
        Play
    }

    /// <summary>
    /// The enum for the states for the player while playing a match
    /// </summary>
    public enum PlayerInGameState {
        /// <summary>
        /// No state - the game hasn't started yet
        /// </summary>
        None,

        /// <summary>
        /// In the pre game state - the player is just after receiving his cards and can
        /// swap his hands cards with his face up cards
        /// </summary>
        PreGame,

        /// <summary>
        /// The player is playing from, and only from his hand cards
        /// </summary>
        HandCards,

        /// <summary>
        /// The player is playing from his face up cards
        /// </summary>
        FaceUpCards,

        /// <summary>
        /// The player is playing from his face down cards
        /// </summary>
        FaceDownCards,

        /// <summary>
        /// The player is out of the game
        /// </summary>
        Out
    }

    /// <summary>
    /// States used to control how the mouse displays to the user
    /// </summary>
    public enum CurrMouseState {
        /// <summary>
        /// default value, mouse isn't visible
        /// </summary>
        None,

        /// <summary>
        /// usual mouse pointer, mainly for viewing where the mouse is
        /// </summary>
        Pointer,

        /// <summary>
        /// mouse state for when the mouse is pressed down
        /// </summary>
        MouseDown,

        /// <summary>
        /// used to let the user know that their over something interactive
        /// </summary>
        Interactive
    }

    /// <summary>
    /// All the fonts used in the game
    /// </summary>
    public enum FontStyle {
        /// <summary>
        /// Use the large font size
        /// </summary>
        Large,

        /// <summary>
        /// Use the small font size
        /// </summary>
        Small,

        /// <summary>
        /// Use the smallest font size
        /// </summary>
        Smallest
    }

    /// <summary>
    /// The different GUI widgit types used in the game
    /// </summary>
    public enum GUI_widgit_type {
        /// <summary>
        /// no widgit
        /// </summary>
        GUI_WIDGIT_NONE,

        /// <summary>
        /// rectangular button type widgit
        /// </summary>
        GUI_WIDGIT_RECT_BUTTON,

        /// <summary>
        /// circular button type widgit
        /// </summary>
        GUI_WIDGIT_CIRCLE_BUTTON,

        /// <summary>
        /// text input type widgit
        /// </summary>
        GUI_WIDGIT_TEXT_INPUT,

        /// <summary>
        /// Background widgit type
        /// </summary>
        GUI_WIDGIT_BACKGROUND
    }

    /// <summary>
    /// the different GUI event types used in the game
    /// </summary>
    public enum GUI_event_type {
        /// <summary>
        /// no event type - null
        /// </summary>
        GUI_EVENT_NONE,

        /// <summary>
        /// a mouse over gui event
        /// </summary>
        GUI_EVENT_MOUSE_OVER,

        /// <summary>
        /// a mouse down gui event
        /// </summary>
        GUI_EVENT_MOUSE_DOWN,

        /// <summary>
        /// a mouse out gui event
        /// </summary>
        GUI_EVENT_MOUSE_OUT,

        /// <summary>
        /// a mouse up gui event
        /// </summary>
        GUI_EVENT_MOUSE_UP,

        /// <summary>
        /// a key down gui event
        /// </summary>
        GUI_EVENT_KEY_DOWN,

        /// <summary>
        /// a key up gui event
        /// </summary>
        GUI_EVENT_KEY_UP
    }

    /// <summary>
    /// The different types of hair models used by the player
    /// </summary>
    public enum PlayerHairType {
        /// <summary>
        /// No hair model
        /// </summary>
        Bald,

        /// <summary>
        /// Spikey hair model chosen
        /// </summary>
        Spikes
    }

    /// <summary>
    /// The different face textures used by the player
    /// </summary>
    public enum PlayerFaceTextures {
        /// <summary>
        /// The basic smiley face
        /// </summary>
        SmileyFace
    }

    /// <summary>
    /// The different colors that the player can choose to color his things
    /// </summary>
    public enum PlayerColorChoice {
        White,
        Black,
        Red,
        Purple,
        Blue,
        Green,
        Yellow,
        Orange,
        Caucassian,
        Brown
    }

    /// <summary>
    /// This enum is to hold the card values, arranged here in order and suit,
    /// although that isn't necessary for SMOCG
    /// </summary>
    public enum Cards {
        /// <summary>
        /// Clubs
        /// </summary>
        TwoOfClubs,
        ThreeOfClubs,
        FourOfClubs,
        FiveOfClubs,
        SixOfClubs,
        SevenOfClubs,
        EightOfClubs,
        NineOfClubs,
        TenOfClubs,
        JackOfClubs,
        QueenOfClubs,
        KingOfClubs,
        AceOfClubs,

        /// <summary>
        /// Diamonds
        /// </summary>
        TwoOfDiamonds,
        ThreeOfDiamonds,
        FourOfDiamonds,
        FiveOfDiamonds,
        SixOfDiamonds,
        SevenOfDiamonds,
        EightOfDiamonds,
        NineOfDiamonds,
        TenOfDiamonds,
        JackOfDiamonds,
        QueenOfDiamonds,
        KingOfDiamonds,
        AceOfDiamonds,

        /// <summary>
        /// Hearts
        /// </summary>
        TwoOfHearts,
        ThreeOfHearts,
        FourOfHearts,
        FiveOfHearts,
        SixOfHearts,
        SevenOfHearts,
        EightOfHearts,
        NineOfHearts,
        TenOfHearts,
        JackOfHearts,
        QueenOfHearts,
        KingOfHearts,
        AceOfHearts,

        /// <summary>
        /// Spades
        /// </summary>
        TwoOfSpades,
        ThreeOfSpades,
        FourOfSpades,
        FiveOfSpades,
        SixOfSpades,
        SevenOfSpades,
        EightOfSpades,
        NineOfSpades,
        TenOfSpades,
        JackOfSpades,
        QueenOfSpades,
        KingOfSpades,
        AceOfSpades
    }

    /// <summary>
    /// This enum is to arrange the card values in numerical order, so they can
    /// be tested against each other - to help decide whether the last move was
    /// legal or not
    /// </summary>
    public enum CardValue {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    }

    /// <summary>
    /// The different card types (i.e. their place in the game)
    /// this changes depending on where the card is at the time and helps to determine
    /// whether something is a legal move or not, i.e. you can't play a face down card
    /// before all your hand cards are played
    /// </summary>
    public enum CardType {
        /// <summary>
        /// One of the three cards face-down at the start of the game
        /// </summary>
        FaceDownCard,

        /// <summary>
        /// One of the three cards face-up at the start of the game.
        /// These cards can be swapped with any of the cards in your hand before the game starts
        /// </summary>
        FaceUpCard,

        /// <summary>
        /// Any cards that are held in your hand.
        /// These cards can be swapped with any of the faceup cards in front of you before the game starts
        /// </summary>
        InHandCard,

        /// <summary>
        /// Any of the cards in the center of the table, which can be picked up, or discarded
        /// </summary>
        InPickupPileCard,

        /// <summary>
        /// Any of the cards currently left in the deck, which players have to pick from when they place a card
        /// </summary>
        InDeckCard,

        /// <summary>
        /// Any of the cards that have been taken out of the game
        /// </summary>
        InDisposedPileCard
    }

    /// <summary>
    /// These are the different messages that can appear on your hud
    /// </summary>
    public enum HUDMessages {
        You_are_player_1,
        You_are_player_2,
        You_are_player_3,
        You_are_player_4,
        You_are_player_5,
        Select_hand_card,
        Select_faceup_card,
        Select_facedown_card,
        Select_multiple_cards,
        Click_pickup_pile_to_play,
        Player1s_go,
        Player2s_go,
        Player3s_go,
        Player4s_go,
        Player5s_go,
        Your_go,
        Can_pickup_anyway,
        Can_swap_faceup_hand_cards,
        Press_ready_to_begin,
        Press_deal_cards,
        Press_reset_game,
        Press_select_same_cards,
        Select_cards_to_switch_position,
        Ready_to_begin_1_other,
        Ready_to_begin_2_others,
        Ready_to_begin_3_others,
        Ready_to_begin_4_others
    }

    /// <summary>
    /// These are the different messages that can appear in the log
    /// </summary>
    public enum Log {
        Player_joined_game,
        Player_ready,
        Player_played_single_card,
        Player_played_multiple_cards,
        Player_picked_up,
        Player_clear_pickup_ten,
        Player_clear_pickup_4_cards,
        Player_out,
        Player_exited_game,
        Player_loser
    }
}
