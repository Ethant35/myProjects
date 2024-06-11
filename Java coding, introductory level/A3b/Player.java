import java.util.LinkedList;
import java.util.Random;

public class Player {
    //Initializing random, playernumber variable, dealer, starter pile and hand
    Random rand=new Random();
    int playerNum;
    Dealer dealer;
    LinkedList<Card> starterPile;
    private LinkedList<Card> m_hand;

    //Hand getter and setter
    public LinkedList<Card> getHand() {
        return m_hand;
      }
    public void setHand(LinkedList<Card> hand) {
        m_hand = hand;
      }
    //Default and overloaded constructor that takes in playernumber, the dealer and the starterpile
    public Player(){
    }
    public Player(int playernum,Dealer dealer,LinkedList<Card> starterpile){
        playerNum=playernum;
        starterPile=starterpile;
        this.dealer= dealer;
        m_hand=dealer.deals(5);
    }
    //Take turn method which uses a foreach loop to iterate through cards in the player's hard, checking if they have a playable card or 8 or
    //8 and playable, in which case it uses the random object to roll the 10% chance to play it
    //Also removes the card from that player's hand and adds it to the starter pile
    public Card takeTurn(){
    //Variable initialization
        int randValue=rand.nextInt(10);
        Card cardToReturn=null;
        Card potentialEight=null;
        Card potentialPlayable=null;
        Card topCard=this.starterPile.getLast();
        int topCardSuit=topCard.getSuitValue();
        int topCardValue=topCard.getValue();
    //For each loop 
        for (Card card:this.getHand()){
            if (card.getSuitValue()==topCardSuit || card.getValue()==topCardValue){    
                potentialPlayable=card;
                
            }
            else if(card.getValue()==8){
                potentialEight=card;
            }
        }
        

        //While loop that checks if there are no playable and draws cards until there is a playable one and then sets the appropriate
        //Variable, does the same checks as the previous for loop
        while (potentialEight==null && potentialPlayable==null && dealer.size()!=0) {
                    LinkedList<Card> drawhand=dealer.deals(1);
                    System.out.println("Drawn card is "+drawhand.getLast());
                    this.getHand().addAll(drawhand);
                    Card justGot=drawhand.get(0);
                        if (justGot.getSuitValue()==topCardSuit || justGot.getValue()==topCardValue){    
                            potentialPlayable=justGot;
                            
                        }
                        else if(justGot.getValue()==8){
                            potentialEight=justGot;
                        }
            }
        //Ifs to check what card to return    
        if (potentialEight!=null && potentialPlayable==null){
            cardToReturn=potentialEight;

            }
    
        if (potentialPlayable!=null && potentialEight==null){
            cardToReturn=potentialPlayable;
            }
    
        if (potentialEight!=null && potentialPlayable!=null){
            if (randValue==9){
                cardToReturn=potentialEight;
                    }
                else{
                    cardToReturn=potentialPlayable;
                    }
            }

        
        
        if (cardToReturn!=null){
            m_hand.remove(cardToReturn);
            addToStarterPile(cardToReturn);
        }
        
        return cardToReturn;
                
        }

    //Method that returns void that changes the suit and prints what suit it was changed
        public void addToStarterPile(Card card){
            //Card starterPileIndex=starterPile.get(0);
            if (card.getValue()==8){
                int oldSuit=card.getSuitValue();
                int newSuit=getNewSuit();
                card.setSuitValue(newSuit);
                System.out.println("Switched from "+oldSuit+" to "+newSuit);
            }
            starterPile.add(card);
        }

    //Method that generates random variable for suit change
        public int getNewSuit(){
                int randsuit=rand.nextInt(3);
                return randsuit;
        }

    }  
