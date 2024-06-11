using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Card : MonoBehaviour
{
    public Sprite frontImage;
    public Sprite backImage;
    private bool isFlipped;
    private bool isFlipping;
    public Game game;

    private void Start()
    {
        game = GameObject.FindObjectOfType<Game>();
    }

    public void flipToFront()
    {
        if (isFlipping || isFlipped || !game.IsOkToFlip())
        {
            print("Card.flipToFront - couldn't flip to front: isFlipping = " + isFlipping + ", isFlipped = " + isFlipped +
                ", game.IsOkToFlip = " + game.IsOkToFlip());
            return;
        }

        game.addToFlippedCards(this);
        reveal();

        //Tell the game to add it to the list of flipped cards
        //Turn it over
    }

    public void flipToBack()
    {
        //Turn card back over
        print("Card.flipToBack: isFlipping = " + isFlipping + ", isFlipped = " + isFlipped);
        if (isFlipping || !isFlipped)
        {
            print("Card.flipToBack - couldn't flip to back: isFlipping = " + isFlipping + ", isFlipped = " + isFlipped);
            return;
        }

        hide();

    }


    public void reveal()
    {
        //Turn over all cards
        isFlipping = true;
        StartCoroutine(flipToFrontCoroutine());

    }

    public void hide()
    {
        isFlipping = true;
        StartCoroutine(flipToBackCoroutine());

    }

    IEnumerator flipToBackCoroutine()
    {
        if (gameObject is not null)
        {
            while (gameObject.transform.rotation.eulerAngles.y > 90)
            {
                rotateOneClick(-1, 90);
                yield return null;
            }
            showBackSprite();
            while (gameObject.transform.rotation.eulerAngles.y > 0)
            {
                rotateOneClick(-1, 0);
                yield return null;
            }
            print("done with flipToBackCoroutine");
            isFlipping = false;
            isFlipped = false;
        }
    }

    public void reset()
    {
        gameObject.transform.eulerAngles = new Vector3(0, 0, 0);
        isFlipped = false;
        isFlipping = false;
        showBackSprite();
    }

    IEnumerator flipToFrontCoroutine()
    {
        //Rotate 90 degrees
        //When it is 90 degrees, swap sprite
        //Keep rotating until 180 degrees
            while (gameObject.transform.rotation.eulerAngles.y < 90)
            {
                rotateOneClick(1, 90);
                yield return null;
            }
            showFrontSprite();
            while (gameObject.transform.rotation.eulerAngles.y < 180)
            {
                rotateOneClick(1, 180);
                yield return null;
            }
        print("done with flipToFrontCoroutine");
            isFlipping = false;
            isFlipped = true;
        
    }

    public void rotateOneClick(int direction, float targetAngle)
    {
        float newRotation = gameObject.transform.eulerAngles.y+(1*(float) direction);
        newRotation = keepWithinAngle(targetAngle, newRotation, direction);
        gameObject.transform.eulerAngles = new Vector3(gameObject.transform.eulerAngles.x, newRotation, gameObject.transform.eulerAngles.z);
        
    }

    private float keepWithinAngle(float targetAngle, float currentRotation, int direction)
    {
        if (direction == 1)
        {
            if (currentRotation > targetAngle)
            {
                currentRotation = targetAngle;
            }
        }

        else if (direction == -1)
        {
            if (currentRotation < targetAngle)
            {
                currentRotation = targetAngle;
            }
        }
        return currentRotation;
    }

    private void showFrontSprite()
    {
        gameObject.GetComponent<Image>().sprite = frontImage;
        gameObject.GetComponent<Image>().transform.localScale = new Vector3(-1, 1, 1);
    }

    private void showBackSprite()
    {
        gameObject.GetComponent<Image>().sprite = backImage;
        gameObject.GetComponent<Image>().transform.localScale = new Vector3(1, 1, 1);
    }

    public Vector3 GetWorldPosition()
    {
        return gameObject.transform.position;
    }


}
