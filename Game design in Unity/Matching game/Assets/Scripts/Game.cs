using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Linq;

public class Game : MonoBehaviour
{
    public List<Card> flippedCards;
    public int matchCounter=0;
    public bool isOkToFlip;
    public Dealer dealer;
    public Sounds Sounds;
    public Countdown Countdown;
    public UI UI;
    private bool isWaitingToRestart = false;
    public Readouts readouts;
    public GameObject EffectPrefab;

    public void Update()
    {
        if (Countdown.IsGameOver() && !isWaitingToRestart)
        {
            dealer.reset();
            UI.ShowGameOver();
            isWaitingToRestart = true;
            StartCoroutine(WaitToRestartGame());
        }
    }

    IEnumerator WaitToRestartGame()
    {
        yield return new WaitForSeconds(3);
        Reset();
        isWaitingToRestart = false;
    }

    public void Start()
    {
        flippedCards = new List<Card>();
        Sounds.PlayMusic();
        Reset();
    }


    public void addToFlippedCards(Card card)
    {

        Sounds.PlayWooshSound();
        flippedCards.Add(card);
        print("adding to flipped cards - flippedcards count = " + flippedCards.Count);
        if (flippedCards.Count == 2)
        {
            isOkToFlip = false;
            bool isMatch = checkForMatch();
            if (isMatch)
            {
                matchCounter += 1;
                readouts.ShowMatches(matchCounter);
                foreach (Card c in flippedCards)
                {
                    Instantiate(EffectPrefab, c.GetWorldPosition() + new Vector3(0, 0, -100), Quaternion.identity);
                }
                flippedCards.Clear();
                print("found match, clearing flipped cards - flippedcards count = " + flippedCards.Count);
                isOkToFlip = true;
                if (hasWon())
                {
                    WinGame();
                }
            }

            else
            {
                print("no match, flippedcards count = " + flippedCards.Count);
                StartCoroutine(waitToFlipBack());
            }

        }

    }

    IEnumerator delayedFlip()
    {
        List<Card> allCards = GameObject.FindObjectsOfType<Card>().ToList();
        allCards.Reverse();
        for (int i = 0; i < allCards.Count; i++)
        {
            allCards[i].reveal();
            yield return new WaitForSeconds(.25f);
        }
    }

    IEnumerator delayedHide()
    {
        List<Card> allCards = GameObject.FindObjectsOfType<Card>().ToList();
        allCards.Reverse();
        for (int i = 0; i < allCards.Count; i++)
        {
            allCards[i].hide();
            yield return new WaitForSeconds(.25f);
        }
        isOkToFlip = true;
    }

    public void revealAllCards()
    {
        isOkToFlip = false;
        StartCoroutine(delayedFlip());
    }

    public void hideAllCards()
    {
        isOkToFlip = false;
        StartCoroutine(delayedHide());
    }

    IEnumerator waitToFlipBack()
    {
        yield return new WaitForSeconds(2);
        flippedCards[0].flipToBack();
        flippedCards[1].flipToBack();
        flippedCards.Clear();
        yield return new WaitForSeconds(1);
        print("end of waitToFlipBack: flippedCards.count = " + flippedCards.Count);
        isOkToFlip = true;
    }

    public bool checkForMatch()
    {
        if (flippedCards[0].frontImage == flippedCards[1].frontImage)
        {
            //print("Match");
            Sounds.PlayMatchSound();
            return true;
        }
        //print("No Match");
        return false;
    }

    public void Reset()
    {
        print("resetting");
        dealer.reset();
        matchCounter = 0;
        isOkToFlip = true;
        flippedCards = new List<Card>();
        Countdown.Reset();
        UI.HideGameOver();
        UI.HideReadouts();
        UI.ShowTitleScreen();
    }

    IEnumerator waitToResetAfterWin()
    {
        print("coroutine started");
        yield return new WaitForSeconds(2);
        Reset();
    }

    public void CheatWin()
    {
        WinGame();

    }

    public bool hasWon()
    {
        if (matchCounter == 8)
        {
            print("win detected");
            return true;
        }

        return false;
    }

    private void WinGame()
    {
        StartCoroutine(waitToResetAfterWin());
    }

    public void clicked()
    {
        dealer.deal();
        UI.HideTitleScreen();
        UI.ShowReadouts();
        PeekAtCards();
    }

    public bool IsOkToFlip()
    {
        if (flippedCards.Count < 2)
            return true;
        return false;
    }

    private void PeekAtCards()
    {
        isOkToFlip = false;
        RevealAllCardsFronts();
    }

    public void RevealAllCardsFronts()
    {

        List<Card> AllCards = GameObject.FindObjectsOfType<Card>().ToList();
        AllCards.Reverse();
        StartCoroutine(RevealAllCardsCoroutine(AllCards));
    }

    public void HideAllCardFronts()
    {
        List<Card> AllCards = GameObject.FindObjectsOfType<Card>().ToList();
        AllCards.Reverse();
        StartCoroutine(HideAllCardFronts(AllCards));
    }
    IEnumerator RevealAllCardsCoroutine(List<Card> AllCards)
    {
        foreach (Card card in AllCards)
        {
            card.reveal();
            yield return new WaitForSeconds(0.25f);
        }
        yield return new WaitForSeconds(3);
        HideAllCardFronts();
    }
    IEnumerator HideAllCardFronts(List<Card> AllCards)
    {
        foreach (Card card in AllCards)
        {
            card.hide();
            yield return new WaitForSeconds(0.25f);
        }
        isOkToFlip = true;
        Countdown.StartTimer();
    }



}
