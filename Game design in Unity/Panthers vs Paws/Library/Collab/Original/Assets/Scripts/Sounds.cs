using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sounds : MonoBehaviour
{
    public AudioSource AudioSource;
    public AudioClip ResetButtonClip;
    public AudioClip GameOverClip;
    public AudioClip TiegameClip;
    public AudioClip GameModeClip;
    public List<AudioClip> MarkerSoundClips;
    private List<int> markerSoundQueue;

    public void PlayResetButtonSound()
    {
        AudioSource.clip = ResetButtonClip;
        AudioSource.Play();
    }

    public void PlayGameOverSound()
    {
        AudioSource.clip = GameOverClip;
        AudioSource.Play();
    }

    public void PlayTieGameSound()
    {
        AudioSource.clip = TiegameClip;
        AudioSource.Play();
    }

    public void PlayGameModeSound()
    {
        AudioSource.clip = GameModeClip;
        AudioSource.Play();
    }


}
