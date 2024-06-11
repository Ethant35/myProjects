//Ethan Tarnarider
//tarnarider@chapman.edu
//CPSC 231-02
//2365982

public class TestCard {
    public static void main(String[] args) {
//Dealer object creation        
        Dealer dealertest=new Dealer();
//New deck object creation        
        Deck deck=new Deck();
//Calling deck's toString and size        
        System.out.println(deck.toString());
        System.out.println(deck.Size());
//Calling and print deck's deal method and checking the deck's size after dealing once        
        Card r=deck.deal();
        System.out.println(r);
        System.out.println(deck.Size());
//Initializing new deck object to use with dealer class methods        
        Deck deck2=new Deck();
//Dealing a hand of four cards and then checking the size and toString of the original deck to make sure it is what it should be
        System.out.println(dealertest.deals(4));
        System.out.println(dealertest.size());
        System.out.println(dealertest.toString());
    }
}
