#include <Geode/Geode.hpp>
#include "WaaahLayer.hpp"
#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, GJGarageLayer) {
	void onBtnClick(CCObject * sender) {
		auto waaahLayer = WaaahLayer::scene();
		auto transitionFade = CCTransitionFade::create(0.5, waaahLayer);
		CCDirector::sharedDirector()->pushScene(transitionFade);
	}

	bool init() {
		if (!GJGarageLayer::init()) return false;

		auto shardMenu = this->getChildByID("shards-menu");
		// auto colorBtnPos = shardMenu->getChildByID("color-button");

		auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_stopEditorBtn_001.png");
		auto button = CCMenuItemSpriteExtra::create(
			buttonSprite, this,
			menu_selector(MyMenuLayer::onBtnClick)
		);

		shardMenu->addChild(button);
		// button->setPosition(colorBtnPos->getPosition() - CCPoint{ 0.f, 40.f });
		// ^ idk what i was cooking with this line of code
		shardMenu->updateLayout();
		button->setID("googoogaga-button");

		return true;
	}
};
