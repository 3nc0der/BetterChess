#pragma once

#include "pieces.hpp"
#include "items.hpp"

#include <stdio.h>
#include <iostream>
#include <string.h>

class Item
{
	public:

		//creates a new item
		Item(int x, int y);

		//destroys the item
		~Item();

		//activates the item and releases its effect
		//this method is a pure virtual and therefore must be implemented by any child class
		virtual void activate() = 0;

		//takes care of every turn based variable the item has
		virtual void update();

		/*
		* getter & setter
		*/

		int getRemainingTurnsOnBoard() { return turnsLeftOnBoard; };

		int getRemainingTurnsActive() { return turnsLeftActivated; };

		bool getStatus() { return isActivated; };

		PIECES getPossesingUnit() { return activatingUnit; };

		ITEMS getItemType() { return itemType; };

		int getXPos() { return xPos; };
		int getYPos() { return yPos; };

		std::string getItemDesc() { return itemDesc; };

	private:

		//describes after how many turns this item will despawn
		int turnsLeftOnBoard;

		//tells if the item still lays on the board or was activated by a unit
		bool isActivated;

		//gives information about what type of unit collected the item
		PIECES activatingUnit;

		//tells what type of item this item is
		ITEMS itemType;

		//tells how long the item remains activated
		int turnsLeftActivated;

		//where the item lays on the board
		int xPos, yPos;

		//describes the item in a prewritten text
		std::string itemDesc;
};
