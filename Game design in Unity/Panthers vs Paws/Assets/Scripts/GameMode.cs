using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameMode : MonoBehaviour
{
    public TicTacToeGame TicTacToeGame;
    private OpponentType currentOpponentType;
    public Sounds Sounds;
    void Start()
    {
        currentOpponentType = OpponentType.Human;
    }

    public void OnButtonPressed(int buttonNumber)
    {
        OpponentType opponentType = SetOpponentType(buttonNumber);
        ChangeOpponentType(opponentType);
    }

    private OpponentType SetOpponentType(int buttonNumber)
    {
        if (buttonNumber == 1)
            return OpponentType.EasyComputer;
        if (buttonNumber == 2)
            return OpponentType.Human;
        return OpponentType.HardComputer;
    }

    private void ChangeOpponentType(OpponentType opponentType)
    {
        if (opponentType != currentOpponentType)
        {
            Sounds.PlayGameModeSound();
            currentOpponentType = opponentType;
            TicTacToeGame.ChangeOpponent();
        }

    }

    public OpponentType GetOpponentType()
    {
        return currentOpponentType;
    }
}

