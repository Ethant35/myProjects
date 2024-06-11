using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Background : MonoBehaviour
{
    private BoxCollider2D boxCollider;

    private Rigidbody2D rb;

    private float height;

    private float speed = 300f;

    private float startPosition = 3356;

    // Start is called before the first frame update
    void Start()
    {
        boxCollider = GetComponent<BoxCollider2D>();
        rb = GetComponent<Rigidbody2D>();

        height = boxCollider.size.y;
        rb.velocity = new Vector3(0, speed, 0);
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.y > startPosition)
        {
            Reposition();
        }
    }

    private void Reposition()
    {
        transform.position = new Vector3(transform.position.x, -5278f, transform.position.z);
    }
}