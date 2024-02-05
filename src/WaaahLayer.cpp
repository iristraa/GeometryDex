#include <Geode/Geode.hpp>
#include "WaaahLayer.hpp"

using namespace geode::prelude;

bool WaaahLayer::init() {
    if (!CCLayer::init()) return false;
    //sto- i mean, borrowed code from betterinfo

    auto backgroundSprite = CCSprite::create("GJ_gradientBG-hd.png");
    // backgroundSprite->setID("background"_spr);

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);

    backgroundSprite->setAnchorPoint({ 0, 0 });
    backgroundSprite->setPosition({ 0, 0 });

    backgroundSprite->setColor({ 176, 11, 105 });

    backgroundSprite->setZOrder(-2);
    this->addChild(backgroundSprite);

    auto backTexture = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
    auto backBtn = CCMenuItemSpriteExtra::create(
        backTexture, this,
        menu_selector(WaaahLayer::onBack)
    );
    // backBtn->setID("exit-button"_spr);

    auto menuBack = CCMenu::create();
    menuBack->addChild(backBtn);
    menuBack->setPosition({ 25, winSize.height - 25 });
    // menuBack->setID("exit-menu"_spr);

    auto headerText = CCLabelBMFont::create("Fats Viewer", "goldFont.fnt");
    headerText->setPosition({ winSize.width / 2, winSize.height - 20.f });
    headerText->setScale(0.8);
    // headerText->setID("header-text"_spr);
    this->addChild(headerText);

    auto progressBar = CCSprite::create("GJ_progressBar_001.png");
    progressBar->setPosition({ winSize.width / 2, winSize.height - 80.f });
    progressBar->setOpacity(125);
    progressBar->setColor({ 0, 0, 0 });
    progressBar->setLayout(
        RowLayout::create()
        ->setAxisAlignment(AxisAlignment::Start)
    );
    // progressBar->setID("progress-bar"_spr);
    this->addChild(progressBar);

    float curProgress = 0.3;
    auto progressBarSize = progressBar->getContentSize();
    auto progressBarPos = progressBar->getPosition();
    auto progress = CCRect({ 0, 0, progressBarSize.width * curProgress, progressBarSize.height });
    auto progressBarProgress = CCSprite::create("GJ_progressBar_001.png", progress);
    progressBarProgress->setColor({ 255, 255, 255 });
    // this->addChild(progressBarProgress);
    // progressBarProgress->setPosition({ winSize.width / 2, winSize.height - 80.f });
    // progressBarProgress->setPosition({ progressBarPos.x, progressBarPos.y });
    progressBar->addChild(progressBarProgress);
    progressBar->updateLayout();
    // progressBarProgress->setID("progress"_spr);

    this->addChild(menuBack);
    this->setKeypadEnabled(true);

    return true;
}

void WaaahLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}


void WaaahLayer::onBack(CCObject* object) {
    keyBackClicked();
}

WaaahLayer* WaaahLayer::create() {
    auto ret = new WaaahLayer;
    if (ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

CCScene* WaaahLayer::scene() {
    auto layer = WaaahLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}