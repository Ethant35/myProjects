using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Readouts : MonoBehaviour
{
    public Text Matches;
    
    public void Reset(int startingMatches)
    {
        ShowMatches(0);
    }

    public void ShowMatches(int matches)
    {
        if (matches < 0)
            matches = 0;
        Matches.text = "Matches: " + matches + "/8";
    }

    
}