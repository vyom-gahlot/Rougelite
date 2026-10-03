#pragma once

#include <string>

struct Item{

    std::string name {};
    std::string type {};
    int tier {};


    int hp {};
    int attack {};
    int defense {};
    int speed {};


};

//weapons
extern Item Rusty_Shortsword;
extern Item Balanced_Shortsword;
extern Item Windsteel_Rapier;
extern Item Iron_Cleaver;
extern Item Heavy_Cleaver;
extern Item Executioners_Blade;
extern Item WeaponNone;

//Armor
extern Item Leather_Vest;
extern Item Studded_Leather;
extern Item Hunters_Brigandine;
extern Item Iron_Cuirass;
extern Item Knights_Cuirass;
extern Item Reinforced_Plate;
extern Item ArmorNone;

//Footwear
extern Item Worn_Boots;
extern Item Scouts_Boots;
extern Item Striders_Greaves;
extern Item IronToed_Boots;
extern Item Guard_Boots;
extern Item Sentinel_Greaves;
extern Item FootwearNone;