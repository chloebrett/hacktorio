#pragma once

const float FRAMES_PER_SECOND = 60.0f;

const float GRID_SIZE = 32.0f;

const int SCREEN_WIDTH_CELLS = 50;   // 50 * 32 = 1600
const int SCREEN_HEIGHT_CELLS = 30;  // 30 * 32 = 960
const int SCREEN_WIDTH = SCREEN_WIDTH_CELLS * GRID_SIZE;
const int SCREEN_HEIGHT = SCREEN_HEIGHT_CELLS * GRID_SIZE;

const int INVENTORY_WIDTH_CELLS = 10;
const int INVENTORY_HEIGHT_CELLS = 10;
const int INVENTORY_WIDTH = INVENTORY_WIDTH_CELLS * GRID_SIZE;
const int INVENTORY_HEIGHT = INVENTORY_HEIGHT_CELLS * GRID_SIZE;
const int INVENTORY_PADDING_CELLS = 1;
const int INVENTORY_PADDING = INVENTORY_PADDING_CELLS * GRID_SIZE;
const int INVENTORY_H_MARGIN_CELLS =
    (SCREEN_WIDTH_CELLS - INVENTORY_WIDTH_CELLS * 2 - INVENTORY_PADDING_CELLS * 3) / 2;
const int INVENTORY_H_MARGIN = INVENTORY_H_MARGIN_CELLS * GRID_SIZE;
const int INVENTORY_V_MARGIN_CELLS =
    (SCREEN_HEIGHT_CELLS - INVENTORY_HEIGHT_CELLS - INVENTORY_PADDING_CELLS * 2) / 2;
const int INVENTORY_V_MARGIN = INVENTORY_V_MARGIN_CELLS * GRID_SIZE;

const int ESCAPE_MENU_ITEM_WIDTH_CELLS = 6;
const int ESCAPE_MENU_ITEM_HEIGHT_CELLS = 2;
const int ESCAPE_MENU_ITEM_COUNT = 2;
const int ESCAPE_MENU_ITEM_PADDING_CELLS = 1;

const int ESCAPE_MENU_ITEM_WIDTH = ESCAPE_MENU_ITEM_WIDTH_CELLS * GRID_SIZE;
const int ESCAPE_MENU_ITEM_HEIGHT = ESCAPE_MENU_ITEM_HEIGHT_CELLS * GRID_SIZE;
const int ESCAPE_MENU_ITEM_PADDING = ESCAPE_MENU_ITEM_PADDING_CELLS * GRID_SIZE;
const int ESCAPE_MENU_WIDTH = ESCAPE_MENU_ITEM_WIDTH + ESCAPE_MENU_ITEM_PADDING * 2;
const int ESCAPE_MENU_HEIGHT = ESCAPE_MENU_ITEM_HEIGHT * ESCAPE_MENU_ITEM_COUNT +
                               ESCAPE_MENU_ITEM_PADDING * (ESCAPE_MENU_ITEM_COUNT + 1);

const int ESCAPE_MENU_LEFT = (SCREEN_WIDTH - ESCAPE_MENU_WIDTH) / 2;
const int ESCAPE_MENU_TOP = (SCREEN_HEIGHT - ESCAPE_MENU_HEIGHT) / 2;

const int RECIPE_GRID_WIDTH_CELLS = 10;
const int RECIPE_GRID_HEIGHT_CELLS = 8;
const int RECIPE_TAB_LIST_HEIGHT_CELLS = 2;
const int RECIPE_PANEL_HEIGHT_CELLS = RECIPE_GRID_HEIGHT_CELLS + RECIPE_TAB_LIST_HEIGHT_CELLS;
const int RECIPE_TAB_COUNT = 4;

const int RECIPE_GRID_WIDTH = RECIPE_GRID_WIDTH_CELLS * GRID_SIZE;
const int RECIPE_GRID_HEIGHT = RECIPE_GRID_HEIGHT_CELLS * GRID_SIZE;
const int RECIPE_TAB_LIST_HEIGHT = RECIPE_TAB_LIST_HEIGHT_CELLS * GRID_SIZE;
const int RECIPE_PANEL_HEIGHT = RECIPE_PANEL_HEIGHT_CELLS * GRID_SIZE;
const int RECIPE_PANEL_WIDTH = RECIPE_GRID_WIDTH;
const int RECIPE_TAB_WIDTH = RECIPE_GRID_WIDTH / RECIPE_TAB_COUNT;
