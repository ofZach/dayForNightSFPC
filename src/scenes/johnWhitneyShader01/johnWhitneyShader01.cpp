
#include "johnWhitneyShader01.h"

void johnWhitneyShader01::setup(){
  
// setup pramaters
    time.set("time", 0, 0, PI);
    time.addAnimation(0, 4,  0,  PI, QuadraticEaseInOut);
    time.addAnimation(4, 8, PI,  0,  QuadraticEaseInOut);
    parameters.add(time);
    animatedParameters.push_back(&time);
    
    vertScale.set("vertScale", 0.15, 0, 1);
    vertScale.addAnimation(8,  12, 0.15,  0.5, LinearInterpolation);
    vertScale.addAnimation(12, 16,  0.5, 0.15, LinearInterpolation);
    parameters.add(vertScale);
    animatedParameters.push_back(&vertScale);

    loadCode("johnWhitneyShader01/exampleCode.cpp");

    shader.load("johnWhitneyShader01/shader");
}

void johnWhitneyShader01::update() {
    
}

void johnWhitneyShader01::draw() {
    float resolution[] = { dimensions.width, dimensions.height };

    ofFill();
    shader.begin();
    shader.setUniform1f("time", time.get());
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform1f("vertScale", vertScale.get());

    ofRect(0, 0, dimensions.width, dimensions.height);
    shader.end();
}