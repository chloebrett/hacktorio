#pragma once

#include <functional>

using namespace std;

/** Event that runs from a timer. */
class TimerEvent
{
public:
    TimerEvent(
        function<void()> event
    );
    function<void()> event;
};
