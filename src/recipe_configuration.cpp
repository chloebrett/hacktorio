#pragma once

#include "recipe.hpp"
#include "recipe_configuration.hpp"
#include "recipe_position.hpp"
#include <map>
#include <vector>
#include "inventory_item_type.hpp"
#include "item_stack.hpp"

using namespace std;

RecipeConfiguration::RecipeConfiguration() {
    vector<ItemStack*> woodenChestInputs = vector<ItemStack*>();
    vector<ItemStack*> woodenChestOutputs = vector<ItemStack*>();
    woodenChestInputs.push_back(new ItemStack(InventoryItemType::WOOD, 2));
    woodenChestOutputs.push_back(new ItemStack(InventoryItemType::WOODEN_CHEST, 1));
    Recipe* woodenChestRecipe = new Recipe("Wooden chest", woodenChestInputs, woodenChestOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::LOGISTICS, 0, 0)] = woodenChestRecipe;

    vector<ItemStack*> ironChestInputs = vector<ItemStack*>();
    vector<ItemStack*> ironChestOutputs = vector<ItemStack*>();
    ironChestInputs.push_back(new ItemStack(InventoryItemType::IRON_PLATE, 8));
    ironChestOutputs.push_back(new ItemStack(InventoryItemType::IRON_CHEST, 1));
    Recipe* ironChestRecipe = new Recipe("Iron chest", ironChestInputs, ironChestOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::LOGISTICS, 0, 1)] = ironChestRecipe;
    
    vector<ItemStack*> transportBeltInputs = vector<ItemStack*>();
    vector<ItemStack*> transportBeltOutputs = vector<ItemStack*>();
    transportBeltInputs.push_back(new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1));
    transportBeltInputs.push_back(new ItemStack(InventoryItemType::IRON_PLATE, 1));
    transportBeltOutputs.push_back(new ItemStack(InventoryItemType::TRANSPORT_BELT, 2));
    Recipe* transportBeltRecipe = new Recipe("Transport belt", transportBeltInputs, transportBeltOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::LOGISTICS, 1, 0)] = transportBeltRecipe;

    // cout << "Defined recipe: " << transportBeltRecipe->getName() << endl;
    // cout << "Ingredients: " << endl;
    // for (ItemStack* input : transportBeltRecipe->getInputs()) {
    //     cout << "  " << (*input).getAmount() << "x " << ((*input).getType() << endl;
    // }
    // for (ItemStack* output : transportBeltRecipe->getOutputs()) {
    //     cout << "  " << output->getAmount() << "x " << gameResources.inventoryItemTypeToKey(output->getType()) << endl;
    // }
    // cout << "Crafting time: " << transportBeltRecipe->getTime() << "s" << endl;
}

Recipe* RecipeConfiguration::getRecipeAtPosition(RecipePosition &position) {
    return recipeMap[position];
}
