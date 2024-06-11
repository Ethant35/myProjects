using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TimedObjectPlacer : MonoBehaviour
{
    public GameObject Prefab;
    private bool isWaitingToCreate = false;
    protected int minimumTimeToCreation = 1;
    protected int maximumTimeToCreation = 3;
    public virtual void Place()
    {
        Instantiate(Prefab, ScreenPositionTools.RandomWorldLocation(), Quaternion.identity);
    }

    void Update()
    {
        if (!isWaitingToCreate)
        {
            StartCoroutine(CountdownUntilCreation());
            isWaitingToCreate = true;
        }

    }

    IEnumerator CountdownUntilCreation()
    {

        yield return new WaitForSeconds(Random.Range(minimumTimeToCreation, maximumTimeToCreation));
        Place();
        isWaitingToCreate = false;
    }
}
