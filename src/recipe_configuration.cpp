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
    initPositions();
    initRecipes();
    initRecipeMap();
}

void RecipeConfiguration::initPositions() {
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 0, 0)] = InventoryItemType::WOODEN_CHEST;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 0, 1)] = InventoryItemType::IRON_CHEST;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 1, 0)] = InventoryItemType::TRANSPORT_BELT;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 2, 0)] = InventoryItemType::BURNER_INSERTER;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 2, 1)] = InventoryItemType::INSERTER;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 3, 0)] = InventoryItemType::SMALL_ELECTRIC_POLE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 3, 1)] = InventoryItemType::PIPE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 3, 2)] = InventoryItemType::PIPE_TO_GROUND;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::LOGISTICS, 4, 0)] = InventoryItemType::STONE_BRICK;

    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 0, 0)] = InventoryItemType::REPAIR_PACK;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 1, 0)] = InventoryItemType::BOILER;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 1, 1)] = InventoryItemType::STEAM_ENGINE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 2, 0)] = InventoryItemType::BURNER_MINING_DRILL;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 2, 1)] = InventoryItemType::ELECTRIC_MINING_DRILL;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 2, 2)] = InventoryItemType::OFFSHORE_PUMP;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 3, 0)] = InventoryItemType::STONE_FURNACE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::PRODUCTION, 4, 0)] = InventoryItemType::LAB;

    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 0, 0)] = InventoryItemType::IRON_PLATE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 0, 1)] = InventoryItemType::COPPER_PLATE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 1, 0)] = InventoryItemType::COPPER_CABLE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 1, 1)] = InventoryItemType::IRON_STICK;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 1, 2)] = InventoryItemType::IRON_GEAR_WHEEL;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 1, 3)] = InventoryItemType::ELECTRONIC_CIRCUIT;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, 2, 0)] = InventoryItemType::AUTOMATION_SCIENCE_PACK;

    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::COMBAT, 0, 0)] = InventoryItemType::PISTOL;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::COMBAT, 1, 0)] = InventoryItemType::FIREARM_MAGAZINE;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::COMBAT, 2, 0)] = InventoryItemType::LIGHT_ARMOR;
    recipeOutputTypeByPosition[RecipePosition(RecipeTabType::COMBAT, 3, 0)] = InventoryItemType::RADAR;
}

void RecipeConfiguration::initRecipes() {
    initLogisticsRecipes();
    initProductionRecipes();
    initIntermediateProductsRecipes();
    initCombatRecipes();
}

void RecipeConfiguration::initLogisticsRecipes() {
    vector<ItemStack*>* woodenChestInputs = new vector<ItemStack*>();
    vector<ItemStack*>* woodenChestOutputs = new vector<ItemStack*>();
    ItemStack* woodStack = new ItemStack(InventoryItemType::WOOD, 2);
    ItemStack* woodenChestStack = new ItemStack(InventoryItemType::WOODEN_CHEST, 1);
    woodenChestInputs->push_back(woodStack);
    woodenChestOutputs->push_back(woodenChestStack);
    Recipe* woodenChestRecipe = new Recipe("Wooden chest", *woodenChestInputs, *woodenChestOutputs, 0.5);
    recipeByOutputType[InventoryItemType::WOODEN_CHEST] = woodenChestRecipe;

    vector<ItemStack*>* ironChestInputs = new vector<ItemStack*>();
    vector<ItemStack*>* ironChestOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack = new ItemStack(InventoryItemType::IRON_PLATE, 8);
    ItemStack* ironChestStack = new ItemStack(InventoryItemType::IRON_CHEST, 1);
    ironChestInputs->push_back(ironPlateStack);
    ironChestOutputs->push_back(ironChestStack);
    Recipe* ironChestRecipe = new Recipe("Iron chest", *ironChestInputs, *ironChestOutputs, 0.5);
    recipeByOutputType[InventoryItemType::IRON_CHEST] = ironChestRecipe;

    vector<ItemStack*>* transportBeltInputs = new vector<ItemStack*>();
    vector<ItemStack*>* transportBeltOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ItemStack* ironPlateStack2 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* transportBeltStack = new ItemStack(InventoryItemType::TRANSPORT_BELT, 2);
    transportBeltInputs->push_back(ironGearWheelStack);
    transportBeltInputs->push_back(ironPlateStack2);
    transportBeltOutputs->push_back(transportBeltStack);
    Recipe* transportBeltRecipe = new Recipe("Transport belt", *transportBeltInputs, *transportBeltOutputs, 0.5);
    recipeByOutputType[InventoryItemType::TRANSPORT_BELT] = transportBeltRecipe;

    vector<ItemStack*>* burnerInserterInputs = new vector<ItemStack*>();
    vector<ItemStack*>* burnerInserterOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack4 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* ironGearWheelStack3 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ItemStack* burnerInserterStack = new ItemStack(InventoryItemType::BURNER_INSERTER, 1);
    burnerInserterInputs->push_back(ironPlateStack4);
    burnerInserterInputs->push_back(ironGearWheelStack3);
    burnerInserterOutputs->push_back(burnerInserterStack);
    Recipe* burnerInserterRecipe = new Recipe("Burner inserter", *burnerInserterInputs, *burnerInserterOutputs, 0.5);
    recipeByOutputType[InventoryItemType::BURNER_INSERTER] = burnerInserterRecipe;

    vector<ItemStack*>* inserterInputs = new vector<ItemStack*>();
    vector<ItemStack*>* inserterOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack4 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ItemStack* ironPlateStack5 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* electronicCircuitStack = new ItemStack(InventoryItemType::ELECTRONIC_CIRCUIT, 1);
    ItemStack* inserterStack = new ItemStack(InventoryItemType::INSERTER, 1);
    inserterInputs->push_back(ironGearWheelStack4);
    inserterInputs->push_back(ironPlateStack5);
    inserterInputs->push_back(electronicCircuitStack);
    inserterOutputs->push_back(inserterStack);
    Recipe* inserterRecipe = new Recipe("Inserter", *inserterInputs, *inserterOutputs, 0.5);
    recipeByOutputType[InventoryItemType::INSERTER] = inserterRecipe;

    vector<ItemStack*>* smallElectricPoleInputs = new vector<ItemStack*>();
    vector<ItemStack*>* smallElectricPoleOutputs = new vector<ItemStack*>();
    ItemStack* woodStack2 = new ItemStack(InventoryItemType::WOOD, 1);
    ItemStack* copperPlateStack = new ItemStack(InventoryItemType::COPPER_CABLE, 2);
    ItemStack* smallElectricPoleStack = new ItemStack(InventoryItemType::SMALL_ELECTRIC_POLE, 2);
    smallElectricPoleInputs->push_back(woodStack2);
    smallElectricPoleInputs->push_back(copperPlateStack);
    smallElectricPoleOutputs->push_back(smallElectricPoleStack);
    Recipe* smallElectricPoleRecipe = new Recipe("Small electric pole", *smallElectricPoleInputs, *smallElectricPoleOutputs, 0.5);
    recipeByOutputType[InventoryItemType::SMALL_ELECTRIC_POLE] = smallElectricPoleRecipe;

    vector<ItemStack*>* pipeInputs = new vector<ItemStack*>();
    vector<ItemStack*>* pipeOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack6 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* pipeStack = new ItemStack(InventoryItemType::PIPE, 1);
    pipeInputs->push_back(ironPlateStack6);
    pipeOutputs->push_back(pipeStack);
    Recipe* pipeRecipe = new Recipe("Pipe", *pipeInputs, *pipeOutputs, 0.5);
    recipeByOutputType[InventoryItemType::PIPE] = pipeRecipe;

    vector<ItemStack*>* pipeToGroundInputs = new vector<ItemStack*>();
    vector<ItemStack*>* pipeToGroundOutputs = new vector<ItemStack*>();
    ItemStack* stoneBrickStack = new ItemStack(InventoryItemType::IRON_PLATE, 5);
    ItemStack* pipeStack2 = new ItemStack(InventoryItemType::PIPE, 10);
    ItemStack* pipeToGroundStack = new ItemStack(InventoryItemType::PIPE_TO_GROUND, 2);
    pipeToGroundInputs->push_back(stoneBrickStack);
    pipeToGroundInputs->push_back(pipeStack2);
    pipeToGroundOutputs->push_back(pipeToGroundStack);
    Recipe* pipeToGroundRecipe = new Recipe("Pipe to ground", *pipeToGroundInputs, *pipeToGroundOutputs, 0.5);
    recipeByOutputType[InventoryItemType::PIPE_TO_GROUND] = pipeToGroundRecipe;

    vector<ItemStack*>* stoneBrickInputs = new vector<ItemStack*>();
    vector<ItemStack*>* stoneBrickOutputs = new vector<ItemStack*>();
    ItemStack* stoneStack = new ItemStack(InventoryItemType::STONE, 2);
    ItemStack* stoneBrickStack2 = new ItemStack(InventoryItemType::STONE_BRICK, 1);
    stoneBrickInputs->push_back(stoneStack);
    stoneBrickOutputs->push_back(stoneBrickStack2);
    // TODO: support furnace-only recipes
    Recipe* stoneBrickRecipe = new Recipe("Stone brick", *stoneBrickInputs, *stoneBrickOutputs, 4.2);
    recipeByOutputType[InventoryItemType::STONE_BRICK] = stoneBrickRecipe;
}

void RecipeConfiguration::initProductionRecipes() {
    vector<ItemStack*>* repairPackInputs = new vector<ItemStack*>();
    vector<ItemStack*>* repairPackOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack5 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 2);
    ItemStack* ironPlateStack7 = new ItemStack(InventoryItemType::IRON_PLATE, 3);
    ItemStack* repairPackStack = new ItemStack(InventoryItemType::REPAIR_PACK, 1);
    repairPackInputs->push_back(ironGearWheelStack5);
    repairPackInputs->push_back(ironPlateStack7);
    repairPackOutputs->push_back(repairPackStack);
    Recipe* repairPackRecipe = new Recipe("Repair pack", *repairPackInputs, *repairPackOutputs, 0.5);
    recipeByOutputType[InventoryItemType::REPAIR_PACK] = repairPackRecipe;

    vector<ItemStack*>* boilerInputs = new vector<ItemStack*>();
    vector<ItemStack*>* boilerOutputs = new vector<ItemStack*>();
    ItemStack* pipeStack3 = new ItemStack(InventoryItemType::PIPE, 4);
    ItemStack* stoneFurnaceStack = new ItemStack(InventoryItemType::STONE_FURNACE, 1);
    boilerInputs->push_back(pipeStack3);
    boilerOutputs->push_back(stoneFurnaceStack);
    Recipe* boilerRecipe = new Recipe("Boiler", *boilerInputs, *boilerOutputs, 0.5);
    recipeByOutputType[InventoryItemType::BOILER] = boilerRecipe;

    vector<ItemStack*>* steamEngineInputs = new vector<ItemStack*>();
    vector<ItemStack*>* steamEngineOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack6 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 8);
    ItemStack* ironPlateStack9 = new ItemStack(InventoryItemType::IRON_PLATE, 10);
    ItemStack* pipeStack4 = new ItemStack(InventoryItemType::PIPE, 5);
    ItemStack* steamEngineStack = new ItemStack(InventoryItemType::STEAM_ENGINE, 1);
    steamEngineInputs->push_back(ironGearWheelStack6);
    steamEngineInputs->push_back(ironPlateStack9);
    steamEngineInputs->push_back(pipeStack4);
    steamEngineOutputs->push_back(steamEngineStack);
    Recipe* steamEngineRecipe = new Recipe("Steam engine", *steamEngineInputs, *steamEngineOutputs, 0.5);
    recipeByOutputType[InventoryItemType::STEAM_ENGINE] = steamEngineRecipe;

    vector<ItemStack*>* burnerMiningDrillInputs = new vector<ItemStack*>();
    vector<ItemStack*>* burnerMiningDrillOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack7 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 3);
    ItemStack* ironPlateStack10 = new ItemStack(InventoryItemType::IRON_PLATE, 3);
    ItemStack* stoneFurnaceStack2 = new ItemStack(InventoryItemType::STONE_FURNACE, 1);
    ItemStack* burnerMiningDrillStack = new ItemStack(InventoryItemType::BURNER_MINING_DRILL, 1);
    burnerMiningDrillInputs->push_back(ironGearWheelStack7);
    burnerMiningDrillInputs->push_back(ironPlateStack10);
    burnerMiningDrillInputs->push_back(stoneFurnaceStack2);
    burnerMiningDrillOutputs->push_back(burnerMiningDrillStack);
    Recipe* burnerMiningDrillRecipe = new Recipe("Burner mining drill", *burnerMiningDrillInputs, *burnerMiningDrillOutputs, 2.0);
    recipeByOutputType[InventoryItemType::BURNER_MINING_DRILL] = burnerMiningDrillRecipe;

    vector<ItemStack*>* electricMiningDrillInputs = new vector<ItemStack*>();
    vector<ItemStack*>* electricMiningDrillOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack8 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 5);
    ItemStack* ironPlateStack11 = new ItemStack(InventoryItemType::IRON_PLATE, 10);
    ItemStack* electronicCircuitStack2 = new ItemStack(InventoryItemType::ELECTRONIC_CIRCUIT, 3);
    ItemStack* electricMiningDrillStack = new ItemStack(InventoryItemType::ELECTRIC_MINING_DRILL, 1);
    electricMiningDrillInputs->push_back(ironGearWheelStack8);
    electricMiningDrillInputs->push_back(ironPlateStack11);
    electricMiningDrillInputs->push_back(electronicCircuitStack2);
    electricMiningDrillOutputs->push_back(electricMiningDrillStack);
    Recipe* electricMiningDrillRecipe = new Recipe("Electric mining drill", *electricMiningDrillInputs, *electricMiningDrillOutputs, 2.0);

    vector<ItemStack*>* offshorePumpInputs = new vector<ItemStack*>();
    vector<ItemStack*>* offshorePumpOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack9 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ItemStack* pipeStack5 = new ItemStack(InventoryItemType::PIPE, 1);
    ItemStack* electronicCircuitStack3 = new ItemStack(InventoryItemType::ELECTRONIC_CIRCUIT, 2);
    ItemStack* offshorePumpStack = new ItemStack(InventoryItemType::OFFSHORE_PUMP, 1);
    offshorePumpInputs->push_back(ironGearWheelStack9);
    offshorePumpInputs->push_back(pipeStack5);
    offshorePumpInputs->push_back(electronicCircuitStack3);
    offshorePumpOutputs->push_back(offshorePumpStack);
    Recipe* offshorePumpRecipe = new Recipe("Offshore pump", *offshorePumpInputs, *offshorePumpOutputs, 0.5);

    vector<ItemStack*>* stoneFurnaceInputs = new vector<ItemStack*>();
    vector<ItemStack*>* stoneFurnaceOutputs = new vector<ItemStack*>();
    ItemStack* stoneStack2 = new ItemStack(InventoryItemType::STONE, 5);
    ItemStack* stoneFurnaceStack3 = new ItemStack(InventoryItemType::STONE_FURNACE, 1);
    stoneFurnaceInputs->push_back(stoneStack2);
    stoneFurnaceOutputs->push_back(stoneFurnaceStack3);
    Recipe* stoneFurnaceRecipe = new Recipe("Stone furnace", *stoneFurnaceInputs, *stoneFurnaceOutputs, 0.5);
    recipeByOutputType[InventoryItemType::STONE_FURNACE] = stoneFurnaceRecipe;

    vector<ItemStack*>* labInputs = new vector<ItemStack*>();
    vector<ItemStack*>* labOutputs = new vector<ItemStack*>();
    ItemStack* electronicCircuitStack4 = new ItemStack(InventoryItemType::ELECTRONIC_CIRCUIT, 10);
    ItemStack* ironGearWheelStack10 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 10);
    ItemStack* transportBeltStack2 = new ItemStack(InventoryItemType::TRANSPORT_BELT, 4);
    ItemStack* labStack = new ItemStack(InventoryItemType::LAB, 1);
    labInputs->push_back(electronicCircuitStack4);
    labInputs->push_back(ironGearWheelStack10);
    labInputs->push_back(transportBeltStack2);
    labOutputs->push_back(labStack);
    Recipe* labRecipe = new Recipe("Lab", *labInputs, *labOutputs, 2.0);
    recipeByOutputType[InventoryItemType::LAB] = labRecipe;
}

void RecipeConfiguration::initIntermediateProductsRecipes() {
    vector<ItemStack*>* ironPlateInputs = new vector<ItemStack*>();
    vector<ItemStack*>* ironPlateOutputs = new vector<ItemStack*>();
    ItemStack* ironOreStack = new ItemStack(InventoryItemType::IRON_ORE, 1);
    ItemStack* ironPlateStack12 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ironPlateInputs->push_back(ironOreStack);
    ironPlateOutputs->push_back(ironPlateStack12);
    Recipe* ironPlateRecipe = new Recipe("Iron plate", *ironPlateInputs, *ironPlateOutputs, 3.2);
    recipeByOutputType[InventoryItemType::IRON_PLATE] = ironPlateRecipe;

    vector<ItemStack*>* copperPlateInputs = new vector<ItemStack*>();
    vector<ItemStack*>* copperPlateOutputs = new vector<ItemStack*>();
    ItemStack* copperOreStack = new ItemStack(InventoryItemType::COPPER_ORE, 1);
    ItemStack* copperPlateStack = new ItemStack(InventoryItemType::COPPER_PLATE, 1);
    copperPlateInputs->push_back(copperOreStack);
    copperPlateOutputs->push_back(copperPlateStack);
    Recipe* copperPlateRecipe = new Recipe("Copper plate", *copperPlateInputs, *copperPlateOutputs, 3.2);
    recipeByOutputType[InventoryItemType::COPPER_PLATE] = copperPlateRecipe;

    vector<ItemStack*>* copperCableInputs = new vector<ItemStack*>();
    vector<ItemStack*>* copperCableOutputs = new vector<ItemStack*>();
    ItemStack* copperPlateStack2 = new ItemStack(InventoryItemType::COPPER_PLATE, 1);
    ItemStack* copperCableStack = new ItemStack(InventoryItemType::COPPER_CABLE, 2);
    copperCableInputs->push_back(copperPlateStack2);
    copperCableOutputs->push_back(copperCableStack);
    Recipe* copperCableRecipe = new Recipe("Copper cable", *copperCableInputs, *copperCableOutputs, 0.5);
    recipeByOutputType[InventoryItemType::COPPER_CABLE] = copperCableRecipe;

    vector<ItemStack*>* ironStickInputs = new vector<ItemStack*>();
    vector<ItemStack*>* ironStickOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack13 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* ironStickStack = new ItemStack(InventoryItemType::IRON_STICK, 2);
    ironStickInputs->push_back(ironPlateStack13);
    ironStickOutputs->push_back(ironStickStack);
    Recipe* ironStickRecipe = new Recipe("Iron stick", *ironStickInputs, *ironStickOutputs, 0.5);
    recipeByOutputType[InventoryItemType::IRON_STICK] = ironStickRecipe;

    vector<ItemStack*>* ironGearWheelInputs = new vector<ItemStack*>();
    vector<ItemStack*>* ironGearWheelOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack3 = new ItemStack(InventoryItemType::IRON_PLATE, 2);
    ItemStack* ironGearWheelStack2 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ironGearWheelInputs->push_back(ironPlateStack3);
    ironGearWheelOutputs->push_back(ironGearWheelStack2);
    Recipe* ironGearWheelRecipe = new Recipe("Iron gear wheel", *ironGearWheelInputs, *ironGearWheelOutputs, 0.5);
    recipeByOutputType[InventoryItemType::IRON_GEAR_WHEEL] = ironGearWheelRecipe;

    vector<ItemStack*>* electronicCircuitInputs = new vector<ItemStack*>();
    vector<ItemStack*>* electronicCircuitOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack8 = new ItemStack(InventoryItemType::IRON_PLATE, 1);
    ItemStack* copperCableStack2 = new ItemStack(InventoryItemType::COPPER_CABLE, 3);
    ItemStack* electronicCircuitStack2 = new ItemStack(InventoryItemType::ELECTRONIC_CIRCUIT, 1);
    electronicCircuitInputs->push_back(ironPlateStack8);
    electronicCircuitInputs->push_back(copperCableStack2);
    electronicCircuitOutputs->push_back(electronicCircuitStack2);
    Recipe* electronicCircuitRecipe = new Recipe("Electronic circuit", *electronicCircuitInputs, *electronicCircuitOutputs, 0.5);
    recipeByOutputType[InventoryItemType::ELECTRONIC_CIRCUIT] = electronicCircuitRecipe;

    vector<ItemStack*>* automationSciencePackInputs = new vector<ItemStack*>();
    vector<ItemStack*>* automationSciencePackOutputs = new vector<ItemStack*>();
    ItemStack* copperPlateStack3 = new ItemStack(InventoryItemType::COPPER_PLATE, 1);
    ItemStack* ironGearWheelStack3 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 1);
    ItemStack* automationSciencePackStack = new ItemStack(InventoryItemType::AUTOMATION_SCIENCE_PACK, 1);
    automationSciencePackInputs->push_back(copperPlateStack3);
    automationSciencePackInputs->push_back(ironGearWheelStack3);
    automationSciencePackOutputs->push_back(automationSciencePackStack);
    Recipe* automationSciencePackRecipe = new Recipe("Automation science pack", *automationSciencePackInputs, *automationSciencePackOutputs, 5.0);
    recipeByOutputType[InventoryItemType::AUTOMATION_SCIENCE_PACK] = automationSciencePackRecipe;
}

void RecipeConfiguration::initCombatRecipes() {
    vector<ItemStack*>* pistolInputs = new vector<ItemStack*>();
    vector<ItemStack*>* pistolOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack14 = new ItemStack(InventoryItemType::IRON_PLATE, 5);
    ItemStack* copperPlateStack3 = new ItemStack(InventoryItemType::COPPER_PLATE, 5);
    ItemStack* pistolStack = new ItemStack(InventoryItemType::PISTOL, 1);
    pistolInputs->push_back(ironPlateStack14);
    pistolInputs->push_back(copperPlateStack3);
    pistolOutputs->push_back(pistolStack);
    Recipe* pistolRecipe = new Recipe("Pistol", *pistolInputs, *pistolOutputs, 5.0);
    recipeByOutputType[InventoryItemType::PISTOL] = pistolRecipe;

    vector<ItemStack*>* firearmMagazineInputs = new vector<ItemStack*>();
    vector<ItemStack*>* firearmMagazineOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack15 = new ItemStack(InventoryItemType::IRON_PLATE, 4);
    ItemStack* firearmMagazineStack = new ItemStack(InventoryItemType::FIREARM_MAGAZINE, 1);
    firearmMagazineInputs->push_back(ironPlateStack15);
    firearmMagazineOutputs->push_back(firearmMagazineStack);
    Recipe* firearmMagazineRecipe = new Recipe("Firearm magazine", *firearmMagazineInputs, *firearmMagazineOutputs, 1.0);
    recipeByOutputType[InventoryItemType::FIREARM_MAGAZINE] = firearmMagazineRecipe;

    vector<ItemStack*>* lightArmorInputs = new vector<ItemStack*>();
    vector<ItemStack*>* lightArmorOutputs = new vector<ItemStack*>();
    ItemStack* ironPlateStack16 = new ItemStack(InventoryItemType::IRON_PLATE, 40);
    ItemStack* lightArmorStack = new ItemStack(InventoryItemType::LIGHT_ARMOR, 1);
    lightArmorInputs->push_back(ironPlateStack16);
    lightArmorOutputs->push_back(lightArmorStack);
    Recipe* lightArmorRecipe = new Recipe("Light armor", *lightArmorInputs, *lightArmorOutputs, 3.0);
    recipeByOutputType[InventoryItemType::LIGHT_ARMOR] = lightArmorRecipe;

    vector<ItemStack*>* radarInputs = new vector<ItemStack*>();
    vector<ItemStack*>* radarOutputs = new vector<ItemStack*>();
    ItemStack* ironGearWheelStack11 = new ItemStack(InventoryItemType::IRON_GEAR_WHEEL, 5);
    ItemStack* electronicCircuitStack5 = new ItemStack(InventoryItemType::ELECTRONIC_CIRCUIT, 5);
    ItemStack* ironPlateStack17 = new ItemStack(InventoryItemType::IRON_PLATE, 10);
    ItemStack* radarStack = new ItemStack(InventoryItemType::RADAR, 1);
    radarInputs->push_back(ironGearWheelStack11);
    radarInputs->push_back(electronicCircuitStack5);
    radarInputs->push_back(ironPlateStack17);
    radarOutputs->push_back(radarStack);
    Recipe* radarRecipe = new Recipe("Radar", *radarInputs, *radarOutputs, 0.5);
    recipeByOutputType[InventoryItemType::RADAR] = radarRecipe;
}

void RecipeConfiguration::initRecipeMap() {
    for (auto const& [position, outputType] : recipeOutputTypeByPosition) {
        recipeMap[position] = recipeByOutputType[outputType];
    }
}

Recipe* RecipeConfiguration::getRecipeAtPosition(RecipePosition &position) {
    return recipeMap[position];
}
