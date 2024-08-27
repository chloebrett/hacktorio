#include "timer.hpp"

#include <functional>
#include <iostream>
#include <vector>

#include "config/constants.hpp"
#include "timer_event.hpp"

Timer::Timer() {
    this->currentTick = 0;
    this->futureEvents = std::vector<std::pair<int, TimerEvent *>>();
}

void Timer::runEvents(int currentTick) {
    this->currentTick = currentTick;
    for (int i = 0; i < futureEvents.size(); i++) {
        std::pair<int, TimerEvent *> futureEvent = futureEvents[i];
        if (currentTick >= futureEvent.first) {
            std::cout << "Running future event at tick " << currentTick << std::endl;
            futureEvent.second->event();
            futureEvents.erase(futureEvents.begin() + i);
            i--;
        }
    }
}

// TODO: add std::string tags to events for debugging?
void Timer::addFutureEvent(float seconds, TimerEvent *event) {
    // TODO: use UPDATES_PER_SECOND instead of FRAMES_PER_SECOND?
    int futureTick = currentTick + static_cast<int>(seconds * FRAMES_PER_SECOND);
    std::cout << "Adding future event at tick " << futureTick << std::endl;
    futureEvents.push_back(std::make_pair(futureTick, event));
}
