using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sounds : MonoBehaviour
{
    public AudioSource SoundEffectsSource;
    public AudioSource MusicSource;

    public AudioClip GameEndClip;
    public AudioClip LevelSelect;
    public AudioClip Match;
    public AudioClip Music;
    public AudioClip Woosh1;
    public AudioClip Woosh2;
    public AudioClip Woosh3;

    // Start is called before the first frame update
    void Start()
    {
        MusicSource.loop = true;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void PlayMusic()
    {
        MusicSource.PlayOneShot(Music);
    }

    public void PlayEndGameSound()
    {
        SoundEffectsSource.PlayOneShot(GameEndClip);
    }

    public void PlayMatchSound()
    {
        SoundEffectsSource.PlayOneShot(Match);
    }

    public void PlayWooshSound()
    {
        int whooshNumber = Random.Range(0, 3);
        if (whooshNumber == 0)
            SoundEffectsSource.PlayOneShot(Woosh1);
        else if (whooshNumber == 1)
            SoundEffectsSource.PlayOneShot(Woosh2);
        else
            SoundEffectsSource.PlayOneShot(Woosh3);
    }
}
