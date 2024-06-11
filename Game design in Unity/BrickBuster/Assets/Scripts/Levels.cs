using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Levels : MonoBehaviour
{
    private int currentLevel = 0;
    private GameObject levelGameObject;
    public List<GameObject> levels;
    public Readouts Readouts;
    void Start()
    {
        levelGameObject = CreateLevel();
        UpdateLevelReadout();
    }

    public void GoToNextLevel()
    {
        currentLevel++;
        if (IsGameOver())
            return;
        LoadNextLevel();

    }

    public bool IsGameOver()
    {
        if (currentLevel == levels.Count)
            return true;
        return false;
    }

    private void LoadNextLevel()
    {
        if (levelGameObject != null)
            Destroy(levelGameObject);
        levelGameObject = CreateLevel();
        UpdateLevelReadout();
    }

    private void UpdateLevelReadout()
    {
        Readouts.ShowLevel(currentLevel+1);
    }

    private GameObject CreateLevel()
    {
        return Instantiate(levels[currentLevel], levels[currentLevel].transform.position, Quaternion.identity);
    }
}
