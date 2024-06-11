import java.util.LinkedList;
public class Content implements Comparable<Content> {
    String m_title;
    ArtistAccount m_artistaccount;
    LinkedList<String> genres;
    int numTimesStreamed;
    protected void Play(){
        this.numTimesStreamed+=1;
    }

    @Override
    public int compareTo(Content content){
        return this.numTimesStreamed.compareTo(content.numTimesStreamed);
    }

}
