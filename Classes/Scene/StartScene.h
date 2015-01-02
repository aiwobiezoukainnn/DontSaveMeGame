//
//  StartScene.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#ifndef __DontSaveMe__StartScene__
#define __DontSaveMe__StartScene__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class StartLayer;
class StartScene : public cocos2d::Scene
{
public:
    StartScene():m_startLayer(nullptr){}
    virtual ~StartScene(){   SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Images.plist");
}
    CREATE_FUNC(StartScene);
    virtual bool init();
private:
    
    StartLayer *m_startLayer;
    
};


#endif /* defined(__DontSaveMe__StartScene__) */
