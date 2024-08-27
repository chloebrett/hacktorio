#pragma once

#include "timer.hpp"

#include <functional>
#include <iostream>
#include <vector>

#include "config/constants.hpp"
#include "timer_event.hpp"

using namespace std;

Timer::Timer() {
    this->currentTick = 0;
    this->futureEvents = vector<pair<int, TimerEvent *>>();
}

void Timer::runEvents(int currentTick) {
    this->currentTick = currentTick;
    for (int i = 0; i < futureEvents.size(); i++) {
        pair<int, TimerEvent *> futureEvent = futureEvents[i];
        if (currentTick >= futureEvent.first) {
            cout << "Running future event at tick " << currentTick << endl;
            futureEvent.second->event();
            futureEvents.erase(futureEvents.begin() + i);
            i--;
        }
    }
}

// TODO: add string tags to events for debugging?
void Timer::addFutureEvent(float seconds, TimerEvent *event) {
    // TODO: use UPDATES_PER_SECOND instead of FRAMES_PER_SECOND?
    int futureTick = currentTick + static_cast<int>(seconds * FRAMES_PER_SECOND);
    cout << "Adding future event at tick " << futureTick << endl;
    futureEvents.push_back(make_pair(futureTick, event));
}
