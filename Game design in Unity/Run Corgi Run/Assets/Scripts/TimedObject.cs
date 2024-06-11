using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TimedObject : MonoBehaviour
{
    protected int secondsOnScreen=2;   
    public virtual void Start()
    {
        StartCoroutine(CountdownUntilDeath());
    }

    IEnumerator CountdownUntilDeath()
    {

        yield return new WaitForSeconds(secondsOnScreen);
        Destroy(this.gameObject);
    }
}
