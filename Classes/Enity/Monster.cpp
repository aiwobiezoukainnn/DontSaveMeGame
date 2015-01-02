//
//  Monster.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#include "Monster.h"
#include "ObjectTag.h"
#include "json/rapidjson.h"
#include "json/document.h"
Monster::Monster()
{
}

Monster::~Monster()
{
    CCLOG("Monster Deconstruction");
}

Monster* Monster::create(int ID)
{
    auto monster = new Monster();
    
    if(monster && monster->init(ID))
    {
        monster->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(monster);
    }
    
    return monster;
}

bool Monster::init(int ID)
{
    this->m_ID = ID;
    
    /* ----------- 读取怪物配置文件 ------------ */
    
    /* 读取配置文件字符串数据 */
    std::string sData = FileUtils::getInstance()->getStringFromFile("config.plist");
//    
//        /* 用于解析Json */
//        Json::Reader reader;
//    
//        /* 解析Json后的根节点 */
//        Json::Value root;
//    
//        /* 开始解析 */
//        if (!reader.parse(sData, root, false))
//        {
//            return false;
//        }
//    
//        /* 在这里，根节点是一个数组，遍历数组，找到我们要的ID */
//        int size = root.size();
//        for (int i = 0; i < size; ++i)
//        {
//            int id = root[i]["id"].asInt();
//    
//            if (id == ID)
//            {
//                m_sModelPath = root[i]["model"].asCString();
//                break;
//            }
//        }
    
    
    
    rapidjson::Document reader;
    reader.Parse<0>(sData.c_str());
    int size = reader.Size();
    for (int i = 0; i < size; ++i) {
        int id = reader[i]["id"].GetInt();
        if (id == ID)
        {
            m_sModelPath = reader[i]["model"].GetString();
            break;
        }
        
    }
    
    
    
    
    return true;
}





void Monster::joinToWorld(Node* parent)
{
    Sprite* sp = Sprite::createWithSpriteFrameName(m_sModelPath.asString().c_str());
    
    /* 创建刚体 */
    PhysicsBody* body = PhysicsBody::createBox(sp->getContentSize());
    body->setCategoryBitmask(1);    // 0001
    body->setCollisionBitmask(1);   // 0001
    body->setContactTestBitmask(1); // 0001
    
    /* 精灵居中 */
    sp->setPosition(Point(sp->getContentSize().width * 0.5f, sp->getContentSize().height * 0.5f));
    
    /* 精灵作为Monster的表现，添加到Monster身上 */
    this->addChild(sp);
    
    /* 设置怪物Tag类型 */
    this->setTag(ObjectTag_Monster);
    
    /* 精灵作为Monster的表现，Monster本身没有大小，所以要设置一下大小 */
    this->setContentSize(sp->getContentSize());
    
    /* 刚体添加到Monster本身，而不是精灵身上 */
    this->setPhysicsBody(body);
    
    /* 设置坐标 */
    this->setPosition(Point(getiPosX(), getiPosY()));
    
    /* Monster加入到物理世界 */
    parent->addChild(this);
    
}
