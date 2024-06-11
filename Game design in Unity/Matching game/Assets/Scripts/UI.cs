using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UI : MonoBehaviour
{
    public CanvasGroup TitleCanvasGroup;
    public CanvasGroup GameOverCanvasGroup;
    public CanvasGroup ReadoutsCanvasGroup;

    public void ShowTitleScreen()
    {
        TitleCanvasGroup.alpha = 1;
        TitleCanvasGroup.blocksRaycasts = true;
        TitleCanvasGroup.interactable = true;
    }

    public void HideTitleScreen()
    {
        TitleCanvasGroup.alpha = 0;
        TitleCanvasGroup.blocksRaycasts = false;
        TitleCanvasGroup.interactable = false;
    }

    public void ShowReadouts()
    {
        ReadoutsCanvasGroup.alpha = 1;
        ReadoutsCanvasGroup.blocksRaycasts = true;
        ReadoutsCanvasGroup.interactable = true;
    }

    public void HideReadouts()
    {
        ReadoutsCanvasGroup.alpha = 0;
        ReadoutsCanvasGroup.blocksRaycasts = false;
        ReadoutsCanvasGroup.interactable = false;
    }

    public void ShowGameOver()
    {
        GameOverCanvasGroup.alpha = 1;
        GameOverCanvasGroup.blocksRaycasts = true;
        GameOverCanvasGroup.interactable = true;
    }

    public void HideGameOver()
    {
        GameOverCanvasGroup.alpha = 0;
        GameOverCanvasGroup.blocksRaycasts = false;
        GameOverCanvasGroup.interactable = false;
    }
}
