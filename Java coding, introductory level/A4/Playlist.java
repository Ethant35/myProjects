import java.util.random.*;
import java.util.LinkedList;
public class Playlist extends Songs {
    String playlistName;
    LinkedList<Songs> songs;
    public Playlist(String name, LinkedList<Songs> song;){
        songs=song;
        playlistName=name;
    }

    public Song shuffle(){
        random=rand.nextInt(this.songs)
        return this.songs.get(random);
    }
    
    public void addContent(Songs track){
        this.songs.add(track);
    }
    public void removeContent(Songs track){
        this.songs.remove(track);
    }
}
