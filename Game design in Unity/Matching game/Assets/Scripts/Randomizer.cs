using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Randomizer : MonoBehaviour
{
    public List<Image> Images;
    public List<Sprite> DogList;
        
    private List<Sprite> randomizedCardSprites;

    // Start is called before the first frame update
    void Start()
    {
        RandomizeSprite();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    //create something to keep track of which sprites are in which slots
    // create list of 1-8 sprites
    // goes through cards and picks random sprite from the list
    // if 2 of those sprites exist after, reomove that sprite from the list
    //continue till all slots are filled
    //reset list for next shuffle


    public void RandomizeSprite()
    {
        // make a list of all the cards
        // this is the list we draw from when making the random list
        // 1  2  3  4  1  2  3  4 etc
        List<Sprite> masterListTwoOfEachCard = new List<Sprite>();
        foreach (Sprite sprite in DogList)
        {
            masterListTwoOfEachCard.Add(sprite);
            masterListTwoOfEachCard.Add(sprite);
        }
        // dogpicture1, dogpicture1, dogpicture2, dogpicture2, dogpicture3, dogpicture3...
        randomizedCardSprites = new List<Sprite>();

        while (masterListTwoOfEachCard.Count != 0)
        {
            int randomSlot = Random.Range(0, masterListTwoOfEachCard.Count);
            randomizedCardSprites.Add(masterListTwoOfEachCard[randomSlot]);
            masterListTwoOfEachCard.RemoveAt(randomSlot);
        }

        for (int i = 0; i < Images.Count; i++)
        {
            Images[i].sprite = randomizedCardSprites[i];
        }
    }
}
    



