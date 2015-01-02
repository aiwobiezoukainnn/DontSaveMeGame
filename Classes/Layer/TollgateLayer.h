//
//  TollgateLayer.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/24/14.
//
//

#ifndef __DontSaveMe__TollgateLayer__
#define __DontSaveMe__TollgateLayer__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class TollgateLayer : public cocos2d::Node
{
public:
    
    CREATE_FUNC(TollgateLayer);
    virtual bool init();
    void logic(float dt);
private:
    TollgateLayer();
    virtual ~TollgateLayer();
    
};



#endif /* defined(__DontSaveMe__TollgateLayer__) */
