using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PageControl : MonoBehaviour
{
    public List<Sprite> PageImages;
    public Image PageImage;
    public Text PageCaption;
    public Button NextButton;
    public Button PrevButton;

    private int currPage = 0;
    private List<string> PageCaptions;
    private string captionFilePath = "Assets/Art/captions.txt";

    // Start is called before the first frame update
    void Start()
    {
        LoadCaptions();
        TryHideButtons();
        UpdatePage();
    }

    public void OnNextClick()
    {
        currPage += 1;
        UpdatePage();
    }

    public void OnPrevClick()
    {
        currPage -= 1;
        UpdatePage();
    }

    private void TryHideButtons()
    {
        // check to see if we should hide next/prev button
        // check next page button
        if (currPage == 0)
        {
            PrevButton.gameObject.SetActive(false);
        }
        else
        {
            PrevButton.gameObject.SetActive(true);
        }

        if (currPage == PageCaptions.Count - 1)
        {
            NextButton.gameObject.SetActive(false);
        }
        else
        {
            NextButton.gameObject.SetActive(true);
        }
    }

    private void UpdatePage()
    {
        // update image and caption
        UpdatePageImage();
        UpdatePageCaption();
        TryHideButtons();
    }

    private void UpdatePageImage()
    {
        PageImage.sprite = PageImages[currPage];
    }

    private void UpdatePageCaption()
    {
        PageCaption.text = PageCaptions[currPage];
    }

    private void LoadCaptions()
    {
        PageCaptions = new List<string>();
        System.IO.StreamReader reader = new System.IO.StreamReader(captionFilePath);
        for (int i = 0; i < 8; ++i)
        {
            PageCaptions.Add(reader.ReadLine());
        }
        reader.Close();
        foreach (string s in PageCaptions)
        {
            print(s);
        }
    }
}
