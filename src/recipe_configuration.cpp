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
    vector<ItemStack*>* woodenChestInputs = new vector<ItemStack*>();
    vector<ItemStack*>* woodenChestOutputs = new vector<ItemStack*>();
    ItemStack* woodStack = new ItemStack(InventoryItemType::WOOD, 2);
    ItemStack* woodenChestStack = new ItemStack(InventoryItemType::WOODEN_CHEST, 1);
    woodenChestInputs->push_back(woodStack);
    woodenChestOutputs->push_back(woodenChestStack);
    Recipe* woodenChestRecipe = new Recipe("Wooden chest", *woodenChestInputs, *woodenChestOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::LOGISTICS, 0, 0)] = woodenChestRecipe;

    vector<ItemStack*>* ironChestInputs = new vector<ItemStack*>();
    vector<ItemStack*>* ironChestOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack = new ItemStack(InventoryItemType::IRON_PLATE, 8);
    ItemStack* ironChestStack = new ItemStack(InventoryItemType::IRON_CHEST, 1);
    ironChestInputs->push_back(ironPlateStack);
    ironChestOutputs->push_back(ironChestStack);
    Recipe* ironChestRecipe = new Recipe("Iron chest", *ironChestInputs, *ironChestOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::LOGISTICS, 0, 1)] = ironChestRecipe;

    vector<ItemStack*>* transportBeltInputs = new vector<ItemStack*>();
    vector<ItemStack*>* transportBeltOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ItemStack* ironPlateStack2 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* transportBeltStack = new ItemStack(InventoryItemType::TRANSPORT_BELT, 2);
    transportBeltInputs->push_back(ironGearWheelStack);
    transportBeltInputs->push_back(ironPlateStack2);
    transportBeltOutputs->push_back(transportBeltStack);
    Recipe* transportBeltRecipe = new Recipe("Transport belt", *transportBeltInputs, *transportBeltOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::LOGISTICS, 1, 0)] = transportBeltRecipe;

    vector<ItemStack*>* ironGearWheelInputs = new vector<ItemStack*>();
    vector<ItemStack*>* ironGearWheelOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack3 = new ItemStack(InventoryItemType::IRON_PLATE, 2);
    ItemStack* ironGearWheelStack2 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ironGearWheelInputs->push_back(ironPlateStack3);
    ironGearWheelOutputs->push_back(ironGearWheelStack2);
    Recipe* ironGearWheelRecipe = new Recipe("Iron gear wheel", *ironGearWheelInputs, *ironGearWheelOutputs, 0.5);
    recipeMap[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 1, 2)] = ironGearWheelRecipe;
}

Recipe* RecipeConfiguration::getRecipeAtPosition(RecipePosition &position) {
    return recipeMap[position];
}
