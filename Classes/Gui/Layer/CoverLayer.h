//
//  CoverLayer.h
//  Active
//
//  Created by jintao on 14-9-4.
//
//

#ifndef __Active__CoverLayer__
#define __Active__CoverLayer__

#include <iostream>
#include "cocos2d.h"


class CoverLayer:public cocos2d::Layer
{
public:
    CREATE_FUNC(CoverLayer);
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
private:
    void showIn(const std::function<void()> &aCall);
    void showOut(const std::function<void()> &aCall);
    
    float _fWidth;
    float _fHeight;
    Layer* _menuLayer;
    cocos2d::LayerColor* _LayerBtnStart;
    cocos2d::LayerColor* _LayerBtnRecord;
    cocos2d::LayerColor* _LayerBtnSet;
    cocos2d::LayerColor* _LayerBtnComment;
    
};

#endif /* defined(__Active__CoverLayer__) */
