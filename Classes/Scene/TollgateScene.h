//
//  StartScene.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/21/14.
//
//

#ifndef __DontSaveMe__StartScene__
#define __DontSaveMe__StartScene__
#include "cocos2d.h"

class BackgroundLayer;
class MonsterLayer;
//class TollgateLayer;
class TollgateScene : public cocos2d::Scene
{
public:
    TollgateScene():m_backgroundLayer(nullptr),m_monsterLayer(nullptr)/*,m_tollgateLayer(nullptr)*/{}
    virtual ~TollgateScene(){}
    CREATE_FUNC(TollgateScene);
    virtual bool init();
    void logic(float dt);
    
private:
    
    BackgroundLayer *m_backgroundLayer;
    MonsterLayer *m_monsterLayer;
  //  TollgateLayer *m_tollgateLayer;
    

};


#endif /* defined(__DontSaveMe__StartScene__) */
