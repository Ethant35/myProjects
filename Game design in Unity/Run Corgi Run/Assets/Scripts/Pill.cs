using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pill : TimedObject
{
    public override void Start()
    {
        secondsOnScreen = GameplayParameters.PillSecondsOnScreen;
        base.Start();
    }
}
