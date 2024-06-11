public class CrazyEightsDriver {
    public static void main(String[] args) {
        Game game=new Game();
        do {
            //keep playing
            System.out.println("Sp"+game.starterPile);
            System.out.println("p1 hand"+game.player1.getHand());
            System.out.println("p2 hand"+game.player2.getHand());
        }while (!game.play());
            
    }
}
