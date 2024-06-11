using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ParticleDestory : MonoBehaviour
{

    private float timeAlive;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        timeAlive += Time.deltaTime;
        if (timeAlive > 3){
            Destroy(gameObject);
        }
    }
}
