public class Songs extends Content {
    public Songs(String title, LinkedList<String> genre, int numStreams, ArtistAccount artistAccount){
        m_title=title;
        genres=genre;
        numTimesStreamed=numStreams;
        m_artistaccount=artistAccount;

    }
}
