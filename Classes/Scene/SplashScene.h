//
//  SplashScene.h
//  DontSaveMeGame
//
//  Created by Mr Gan on 1/2/15.
//
//

#ifndef __DontSaveMeGame__SplashScene__
#define __DontSaveMeGame__SplashScene__

#include <stdio.h>
#include "cocos2d.h"
class SplashScene : public cocos2d::Scene
{
public:
    
    CREATE_FUNC(SplashScene);
    virtual bool init();
    void update(float dt);

private:
    SplashScene();
    virtual ~SplashScene();
    
};

#endif /* defined(__DontSaveMeGame__SplashScene__) */
