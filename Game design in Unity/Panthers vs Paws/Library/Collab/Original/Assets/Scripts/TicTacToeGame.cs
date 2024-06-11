using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TicTacToeGame : MonoBehaviour
{
    public Slots Slots;
    private MarkerType currentMarkerType;
    private int numberOfTurnsPlayed;
    public TicTacToeResolver TicTacToeResolver;
    public TurnDisplay TurnDisplay;
    public WinnerDisplay WinnerDisplay;
    public GameMode GameMode;
    private MarkerType firstPlayerMarkerType;
    private bool isWaitingForComputerToPlay;
    public Sounds Sounds;
    // Start is called before the first frame update
    void Start()
    {
        Reset();
        currentMarkerType = MarkerType.Panther;
    }

    public void OnSlotClicked(Slot slot)
    {
        if(!isWaitingForComputerToPlay)
            PlaceMarkerInSlot(slot);   
    }

    public void OnResetButtonClicked()
    {
        Sounds.PlayResetButtonSound();
        Reset();
    }

    public void Reset()
    {
        ResetPlayers();
        ResetDisplays();
        Sounds.PlayResetButtonSound();
        ResetSlots();
        numberOfTurnsPlayed = 0;
    }

    public void ChangeOpponent()
    {
        Reset();
    }

    private void ResetSlots()
    {
        Slots.Reset();
    }

    private void SeeIfComputerShouldPlay()
    {
        if (IsHumanTurn())
            return;
        if (IsPlayingComputerOpponent())
            PlayComputerTurn();

    }

    private bool IsPlayingComputerOpponent()
    {
        return GameMode.GetOpponentType() != OpponentType.Human;
    }

    private void PlayComputerTurn()
    {
        StartCoroutine(PauseForComputerPlayer());

    }

    IEnumerator PauseForComputerPlayer()
    {
        isWaitingForComputerToPlay = true;
        float secondsToWait = Random.Range(0.5f, 1f);
        yield return new WaitForSeconds(secondsToWait);
        isWaitingForComputerToPlay = false;
        PlayComputerTurnAfterPause();
    }

    private void PlayComputerTurnAfterPause()
    {
        if (GameMode.GetOpponentType() == OpponentType.EasyComputer)
        {
            PlayEasyComputerMove();
        }
        else if (GameMode.GetOpponentType() == OpponentType.HardComputer)
        {
            PlayHardComputerMove();
        }

    }

    private void PlayHardComputerMove()
    {
        bool hasWon = TryToWin();
        if (hasWon)
            return;
        bool hasBlocked = TryToBlock();
        if (hasBlocked)
            return;
        PlayMarkerInRandomSlot();

    }

    private bool TryToWin()
    {

        return TryToPlayBestMoveForPlayer(currentMarkerType);
    }

    private bool TryToBlock()
    {
        return TryToPlayBestMoveForPlayer(firstPlayerMarkerType);
    }

    private bool TryToPlayBestMoveForPlayer(MarkerType markerType)
    {
        int bestSlotIndex = TicTacToeResolver.FindBestSlotIndexForPlayer(Slots.SlotOccupants(), markerType);
        if (bestSlotIndex != -1)
        {
            PlaceMarkerInSlot(Slots.GetSlot(bestSlotIndex));
            return true;
        }
        return false;
    }

    private void PlayEasyComputerMove()
    {
        PlayMarkerInRandomSlot();
    }

    private void PlayMarkerInRandomSlot()
    {
        Slot slot = Slots.RandomFreeSlot();
        PlaceMarkerInSlot(slot);
    }

    private bool IsHumanTurn()
    {
        return currentMarkerType == firstPlayerMarkerType;
    }

    private void ResetPlayers()
    {
        TicTacToeResolver.Reset();
        RandomizePlayer();
        firstPlayerMarkerType = currentMarkerType;
        isWaitingForComputerToPlay = false;
    }

    private void PlaceMarkerInSlot(Slot slot)
    {
        if (GameNotOver())
        {
            updateSlotImage(slot);
            EndTurn();
            CheckForWinner();
        }
    }

    private void EndTurn()
    {
        if (GameNotOver())
            ChangePlayer();
        else
            ShowWinner();
    }

    private void ShowWinner()
    {
        PlayEndOfGameSound();
        WinnerDisplay.Show(TicTacToeResolver.Winner());
    }

    private void PlayEndOfGameSound()
    {
        if (TicTacToeResolver.Winner() == MarkerType.Tie)
            Sounds.PlayTieGameSound();
        else
            Sounds.PlayGameOverSound();
    }

    private void ChangePlayer()
    {
        if (currentMarkerType == MarkerType.Paw)
            currentMarkerType = MarkerType.Panther;
        else
            currentMarkerType = MarkerType.Paw;
        TurnDisplay.Show(currentMarkerType);
        SeeIfComputerShouldPlay();

    }

    private void updateSlotImage(Slot slot)
    {
        Slots.UpdateSlot(slot, currentMarkerType);
    }

    private void CheckForWinner()
    {
        numberOfTurnsPlayed++;
        if (numberOfTurnsPlayed < 5)
            return;
        TicTacToeResolver.CheckForEndOfGame(Slots.SlotOccupants());



    }

    private bool GameNotOver()
    {
        return TicTacToeResolver.NoWinner();
    }

    private void RandomizePlayer()
    {
        int randomnumber = Random.Range(1, 3);
        if (randomnumber == 1)
            currentMarkerType = MarkerType.Panther;
        else
            currentMarkerType = MarkerType.Paw;
    }

    public void ResetDisplays()
    {
        TurnDisplay.Reset(currentMarkerType);
        WinnerDisplay.Reset();
    }
}
