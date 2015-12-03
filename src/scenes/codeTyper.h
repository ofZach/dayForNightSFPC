//
//  codeTyper.h
//  d4nSFPCRunner
//
//  Created by Christopher Anderson on 11/25/15.
//
//

#pragma once

#include "ofMain.h"
#include "appConstants.h"

class codeTyper {
public:
    codeTyper();

    void update(float time);
    void updateCode(const string& newCode);
    void resetCode(const string& newCode);
    string getRevealedCode();
    
    string fullCode;
    int revealedIdx, revealedChars;
    
};