//
//  Monster.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#ifndef __DontSaveMe__Monster__
#define __DontSaveMe__Monster__


#include "cocos2d.h"
USING_NS_CC;
class Monster : public Node
{
public:
    Monster();
    virtual ~Monster();
    static Monster* create(int ID);
    bool init(int ID);
    
    /* 加入到当前场景的物理世界 */
    void joinToWorld(Node* parent);
    
    CC_SYNTHESIZE(int, m_ID, ID);
    CC_SYNTHESIZE(float, m_fShowTime, fShowTime);
    CC_SYNTHESIZE(int, m_iPosX, iPosX);
    CC_SYNTHESIZE(int, m_iPosY, iPosY);
    CC_SYNTHESIZE(int, m_iAtk, iAtk);
    CC_SYNTHESIZE(Value, m_sModelPath, sModelPath);
};

#endif /* defined(__DontSaveMe__Monster__) */
