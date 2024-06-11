
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Countdown : MonoBehaviour

{
    float initialTime = 100;
    float Seconds = 0;
    float currentTime;
    public Text timerText;
    // Start is called before the first frame update
    private bool isStarted = false;
    private bool isGameOver = false;
    private bool TimerPastZero = false;

    public void EasyClick()
    {
        initialTime = 120;
        Seconds = 0;
        isGameOver = false;
        TimerPastZero = false;
    }

    public void MediumClick()
    {
        initialTime = 60;
        Seconds = 0;
        isGameOver = false;
        TimerPastZero = false;
    }

    public void HardClick()
    {
        initialTime = 40;
        Seconds = 0;
        isGameOver = false;
        TimerPastZero = false;
    }

    public void Reset()
    {
        isGameOver = false;
        isStarted = false;
    }

    public void StartTimer()
    {
        isStarted = true;
    }

    void Update()
    {
        if (isStarted && !isGameOver)
        {
            Seconds += Time.deltaTime;
            currentTime = initialTime - Seconds;

            if (currentTime < 0)
                currentTime = 0;

            timerText.text = "Time: " + (int)currentTime + "s";
            bool TimerPastZero = false;

            if (currentTime <= 0)
            {
                if (TimerPastZero == false)
                    isGameOver = true;
                    TimerPastZero = true;
            }
            else
                TimerPastZero = true;
        }

    }

    // Update is called once per frame

    public bool IsGameOver()
    {
        return isGameOver;
    }


}

