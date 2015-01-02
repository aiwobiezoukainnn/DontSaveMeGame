//
//  StartLayer.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#ifndef __DontSaveMe__StartLayer__
#define __DontSaveMe__StartLayer__

#include <stdio.h>


#include "cocos2d.h"
USING_NS_CC;
class StartLayer : public Layer
{
public:
    StartLayer();
    virtual ~StartLayer();
    CREATE_FUNC(StartLayer);
    virtual bool init();
    void logic(float dt);
    
    void StartGame(cocos2d::Ref *ref);
    
    void ExitGame(cocos2d::Ref *ref);
    
    

    void onBeginTouchStartButton(Touch* touch, Event* event);
    

    void onBeginTouchExitButton(Touch* touch, Event* event);
    
    


    
};
#endif /* defined(__DontSaveMe__StartLayer__) */
