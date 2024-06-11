using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyboardInput : MonoBehaviour
{
    public Corgi Corgi;
    public PoopPlacer PoopPlacer;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.W))
        {
            Corgi.MoveManually(new Vector2(0, 1));
        }

        if (Input.GetKey(KeyCode.S)){
            Corgi.MoveManually(new Vector2(0, -1));
         }
        if (Input.GetKey(KeyCode.D))
        {
            Corgi.MoveManually(new Vector2(1, 0));
        }

        if (Input.GetKey(KeyCode.A))
        {
            Corgi.MoveManually(new Vector2(-1, 0));
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            PoopPlacer.Place(Corgi.transform.position);
        }
    }
}
