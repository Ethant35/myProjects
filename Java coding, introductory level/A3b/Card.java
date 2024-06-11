//Ethan Tarnarider
//tarnarider@chapman.edu
//CPSC 231-02
//2365982

public class Card {
//Definitions of static variables that are responsible for the suits of the card, along with the face value cards    
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;
    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;
//Defining two member variables, one to store the suit of the card and one to store the numericla value    
    int m_suit;
    int m_value; 
//Two methods to set and get the suit member variable     
    public int getSuitValue() {
        return m_suit;
      }
      public void setSuitValue(int suitValue) {
        m_suit = suitValue;
      }
//Two methods to set and get the value member variable         
      public int getValue() {
        return m_value;
      }
      public void setValue(int Value) {
        m_value = Value;
      }  
//Default constructor      
      public Card(){
        m_suit=0;
        m_value=0;
    }
//Overloaded constructor that sets the value and suit of a card    
    public Card(int Value, int suitValue){
        m_suit=suitValue;
        m_value=Value;
    }
//toString method that when called on a card object, uses two switch statements to change from a numerical suit or card value
//to the appropriate number in words and suit in words
    public String toString(){
        String c="";
        String cardValue="";
        String cardSuit="";
        switch (m_value) {
            case (2):
                cardValue+="2 of";
                break;
            case (3):
                cardValue+="3 of";
                break;
            case (4):
                cardValue+="4 of";
                break;
            case (5):
                cardValue+="5 of";
                break;
            case (6):
                cardValue+="6 of";
                break;
            case (7):
                cardValue+="7 of";
                break;
            case (8):
                cardValue+="8 of";
                break;
            case (9):
                cardValue+="9 of";
                break;
            case (10):
                cardValue+="10 of";
                break;
            case (11):
                cardValue+="Jack of";
                break;
            case (12):
                cardValue+="Queen of";
                break;
            case (13):
                cardValue+="King of";
                break;
            case (14):
                cardValue+="Ace of";
                break;
        }

        switch (m_suit){
            case (0):
                cardSuit+=" Hearts";
                break;
            case (1):
                cardSuit+=" Spades";
                break;
            case (2):
                cardSuit+=" Clubs";
                break;
            case (3):
                cardSuit+=" Diamonds";
                break;
        }

        return cardValue+cardSuit;

    }
//Equals method    
    public boolean equals(Object o) {
        if (this == o) {
          return true;
        }
        if (!(o instanceof Card)) {
          return false;
        }
        Card p = (Card) o;
        return ((this.m_value == (p.m_value)));
    }

//Copy constructor that makes a deep copy    
    public Card(Card otherCard){
        m_suit=otherCard.m_suit;
        m_value=otherCard.m_value;
    }
}
