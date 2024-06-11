using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BeerPlacer : TimedObjectPlacer
{

    public void Start()
    {
        minimumTimeToCreation = GameplayParameters.BeerMinimumTimeToCreation;
        maximumTimeToCreation = GameplayParameters.BeerMaximumTimeToCreation;
    }
}
