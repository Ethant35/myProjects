using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoonshinePlacer : TimedObjectPlacer
{
    public void Start()
    {
        minimumTimeToCreation = GameplayParameters.MoonshineMinimumTimeToCreation;
        maximumTimeToCreation = GameplayParameters.MoonshineMaximumTimeToCreation;
    }

    public override void Place()
    {
        Instantiate(Prefab, ScreenPositionTools.RandomTopOfScreenWorldLocation(), Quaternion.identity);
    }
}
