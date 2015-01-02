//
//  MonsterLayer.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#ifndef __DontSaveMe__MonsterLayer__
#define __DontSaveMe__MonsterLayer__

#include <stdio.h>

#include "../Enity/Monster.h"
#include "cocos2d.h"
USING_NS_CC;


class Monster;
class MonsterLayer : public Layer
{
public:
    MonsterLayer();
    ~MonsterLayer();
    CREATE_FUNC(MonsterLayer);
    virtual bool init();
    
    void logic(float dt);
private:
    /* 从配置文件中加载怪物数据 */
    void loadMonstersFromTmxConf();
    
    /* 存放所有即将要出场的怪物对象 */
    Vector<Monster*> m_monsterVec;
    
    /* 计时器 */
    float m_fTimeCounter;
};


#endif /* defined(__DontSaveMe__MonsterLayer__) */
