using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sounds : MonoBehaviour
{
    private AudioSource audioSource;
    public static Sounds Instance;
    public AudioClip GameStart;
    public AudioClip GameLose;
    public AudioClip LoseBall;

    private void Awake()
    {
        if (Instance != null && Instance != this)
            Destroy(this.gameObject);
        else
            Instance = this;
    }

    void Start()
    {
        audioSource = gameObject.GetComponent<AudioSource>();
    }

    public void PlayStart()
    {
        audioSource.PlayOneShot(GameStart);
    }
    public void PlayLose()
    {
        audioSource.PlayOneShot(GameLose);
    }
    public void PlayBallLost()
    {
        audioSource.PlayOneShot(LoseBall);
    }
}
