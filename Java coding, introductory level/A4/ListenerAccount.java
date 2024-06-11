import java.util.LinkedList;

public class ListenerAccount extends Account {
    LinkedList<ContentCollection> favorites;
    public ListenerAccount(String name, LinkedList<Contentcollection> favorite){
        m_name=name;
        favorites=favorite;

    }

    public void favorite(ContentCollection contentCollection){
        favorites.add(contentCollection);
    }
}
