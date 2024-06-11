using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Corgi : MonoBehaviour
{
    public SpriteRenderer CorgiSpriteRenderer;
    private bool isDrunk = false;
    private bool isPlastered = false;
    public Sprite DrunkenSprite;
    public Sprite NormalSprite;
    private int randomStepsLeft = 0;
    private int lastRandomDirection = 0;
    public UI UI;
    public void Update()
    {
        if (isPlastered)
        {
            MoveRandomly();
        }
    }

    private void MoveRandomly()
    {
        int direction = lastRandomDirection;
        if (randomStepsLeft == 0)
        {
            direction = Random.Range(0, 4);
            randomStepsLeft = Random.Range(10, 30);
            lastRandomDirection = direction;
        }
        switch (direction)
        {
            case 0:
                Move(new Vector2(1, 0));
                break;
            case 1:
                Move(new Vector2(-1, 0));
                break;
            case 2:
                Move(new Vector2(0, 1));
                break;
            case 3:
                Move(new Vector2(0, -1));
                break;
        }
    }

    public void Move(Vector2 direction)
    {
        direction = ApplyDrunkenness(direction);
        Vector3 amountToMove = CalculateAmountToMove(direction);
        CorgiSpriteRenderer.transform.Translate(amountToMove);
        FaceCorrectDirection(direction);
        KeepOnScreen();
    }

    public void MoveManually(Vector2 direction)
    {
        if (isPlastered)
        {
            return;
        }
        Move(direction);
        
    }

    private Vector3 CalculateAmountToMove(Vector2 direction)
    {
        float amountX = direction.x * GameplayParameters.CorgiMoveAmount;
        float amountY = direction.y * GameplayParameters.CorgiMoveAmount;
        return new Vector3(amountX, amountY, 0);
    }

    private Vector2 ApplyDrunkenness(Vector2 direction)
    {
        if (isDrunk)
        {
            direction.x = direction.x * -1;
            direction.y = direction.y * -1;
            
        }
        return direction;
    }

    private void FaceCorrectDirection(Vector2 direction)
    {
        if (direction.x == 1)
            CorgiSpriteRenderer.flipX = false;

        else if (direction.x == -1)
            CorgiSpriteRenderer.flipX = true;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Beer") {
            GetDrunk();
        }
        if (collision.gameObject.tag == "Pill")
        {
            SoberUp();
        }

        if (collision.gameObject.tag == "Bone")
        {
            ScoreKeeper.AddToScore(1);
            UI.ShowScore(ScoreKeeper.GetScore());
        }

        if (collision.gameObject.tag == "Whiskey")
        {  
            GetPlastered();
        }

        Destroy(collision.gameObject);

    }

    private void Inebriate()
    {
        SwitchToDrunkenSprite();
        StartSoberUpTimer();
    }


    private void GetPlastered()
    {
        isPlastered = true;
        Inebriate();
    }

    private void SoberUp()
    {
        SwitchToNormalSprite();
        isDrunk = false;
        isPlastered = false;
    }

    private void SwitchToNormalSprite()
    {
        CorgiSpriteRenderer.sprite = NormalSprite;
    }


    private void SwitchToDrunkenSprite()
    {
        CorgiSpriteRenderer.sprite = DrunkenSprite;
    }

    private void GetDrunk()
    {
        Inebriate();
        isDrunk = true;
    }

    private void StartSoberUpTimer()
    {
        StartCoroutine(WaitToSoberUp());
    }

    IEnumerator WaitToSoberUp()
    {
        yield return new WaitForSeconds(5);
        SoberUp();
    }

    private void KeepOnScreen()
    {
       CorgiSpriteRenderer.transform.position= SpriteTools.ConstrainToScreen(CorgiSpriteRenderer);
    }

    }

