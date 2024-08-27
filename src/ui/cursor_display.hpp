#pragma once

#include "../container.hpp"
#include "../cursor.hpp"
#include "../item_stack.hpp"
#include "../scene_node.hpp"

class CursorDisplay : public SceneNode {
   public:
    CursorDisplay(Cursor &cursor);

   private:
    Cursor &cursor;
};
