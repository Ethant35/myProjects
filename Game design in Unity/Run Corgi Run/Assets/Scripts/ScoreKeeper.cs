using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class ScoreKeeper 
{
    private static int score = 0;

    public static void AddToScore(int points)
    {
        score = score + points;
    }

    public static int GetScore()
    {
        return score;
    }
}
