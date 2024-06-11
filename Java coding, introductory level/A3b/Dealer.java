//Ethan Tarnarider
//tarnarider@chapman.edu
//CPSC 231-02
//2365982

import java.util.LinkedList;
public class Dealer {
    private Deck m_deck;
//Constructor for a new deck    
    public Dealer(){
        m_deck=new Deck();
    }
//Method that creates a "hand" of cards by randomly selecting n amount of cards and returning those as a new LinkedList
//includes an if statement that checks for 0 cards in the deck
    public LinkedList<Card> deals(int n){
        LinkedList<Card> hand=new LinkedList<Card>();
        if (m_deck.size()!=0){
            for (int i = 0; i<n;i++){
                hand.add(m_deck.deal());
            }
        }
        else {
            return hand;
        }
        return hand;
    }
//Size method that uses the size method of LinkedLists
    public int size(){
        return m_deck.size();
    }
//toString method that uses the toString method of LinkedLists
    public String toString(){
        return m_deck.toString();
    }
}
