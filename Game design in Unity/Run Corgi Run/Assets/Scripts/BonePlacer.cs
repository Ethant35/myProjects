using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BonePlacer : TimedObjectPlacer
{
    public void Start()
    {
        minimumTimeToCreation = GameplayParameters.BoneMinimumTimeToCreation;
        maximumTimeToCreation = GameplayParameters.BoneMaximumTimeToCreation;
    }
}
