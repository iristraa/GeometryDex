#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class WaaahLayer : public cocos2d::CCLayer {
protected:
	bool init() override;

	void keyBackClicked();
	void onBack(cocos2d::CCObject*);

public:
	static WaaahLayer* create();
	static cocos2d::CCScene* scene();

};