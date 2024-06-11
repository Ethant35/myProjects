using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bone : TimedObject
{
    public override void Start()
    {
        secondsOnScreen = GameplayParameters.BoneSecondsOnScreen;
        base.Start();
    }
}
