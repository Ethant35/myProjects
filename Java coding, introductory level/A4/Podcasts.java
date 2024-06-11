public class Podcasts extends Content {
    int m_episodeNum;
    public Podcasts(String title, LinkedList<String> genre, int numStreams, ArtistAccount aristAccount, int episodeNum){
        m_title=title;
        genres=genre;
        numTimesStreamed=numStreams;
        m_artistaccount=aristAccount;
        m_episodeNum=episodeNum;
    }
}
