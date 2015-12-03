//
//  codeTyper.cpp
//  d4nSFPCRunner
//
//  Created by Christopher Anderson on 11/25/15.
//
//

#include "codeTyper.h"

codeTyper::codeTyper() {
    fullCode = "";
    revealedIdx = 0;
    revealedChars = 0;
}

void codeTyper::update(float time) {
    int charsToReveal = (int)(time * CODE_REVEAL_CHARS_PER_SEC);
    
    if (charsToReveal <= revealedChars || revealedIdx >= fullCode.length())
        return;
    
    while (revealedChars < charsToReveal) {
        // reveal one character at a time
        revealedChars++;

        // revealing a character might mean advancing the index a bunch
        revealedIdx++;
        while (fullCode[revealedIdx] == ' ') {
            revealedIdx++;
            if (revealedIdx >= fullCode.length())
                return;
        }
    }
}

void codeTyper::updateCode(const string& newCode) {
    fullCode = newCode;

    if (revealedIdx >= fullCode.length())
        revealedIdx = fullCode.length();
}


void codeTyper::resetCode(const string& newCode) {
    fullCode = newCode;
    revealedIdx = 0;
    revealedChars = 0;
}

string codeTyper::getRevealedCode() {
    return fullCode.substr(0, revealedIdx);
}
