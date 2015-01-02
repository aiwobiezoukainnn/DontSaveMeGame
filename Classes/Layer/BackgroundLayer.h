//
//  BackgroundLayer.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/21/14.
//
//

#ifndef __DontSaveMe__BackgroundLayer__
#define __DontSaveMe__BackgroundLayer__

#include <stdio.h>


#include "cocos2d.h"
#include "../Enity/CustomSprite.h"

USING_NS_CC;
class BackgroundLayer : public Layer
{
public:
    BackgroundLayer();
    ~BackgroundLayer();
    CREATE_FUNC(BackgroundLayer);
    virtual bool init();
    void logic(float dt);
    void back(Touch  *touch, Event *event);

private:
    Sprite* m_bg1;
    Sprite* m_bg2;
    Sprite* createBorder(Point pos);
};


#endif /* defined(__DontSaveMe__BackgroundLayer__) */
