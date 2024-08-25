#pragma once

#include "../container.hpp"
#include "../item_stack.hpp"
#include "../cursor.hpp"
#include "../scene_node.hpp"

class CursorDisplay : public SceneNode {
    public:
    CursorDisplay(Cursor &cursor);

    private:
    Cursor &cursor;
};
