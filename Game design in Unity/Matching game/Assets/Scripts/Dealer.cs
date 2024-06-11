using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;

public class Dealer : MonoBehaviour
{
    public GameObject CanvasGameObject;
    public GameObject PanelPrefab4x4;
    public GameObject CardPrefab;
    public Game game;

    public List<Sprite> pictures;
    private List<Card> cards = new();
    private GameObject Panel;

    public void deal()
    {
        
            MakePanel();
            AttachToCanvas();
            cards = new List<Card>();
            for (int i = 0; i < 16; i++)
            {
                GameObject card = Instantiate(CardPrefab);
                card.gameObject.transform.parent = Panel.transform;
                Card newCard = card.gameObject.GetComponent<Card>();
                newCard.game = game;
                cards.Add(newCard);
            }
            assignPicsToCards();
        

    
    

    }

    public void assignPicsToCards()
    {
        List<Sprite> shuffledPics=makePicsRandomized(pictures);
        for (int i = 0; i < cards.Count;i++)
        {
            cards[i].frontImage = shuffledPics[i];
        }
    }


    public void reset()
    {
        Destroy(Panel);
    }

    private void MakePanel()
    {
        Panel = Instantiate(PanelPrefab4x4, new Vector3(0, 0, 0), Quaternion.identity);
    }

    private void AttachToCanvas()
    {
        Panel.gameObject.transform.parent = CanvasGameObject.transform;
        Panel.gameObject.transform.localPosition = new Vector3(0, -60, 0);
    }

    private List<Sprite> makePicsRandomized(List<Sprite> spritesInOrder)
    {
        System.Random random = new System.Random();
        return spritesInOrder.OrderBy(a => random.Next()).ToList();
    }
}
