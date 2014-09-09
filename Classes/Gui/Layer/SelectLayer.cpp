//
//  SelectLayer.cpp
//  Active
//
//  Created by jintao on 14-9-5.
//
//

#include "SelectLayer.h"
#include "cocos-ext.h"
#include "cocostudio/CCActionManagerEx.h"
#include "editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;



bool SelectLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    LayerColor* layerBg = LayerColor::create(Color4B(104,177,59,255));
    addChild(layerBg,0);
    
    Layout* _widget = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("ccs/scroll_1.ExportJson"));

    addChild(_widget);
    
    return true;
}
