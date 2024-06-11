import java.util.Random;
import java.util.random.*;
public class Album extends ContentCollection {
    Random rand=new Random();
    String albumName;
    LinkedList<Songs> albumContents;
    public Album(String name, LinkedList<Songs> songs){
        albumName=name;
        albumContents=songs;
    }

    public Song shuffle(){
        random=rand.nextInt(this.albumContents)
        return this.albumContents.get(random);
    }
}
