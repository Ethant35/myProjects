import java.util.LinkedList;
import java.util.Random;
public class Game {
    //Declaration of variables
    Dealer dealer;
    LinkedList<Card> starterPile;
    public Player player1;
    public Player player2;

    //Game constructor
    public Game(){
        dealer=new Dealer();
        starterPile=dealer.deals(1);
        player1=new Player(1,dealer,starterPile);
        player2=new Player(2,dealer,starterPile);
    }

    //Play method that returns a boolean and goes through all the game logic, winning conditions, adding up score etc
    public boolean play(){
        Card firstPlayerCard=null;
        Card secondPlayerCard=null;
        boolean isGameOver=false;
        if(player1.getHand().size()>0 && player2.getHand().size()>0){
            firstPlayerCard=player1.takeTurn();
            secondPlayerCard=player2.takeTurn();
        }

        else if (player1.getHand().size()==0 && player2.getHand().size()!=0){
            System.out.println("Player one has won");
            System.out.println("Player one's score was "+getScore(player2));
            isGameOver=true;
        }

        else if (player2.getHand().size()==0 && player1.getHand().size()!=0){
            System.out.println("Player two has won");
            System.out.println("Player two's score was "+getScore(player1));
            isGameOver=true;
        }

        else if (player2.getHand().size()!=0 && player1.getHand().size()!=0 && firstPlayerCard==null && secondPlayerCard==null){
            if (player2.getHand().size()<player1.getHand().size()){
                System.out.println("Second player has won");
                System.out.println("Player two's score was "+getScore(player1));
                isGameOver=true;

            }

            else if(player2.getHand().size()>player1.getHand().size() && firstPlayerCard==null && secondPlayerCard==null){
                System.out.println("First player has won");
                System.out.println("Player one's score was "+getScore(player2));
                isGameOver=true;
                
            }
        }
        return isGameOver;
    }

    //Method that uses switch to add up score based on the cards in the losing player's hand
    public int getScore(Player losingPlayer){
        LinkedList <Card> losingPlayerHand=losingPlayer.getHand();
        int score=0;
        for (int i=0;i<losingPlayerHand.size();i++){
            switch (losingPlayerHand.get(i).getValue()) {
                case 8:
                    score+=50;
                    break;
                case 10:
                    score+=10;
                    break;
                case 11:
                    score+=10;
                    break;
                case 12:
                    score+=10;
                    break;
                case 13:
                    score+=10;
                    break;
                case 14:
                    score+=1;
                    break;
                case 2:
                    score+=2;
                    break;
                case 3:
                    score+=3;
                    break;
                case 4:
                    score+=4;
                    break;
                case 5:
                    score+=5;
                    break;
                case 6:
                    score+=6;
                    break;
                case 7:
                    score+=7;
                    break;
                case 9:
                    score+=9;
                    break;
                default:
                    break;
            }
        }
        return score;
    }

    

}
