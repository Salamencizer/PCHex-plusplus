#include <cstring>

#include "state.h"

int State::mode = State::SELECTMODE;
int State::ciaselected = 0;
int State::indexnumber = 0;
int State::boxnumber = 0;
int State::boxcloneorigin;
int State::indexcloneorigin;
std::string State::overlaymsg;
int State::backupmode;
int State::multipleselectiontick = 0;
bool State::tick = false;
unsigned int State::eovselected = 0;
std::vector<std::string> State::eovvector;
int State::eovmode;
std::string State::currentfolder = "";
HB_Keyboard State::keyboard;
int State::keyboardstate;
int State::skip = 0;
int State::keyboarddelay = 0;
int State::touchid = 0;
int State::buttondelay = 0;
int State::keepbuttondelay = 0;
char State::tempbackup[232];
int State::tab = 0;
int State::tabkeyboarddelay = 0;
bool State::shoulderless = false;
bool State::skiplanguage = false;

void State::setCiaSelected(const int val) {
    if(val < 0 )
        ciaselected = 4;
    
    else ciaselected = val % 5;
}

void State::setIndexNumber(const int val) {
    if( boxnumber == 31 ) {
        if(val >= 0 && val < 6)
            indexnumber = val;
    }
    
    else if( val >= 0 && val < 30 )
        indexnumber = val;
}

void State::setBoxNumber(const int val) {
    int limitval;
    if( mode != State::MULTIPLESELECTMODE && mode != State::MULTIPLECLONEMODE )
        limitval = 31;
    
    else limitval = 30;
    
    if( val > limitval )
        boxnumber = 0;
    
    else if( val < 0 )
        boxnumber = limitval;
    
    else boxnumber = val;
}

bool State::getMultipleSelectionTick() {
    multipleselectiontick++;
    
    if( multipleselectiontick / 50 > 0 ) {
        tick = !tick;
        multipleselectiontick = 0;
    }
    
    return tick;
}

void State::setEovSelected(const unsigned int val) {
    if( val >= 0 && val < eovvector.size() )
        eovselected = val;
}

void State::getTempBackup(Pokemon* pika) {
    pika->setDataPtr(tempbackup);
}

void State::setTempBackup(Pokemon* pika) {
    memcpy(tempbackup, pika->getDataPtr(), 232);
}