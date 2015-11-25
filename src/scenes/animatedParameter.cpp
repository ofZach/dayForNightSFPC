//
//  animationTiming.cpp
//  d4nSFPCRunner
//
//  Created by Christopher Anderson on 11/25/15.
//
//

#include "animatedParameter.h"

animatedParameter::animatedParameter() : maxTime(0), loop(true)
{
}

void animatedParameter::addAnimation(float startTime, float endTime, float startVal, float endVal, AHEasingFunction f) {
    animationTiming timing;

    timing.startTime = startTime;
    timing.endTime = endTime;
    timing.startValue = startVal;
    timing.endValue = endVal;
    timing.easingFunction = f;

    if (endTime > maxTime) {
        maxTime = endTime;
    }

    timings.push_back(timing);
}

void animatedParameter::updateTime(float time) {
    if (timings.size() == 0) {
        return;
    }

    if (loop && time > maxTime) {
        time = fmod(time, maxTime);
    }

    // Find the animation we're in right now
    animationTiming *t = &timings[0];
    for (auto &animationTiming : timings) {
        if (time > animationTiming.startTime)
            t = &animationTiming;
    }

    if (time < t->startTime) {
        return t->startValue;
    } else if (time > t->endTime) {
        return t->endValue;
    }

    float p = (time - t->startTime) / (t->endTime - t->startTime);
    float val = t->easingFunction(p) * (t->endValue - t->startValue) + t->startValue;
    
    set(val);
}
