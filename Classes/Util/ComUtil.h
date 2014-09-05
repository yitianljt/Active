//
//  ComUtil.h
//  Active
//
//  Created by jintao on 14-9-4.
//
//

#ifndef __Active__ComUtil__
#define __Active__ComUtil__

#include <iostream>
#include "cocos2d.h"

cocos2d::Size COMWinSize();
#define FONTSIZE(__SIZE__)  (__SIZE__/960.0)*COMWinSize().height
#endif /* defined(__Active__ComUtil__) */
