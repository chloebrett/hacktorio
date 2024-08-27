#pragma once

#include <functional>

#include "timer_event.hpp"

/** Timer that runs delayed events. */
class Timer {
   public:
    Timer();
    void runEvents(int currentTick);
    void addFutureEvent(float seconds, TimerEvent *event);

   private:
    int currentTick;
    std::vector<std::pair<int, TimerEvent *>> futureEvents;  // TODO: deque?
};
