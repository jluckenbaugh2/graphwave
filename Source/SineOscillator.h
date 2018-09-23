/*
  ==============================================================================

    SineOscillator.h
    Created: 23 Sep 2018 1:18:49pm
    Author:  Jerry

  ==============================================================================
*/

#pragma once


#ifndef SineOscillator_h
#define SineOscillator_h

#include <stdio.h>
#include "../JuceLibraryCode/JuceHeader.h"

class SineOscillator{
private:
    float currentAngle = 0.0;
    float angleDelta = 0.0;
    
public:
    //Default constructor
    SineOscillator(){}
    void setFrequency(float frequency, float sampleRate){
        float cyclesPerSample = frequency/sampleRate;
        angleDelta = cyclesPerSample * MathConstants<float>::twoPi;
    }
    float getNextSample(){
        currentAngle += angleDelta;
        if(currentAngle >= MathConstants<float>::twoPi)
            currentAngle -= MathConstants<float>::twoPi;
        return std::sin(currentAngle);
    }
    
    
};
#endif /* SineOscillator_h */
