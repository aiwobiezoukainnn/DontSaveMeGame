//
//  MonsterLayer.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#include "MonsterLayer.h"
MonsterLayer::MonsterLayer()
{
    m_fTimeCounter = 0;
}

MonsterLayer::~MonsterLayer()
{
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("monster.plist");
}
void MonsterLayer::logic(float dt)
{
    /* 计时 */
    m_fTimeCounter += dt;
    
    /* 记录本次出场的怪物 */
    Vector<Monster*> deleteVec;
    
    /* 让达到出场时间的怪物添加到物理世界 */
    for (auto monster : m_monsterVec)
    {
        /* 达到时间，可以出场了 */
        if (m_fTimeCounter >= monster->getfShowTime())
        {
            monster->joinToWorld(this);
            
            /* 记录本次出场的怪物，然后删除掉 */
            deleteVec.pushBack(monster);
        }
    }
    
    /* 删除已经添加到物理世界的怪物，避免重复出场 */
    for (auto monster : deleteVec)
    {
        m_monsterVec.eraseObject(monster, false);
    }
}




bool MonsterLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster.plist", "monster.png");
    
    /* 加载关卡的怪物配置 */
    loadMonstersFromTmxConf();
    return true;
}

void MonsterLayer::loadMonstersFromTmxConf()
{
    /* 加载地图 */
    TMXTiledMap* map = TMXTiledMap::create("tg1.tmx");
    this->addChild(map);
    
    /* 加载怪物对象层的所有对象 */
    TMXObjectGroup* objGroup = map->getObjectGroup("monster");
    ValueVector objects = objGroup->getObjects();
    
    /* 遍历所有对象 */
    for (const auto v : objects)
    {
        const ValueMap dict = v.asValueMap();
        
        int id = dict.at("id").asInt();
        float fShowTime = dict.at("showTime").asFloat();
        int iPosX = dict.at("x").asInt();
        int iPosY = dict.at("y").asInt();
        
        /* 创建怪物对象，并保存起来 */
        Monster* monster = Monster::create(id);
        monster->setID(id);
        monster->setfShowTime(fShowTime);
        monster->setiPosX(iPosX);
        monster->setiPosY(iPosY);
        
        /* 保存怪物对象 */
        m_monsterVec.pushBack(monster);
    }
}

