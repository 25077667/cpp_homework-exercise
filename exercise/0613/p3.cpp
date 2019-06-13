#include <vector>
#include "pokemon.h"

int main() {
    Water_Pokemon water[3] = {Water_Pokemon("wa1", "water", 3, 10), Water_Pokemon("wa2", "water", 7, 20), Water_Pokemon("wa3", "water", 15, 40)};
    Wood_Pokemon wood[3] = {Wood_Pokemon("wo1", "wood", 3, 10), Wood_Pokemon("wo2", "wood", 7, 20), Wood_Pokemon("wo3", "wood", 15, 40)};
    Fire_Pokemon fire[3] = {Fire_Pokemon("f1", "fire", 3, 10), Fire_Pokemon("f2", "fire", 7, 20), Fire_Pokemon("f3", "fire", 15, 40)};

    vector<Pokemon*> allPokemon;
    for (int i = 0; i < 3; i++) {
        allPokemon.push_back(&(water[i]));
        allPokemon.push_back(&(wood[i]));
        allPokemon.push_back(&(fire[i]));
    }
    for (int i = 0; i < 9; i++)
        allPokemon[i]->showDetail();

    return 0;
}