using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Moonshine : TimedObject
{
    public override void Start()
    {
        secondsOnScreen = GameplayParameters.MoonshineSecondsOnScreen;
        base.Start();
    }
}
