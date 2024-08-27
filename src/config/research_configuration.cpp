#pragma once

#include "research_configuration.hpp"

#include <vector>

#include "../recipe.hpp"
#include "../research/research.hpp"
#include "../research/research_type.hpp"
#include "../research/science_type.hpp"

using namespace std;

Research* ResearchConfiguration::getResearchAtIndex(int index) { return researches[index]; }

ResearchConfiguration::ResearchConfiguration() {
    vector<Research*> emptyResearchVector;
    vector<Recipe*> emptyRecipeVector;

    Research* automation =
        new Research(ResearchType::AUTOMATION, "Automation", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(automation);

    Research* optics =
        new Research(ResearchType::OPTICS, "Optics", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 15,
                     /* unitCount= */ 10);
    researches.push_back(optics);

    Research* gunTurret =
        new Research(ResearchType::GUN_TURRET, "Gun turret", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(gunTurret);

    Research* stoneWall =
        new Research(ResearchType::STONE_WALL, "Stone wall", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(stoneWall);

    Research* military =
        new Research(ResearchType::MILITARY, "Military", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(military);

    Research* logistics =
        new Research(ResearchType::LOGISTICS, "Logistics", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(logistics);

    Research* steelProcessing =
        new Research(ResearchType::STEEL_PROCESSING, "Steel processing", emptyResearchVector,
                     emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(steelProcessing);

    Research* logisticSciencePack = new Research(
        ResearchType::LOGISTIC_SCIENCE_PACK, "Logistic science pack", emptyResearchVector,
        emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
        /* timePerUnit= */ 10,
        /* unitCount= */ 10);
    researches.push_back(logisticSciencePack);

    Research* electronics =
        new Research(ResearchType::ELECTRONICS, "Electronics", emptyResearchVector,
                     emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(electronics);

    Research* fastInserter =
        new Research(ResearchType::FAST_INSERTER, "Fast inserter", emptyResearchVector,
                     emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(fastInserter);

    Research* heavyArmor =
        new Research(ResearchType::HEAVY_ARMOR, "Heavy armor", emptyResearchVector,
                     emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(heavyArmor);

    Research* steelAxe =
        new Research(ResearchType::STEEL_AXE, "Steel axe", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(steelAxe);

    Research* weaponsShootingSpeed1 = new Research(
        ResearchType::WEAPONS_SHOOTING_SPEED_1, "Weapons shooting speed 1", emptyResearchVector,
        emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
        /* timePerUnit= */ 10,
        /* unitCount= */ 10);
    researches.push_back(weaponsShootingSpeed1);

    Research* physicalProjectileDamage1 = new Research(
        ResearchType::PHYSICAL_PROJECTILE_DAMAGE_1, "Physical projectile damage 1",
        emptyResearchVector, emptyRecipeVector, static_cast<int>(ScienceType::AUTOMATION_SCIENCE),
        /* timePerUnit= */ 10,
        /* unitCount= */ 10);
    researches.push_back(physicalProjectileDamage1);

    Research* military2 =
        new Research(ResearchType::MILITARY_2, "Military 2", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(military2);

    Research* militarySciencePack =
        new Research(ResearchType::MILITARY_SCIENCE_PACK, "Military science pack",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(militarySciencePack);

    Research* automation2 = new Research(ResearchType::AUTOMATION_2, "Automation 2",
                                         emptyResearchVector, emptyRecipeVector,
                                         static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                             static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                         /* timePerUnit= */ 10,
                                         /* unitCount= */ 10);
    researches.push_back(automation2);

    Research* landfill =
        new Research(ResearchType::LANDFILL, "Landfill", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(landfill);

    Research* fluidHandling = new Research(ResearchType::FLUID_HANDLING, "Fluid handling",
                                           emptyResearchVector, emptyRecipeVector,
                                           static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                               static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                           /* timePerUnit= */ 10,
                                           /* unitCount= */ 10);
    researches.push_back(fluidHandling);

    Research* flammables =
        new Research(ResearchType::FLAMMABLES, "Flammables", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(flammables);

    Research* nightvisionEquipment =
        new Research(ResearchType::NIGHTVISION_EQUIPMENT, "Nightvision equipment",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(nightvisionEquipment);

    Research* beltImmunityEquipment =
        new Research(ResearchType::BELT_IMMUNITY_EQUIPMENT, "Belt immunity equipment",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(beltImmunityEquipment);

    Research* personalBattery = new Research(ResearchType::PERSONAL_BATTERY, "Personal battery",
                                             emptyResearchVector, emptyRecipeVector,
                                             static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                                 static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                             /* timePerUnit= */ 10,
                                             /* unitCount= */ 10);
    researches.push_back(personalBattery);

    Research* speedModule = new Research(ResearchType::SPEED_MODULE, "Speed module",
                                         emptyResearchVector, emptyRecipeVector,
                                         static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                             static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                         /* timePerUnit= */ 10,
                                         /* unitCount= */ 10);
    researches.push_back(speedModule);

    Research* productivityModule =
        new Research(ResearchType::PRODUCTIVITY_MODULE, "Productivity module", emptyResearchVector,
                     emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(productivityModule);

    Research* efficiencyModule = new Research(ResearchType::EFFICIENCY_MODULE, "Efficiency module",
                                              emptyResearchVector, emptyRecipeVector,
                                              static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                                  static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                              /* timePerUnit= */ 10,
                                              /* unitCount= */ 10);
    researches.push_back(efficiencyModule);

    Research* chemicalSciencePack =
        new Research(ResearchType::CHEMICAL_SCIENCE_PACK, "Chemical science pack",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(chemicalSciencePack);

    Research* advancedMaterialProcessing =
        new Research(ResearchType::ADVANCED_MATERIAL_PROCESSING, "Advanced material processing",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(advancedMaterialProcessing);

    Research* railway =
        new Research(ResearchType::RAILWAY, "Railway", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(railway);

    Research* automatedRailTransportation =
        new Research(ResearchType::AUTOMATED_RAIL_TRANSPORTATION, "Automated rail transportation",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(automatedRailTransportation);

    Research* circuitNetwork = new Research(ResearchType::CIRCUIT_NETWORK, "Circuit network",
                                            emptyResearchVector, emptyRecipeVector,
                                            static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                                static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                            /* timePerUnit= */ 10,
                                            /* unitCount= */ 10);
    researches.push_back(circuitNetwork);

    Research* explosives =
        new Research(ResearchType::EXPLOSIVES, "Explosives", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(explosives);

    Research* gate =
        new Research(ResearchType::GATE, "Gate", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(gate);

    Research* engine =
        new Research(ResearchType::ENGINE, "Engine", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(engine);

    Research* railSignals = new Research(ResearchType::RAIL_SIGNALS, "Rail signals",
                                         emptyResearchVector, emptyRecipeVector,
                                         static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                             static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                         /* timePerUnit= */ 10,
                                         /* unitCount= */ 10);
    researches.push_back(railSignals);

    Research* toolbelt =
        new Research(ResearchType::TOOLBELT, "Toolbelt", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(toolbelt);

    Research* labResearchSpeed1 =
        new Research(ResearchType::LAB_RESEARCH_SPEED_1, "Lab research speed 1",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(labResearchSpeed1);

    Research* oilProcessing = new Research(ResearchType::OIL_PROCESSING, "Oil processing",
                                           emptyResearchVector, emptyRecipeVector,
                                           static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                               static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                           /* timePerUnit= */ 10,
                                           /* unitCount= */ 10);
    researches.push_back(oilProcessing);

    Research* automobilism = new Research(ResearchType::AUTOMOBILISM, "Automobilism",
                                          emptyResearchVector, emptyRecipeVector,
                                          static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                              static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                          /* timePerUnit= */ 10,
                                          /* unitCount= */ 10);
    researches.push_back(automobilism);

    Research* strongerExplosives1 =
        new Research(ResearchType::STRONGER_EXPLOSIVES_1, "Stronger explosives 1",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(strongerExplosives1);

    Research* modularArmor = new Research(ResearchType::MODULAR_ARMOR, "Modular armor",
                                          emptyResearchVector, emptyRecipeVector,
                                          static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                              static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                          /* timePerUnit= */ 10,
                                          /* unitCount= */ 10);
    researches.push_back(modularArmor);

    Research* portableSolarPanel =
        new Research(ResearchType::PORTABLE_SOLAR_PANEL, "Portable solar panel",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(portableSolarPanel);

    Research* modules =
        new Research(ResearchType::MODULES, "Modules", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(modules);

    Research* electricEnergyDistribution1 =
        new Research(ResearchType::ELECTRIC_ENERGY_DISTRIBUTION_1, "Electric energy distribution 1",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(electricEnergyDistribution1);

    Research* battery =
        new Research(ResearchType::BATTERY, "Battery", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(battery);

    Research* electricEnergyAccumulators =
        new Research(ResearchType::ELECTRIC_ENERGY_ACCUMULATORS, "Electric energy accumulators",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(electricEnergyAccumulators);

    Research* stackInserter = new Research(ResearchType::STACK_INSERTER, "Stack inserter",
                                           emptyResearchVector, emptyRecipeVector,
                                           static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                               static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                           /* timePerUnit= */ 10,
                                           /* unitCount= */ 10);
    researches.push_back(stackInserter);

    Research* sulfurProcessing = new Research(ResearchType::SULFUR_PROCESSING, "Sulfur processing",
                                              emptyResearchVector, emptyRecipeVector,
                                              static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                                  static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                              /* timePerUnit= */ 10,
                                              /* unitCount= */ 10);
    researches.push_back(sulfurProcessing);

    Research* advancedElectronics =
        new Research(ResearchType::ADVANCED_ELECTRONICS, "Advanced electronics",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(advancedElectronics);

    Research* logistics2 = new Research(ResearchType::LOGISTICS_2, "Logistics 2",
                                        emptyResearchVector, emptyRecipeVector,
                                        static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                            static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                        /* timePerUnit= */ 10,
                                        /* unitCount= */ 10);
    researches.push_back(logistics2);

    Research* fluidWagon = new Research(ResearchType::FLUID_WAGON, "Fluid wagon",
                                        emptyResearchVector, emptyRecipeVector,
                                        static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                            static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                        /* timePerUnit= */ 10,
                                        /* unitCount= */ 10);
    researches.push_back(fluidWagon);

    Research* inserterCapacityBonus1 =
        new Research(ResearchType::INSERTER_CAPACITY_BONUS_1, "Inserter capacity bonus 1",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(inserterCapacityBonus1);

    Research* plastics =
        new Research(ResearchType::PLASTICS, "Plastics", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(plastics);

    Research* cliffExplosives = new Research(ResearchType::CLIFF_EXPLOSIVES, "Cliff explosives",
                                             emptyResearchVector, emptyRecipeVector,
                                             static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                                 static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                             /* timePerUnit= */ 10,
                                             /* unitCount= */ 10);
    researches.push_back(cliffExplosives);

    Research* solarEnergy = new Research(ResearchType::SOLAR_ENERGY, "Solar energy",
                                         emptyResearchVector, emptyRecipeVector,
                                         static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                                             static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                                         /* timePerUnit= */ 10,
                                         /* unitCount= */ 10);
    researches.push_back(solarEnergy);

    Research* concrete =
        new Research(ResearchType::CONCRETE, "Concrete", emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(concrete);

    Research* miningProductivity1 =
        new Research(ResearchType::MINING_PRODUCTIVITY_1, "Mining productivity 1",
                     emptyResearchVector, emptyRecipeVector,
                     static_cast<int>(ScienceType::AUTOMATION_SCIENCE) |
                         static_cast<int>(ScienceType::LOGISTIC_SCIENCE),
                     /* timePerUnit= */ 10,
                     /* unitCount= */ 10);
    researches.push_back(miningProductivity1);

    // TODO: add more science beyond red + green.
    // Copilot is good at this, just give it the list of research from the enum and one code
    // example. Also TODO: update research times + unit counts to be accurate.
}
