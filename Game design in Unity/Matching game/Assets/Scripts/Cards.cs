using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cards : MonoBehaviour
{
    public SpriteRenderer SpriteRenderer;
    int counter;
    public SpriteRenderer Button1SpriteRenderer;
    public SpriteRenderer Button2SpriteRenderer;
    int score = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public bool checkIfSame(SpriteRenderer button1SpriteRenderer, SpriteRenderer button2SpriteRenderer)
    {
        if (button1SpriteRenderer.sprite = button2SpriteRenderer.sprite)
        {
            return true;
        }
        return false;
    }

    public void ifSame()
    {
        if (checkIfSame(Button1SpriteRenderer,Button2SpriteRenderer))
        {
            score += 1;
            //do fx
            Button1SpriteRenderer.gameObject.SetActive(false);
            Button2SpriteRenderer.gameObject.SetActive(false);
        }

        //do you didn't get a match fx
        //flip the cards back over
    }

    //Keep track of which cards have been clicked on, needs to know card 1 and card 2 clicked
    //Once both are clicked it needs to be able to check if they are the same
    //And if they are cards need to be hidden and points need to increase
    //If not, the two cards need to be reset to how they were at the beginning
}
