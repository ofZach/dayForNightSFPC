//
//  animationTiming.hpp
//  d4nSFPCRunner
//
//  Created by Christopher Anderson on 11/25/15.
//
//

#pragma once

#include "ofMain.h"
#include "easing.h"

struct animationTiming {
    float startTime, endTime;
    float startValue, endValue;
    
    AHEasingFunction easingFunction;
};

class animatedParameter : public ofParameter<float> {

public:
    animatedParameter();
    
    vector< animationTiming > timings;
    float maxTime;
    bool loop;
    
    void addAnimation(float startTime, float endTime, float startVal, float endVal, AHEasingFunction f);
    void updateTime(float time);
};
