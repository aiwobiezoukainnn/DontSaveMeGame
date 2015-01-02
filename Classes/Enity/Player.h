//
//  Player.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/21/14.
//
//

#ifndef __DontSaveMe__Player__
#define __DontSaveMe__Player__

#include <stdio.h>
#include "cocos2d.h"
#include "../ObjectTag.h"
USING_NS_CC;
class Player : public Node
{
public:
    Player();
    ~Player();
    CREATE_FUNC(Player);
    virtual bool init();
    void moveToRight();
    void moveToLeft();
    void quickMove();
    
    void beAtked(int n);

    void logic(float dt);
private:
    CC_SYNTHESIZE(int, m_iHP, iHP);
};


#endif /* defined(__DontSaveMe__Player__) */
