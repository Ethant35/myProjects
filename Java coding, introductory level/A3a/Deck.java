//Ethan Tarnarider
//tarnarider@chapman.edu
//CPSC 231-02
//2365982

import java.util.LinkedList;
import java.util.Random;
public class Deck{
//Initializing the linked list of cards    
    LinkedList<Card> m_cards; 
    public Deck(){
//For loop that goes through all four suits and all 13 card values and creates a card for every single combination and adds it
//to the linked list of cards that acts as a deck
        m_cards=new LinkedList<Card>();
        for (int i=0;i<4;i++){
            for (int j=2;j<15;j++){
                m_cards.add(new Card(j,i));
            }
        }
    }
//Setter and getter methods for the LinkedList of cards    
    public void setCards(LinkedList<Card> cards) {
        m_cards = cards;
      }
      public LinkedList<Card> getCards() {
        return m_cards;
      }

//Copy constructor for a deck that uses the addAll method of LinkedLists    
      public Deck (Deck deck){
        m_cards=new LinkedList<Card>();
        m_cards.addAll(deck.getCards());
    }
//toString method that uses the toString method of LinkedLists
    public String toString(){
        return m_cards.toString();
    }
//Size method that uses the size method of LinkedLists
    public int Size(){
        return m_cards.size();
    }
//Deal method that simulates dealing a random card from the deck and returns it
    public Card deal(){
        Random rand=new Random();
        int randomCardVal=rand.nextInt(m_cards.size());
        m_cards.remove(randomCardVal);
        return m_cards.get(randomCardVal);

    }
        
}
