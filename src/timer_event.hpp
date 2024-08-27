#pragma once

#include <functional>

/** Event that runs from a timer. */
class TimerEvent {
   public:
    TimerEvent(std::function<void()> event);
    std::function<void()> event;
};
