using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slots : MonoBehaviour
{
    public TicTacToeGame TicTacToeGame;
    public List<Slot> SlotsList;
    private List<MarkerType> slotOccupants;
    public Sprite PawSprite;
    public Sprite PantherSprite;
    public Sprite BlankSprite;
    public void OnSlotClicked(Slot slot)
    {
        TicTacToeGame.OnSlotClicked(slot);
    }

    public void UpdateSlot(Slot slot, MarkerType markerType)
    {
        SetSlotImage(slot, markerType);
        SetSlotOccupant(slot, markerType);

    }

    private void SetSlotImage(Slot slot, MarkerType markerType)
    {
        if (markerType == MarkerType.Panther)
            slot.Mark(PantherSprite);
        else
            slot.Mark(PawSprite);
    }

    public void ResetSlotOccupants()
    {
        slotOccupants = new List<MarkerType>();
        for (int i = 0; i < 9; i++)
            slotOccupants.Add(MarkerType.None);
        
    }

    private void SetSlotOccupant(Slot slot, MarkerType markerType)
    {
        int slotIndex = slot.SlotNumber-1;
        slotOccupants[slotIndex] = markerType;
    }

    public void Reset()
    {
        ResetSlotOccupants();
        ResetSlotImages();
    }

    private void ResetSlotImages()
    {
        foreach (Slot slot in SlotsList)
            slot.Reset(BlankSprite);
    }

    public List<MarkerType> SlotOccupants()
    {
        return slotOccupants;
    }

    public Slot RandomFreeSlot()
    {
        List<int> emptySlotIndicies = FindEmptySlotIndices();
        int randomIndex = Random.Range(0, emptySlotIndicies.Count);
        int randomSlotIndex = emptySlotIndicies[randomIndex];
        return SlotsList[randomSlotIndex];

    }

    private List<int> FindEmptySlotIndices()
    {
        List<int> emptySlotIndices = new List<int>();
        for (int i = 0; i < SlotsList.Count; i++)
        {
            if (SlotsList[i].IsEmpty())
                emptySlotIndices.Add(i);
        }
            return emptySlotIndices;
    }

    public Slot GetSlot(int slotIndex)
    {
        return SlotsList[slotIndex];
    }




}
