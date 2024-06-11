using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PillPlacer : TimedObjectPlacer
{
    public void Start()
    {
        minimumTimeToCreation = GameplayParameters.PillMinimumTimeToCreation;
        maximumTimeToCreation = GameplayParameters.PillMaximumTimeToCreation;
    }
}
