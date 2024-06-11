using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PanelClose : MonoBehaviour
{
    public GameObject Panel;
    public GameObject PanelLogos;
    public GameObject EasyButton;
    public GameObject MediumButton;
    public GameObject HardButton;


    public void ClosePanel()
    {
        Panel.gameObject.SetActive(false);
        PanelLogos.gameObject.SetActive(false);

    }

    public void CloseButtons()
    {
        EasyButton.gameObject.SetActive(false);
        MediumButton.gameObject.SetActive(false);
        HardButton.gameObject.SetActive(false);
    }

}
