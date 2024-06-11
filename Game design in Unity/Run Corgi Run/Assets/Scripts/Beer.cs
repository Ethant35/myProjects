using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Beer : TimedObject
{
    public override void Start()
    {
        secondsOnScreen = GameplayParameters.BeerSecondsOnScreen;
        base.Start();
    }
}
