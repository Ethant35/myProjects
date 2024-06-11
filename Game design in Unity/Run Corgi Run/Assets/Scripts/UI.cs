using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UI : MonoBehaviour
{
    public Text ScoreText;
    public Text TimeText;
    public void ShowScore(int score)
    {
        ScoreText.text = score.ToString();
    }

    public void ShowTime(string time) {
        TimeText.text = time;
    }

    public void Reset()
    {
        ScoreText.text = "0";
        TimeText.text = "00:00";
    }


}
