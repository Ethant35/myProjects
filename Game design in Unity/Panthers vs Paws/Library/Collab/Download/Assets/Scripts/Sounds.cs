using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sounds : MonoBehaviour
{
    public AudioSource AudioSource;
    public AudioClip ResetButtonClip;
    public void PlayResetButtonSound()
    {
        AudioSource.clip = ResetButtonClip;
        AudioSource.Play();
    }
}
