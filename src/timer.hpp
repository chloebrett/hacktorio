#pragma once

#include <functional>
#include "timer_event.hpp"

using namespace std;

/** Timer that runs delayed events. */
class Timer
{
public:
    Timer();
    void runEvents(int currentTick);
    void addFutureEvent(float seconds, TimerEvent *event);

private:
    int currentTick;
    vector<pair<int, TimerEvent*>> futureEvents; // TODO: deque?
};
