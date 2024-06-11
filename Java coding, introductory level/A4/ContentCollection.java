import java.util.LinkedList;
public class ContentCollection implements Comparable<ContentCollection> {
    String m_title;
    LinkedList<Content> m_tracklist;

    public ContentCollection(){
        
    }
    public void Shuffle(){

    }

    @Override
    public int compareTo(Contentcollection contentcollection){
        return this.m_tracklist.Size().compareTo(content.contentcollection.Size());
    }
}
