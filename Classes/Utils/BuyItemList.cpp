#ifndef CONST_BUYITEMLIST
#define CONST_BUYITEMLIST

#include "BuyItemList.h"

#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

BuyItemList::~BuyItemList()
{
    this->removeAllChildrenWithCleanup(true);
}

BuyItemList::BuyItemList(CCNode* pParent) :
    List(Utils::coord(512), Utils::coord(640), Utils::coord(512), Utils::coord(/** 750 **/0), ((Entity*) pParent)->getWidth() / 2, ((Entity*) pParent)->getHeight() / 2 + Utils::coord(0), "about_scroll_fill_small@2x.png", pParent),
	mIcon(0),
	mSilverCoinsIcon(0),
	mCoinsIcon(0),
	mPropertiesIcon(0),
	mStars(),
	mNameText(0),
	mDescriptionText(0),
	mPriceText(0),
	mPriceGoldText(0),
	mPowerText(0),
	mBoughtText(0)
	{
        this->setListType(List::TYPE_VERTICAL);
        this->setParentType(List::PARENT_TYPE_POPUP);

        this->mSpriteBatch = SpriteBatch::create("TextureAtlas5");

        this->addChild(this->mSpriteBatch);

        this->mIcon = Entity::create("shop_item_icon@2x.png", 10, 6, this->mSpriteBatch);

		Textes textes1 = {"", Options::FONT, 24, -1};

        this->mDescriptionText = Text::create(textes1, ccp(Utils::coord(450), 0), this);
        this->mDescriptionText->cocos2d::CCLabelTTF::enableShadow(CCSize(Utils::coord(1), -Utils::coord(1)), 255.0, 2.0, true);

        this->mStars[0] = Entity::create("popup_item_rate_stars@2x.png", 1, 2, this->mSpriteBatch);
        this->mStars[1] = Entity::create("popup_item_rate_stars@2x.png", 1, 2, this->mSpriteBatch);
        
        this->mStars[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(5) + this->mStars[0]->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(50));
        this->mStars[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(5) + this->mStars[0]->getWidth() / 2, Options::CAMERA_CENTER_Y -+Utils::coord(50));
        this->mStars[0]->setCurrentFrameIndex(1);

        this->mSilverCoinsIcon = Entity::create("coins_silver@2x.png", 5, 4, this->mSpriteBatch);
        this->mCoinsIcon = Entity::create("coins@2x.png", 5, 4, this->mSpriteBatch);
        
        this->mSilverCoinsIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_CENTER_Y + Utils::coord(170));
        this->mSilverCoinsIcon->setRotation(-45);
        this->mSilverCoinsIcon->setScale(0.75);
        this->mSilverCoinsIcon->animate(0.05);
        
        this->mCoinsIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_CENTER_Y + Utils::coord(170));
        this->mCoinsIcon->setRotation(-45);
        this->mCoinsIcon->setScale(0.75);
        this->mCoinsIcon->animate(0.05);

        this->mPropertiesIcon = Entity::create("icon_properties@2x.png", 1, 3, this->mSpriteBatch);
        this->mPropertiesIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_CENTER_Y + Utils::coord(112));

		Textes textes2 = {"0", Options::FONT, 32, 0};
		Textes textes3 = {"0", Options::FONT, 32, 0};
		Textes textes4 = {"112", Options::FONT, 32, 0};
		Textes textes5 = {"", Options::FONT, 40, 0};

        this->mPriceText = Text::create(textes2, this);
        this->mPriceText->setColor(ccc3(255.0, 130.0, 0.0));
        
        this->mPriceGoldText = Text::create(textes3, this);
        this->mPriceGoldText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mBoughtText = Text::create(Options::TEXT_ITEM_ALREADY_BOUGHT, this);
        this->mBoughtText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mPowerText = Text::create(textes4, this);
        this->mPowerText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mNameText = Text::create(textes5, this);
        this->mNameText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(260));
        this->mNameText->setColor(ccc3(170.0, 82.0, 5.0));
        
        this->mDescriptionText->setColor(ccc3(204.0, 102.0, 51.0));

        this->mIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(120), Options::CAMERA_CENTER_Y + Utils::coord(120));
        
        this->mPreloaderSprite = Entity::create("preloader@2x.png", 0, 0, 64, 64, this);
    }

BuyItemList* BuyItemList::create(CCNode* pParent)
{
    BuyItemList* list = new BuyItemList(pParent);
    list->autorelease();
    list->retain();
    
    return list;
}

// ===========================================================
// Methods
// ===========================================================

void BuyItemList::showDescription()
{
    this->mPreloaderSprite->setVisible(false);
    
    this->mDescriptionText->setVisible(true);
    this->mDescriptionText->setString(Options::TEXT_SHOP_ITEMS_DESCRIPTIONS[Shop::CLICKED_ITEM_ID].string);
    this->mDescriptionText->setCenterPosition(this->mParent->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(5) - this->mDescriptionText->getHeight() / 2);
    
    this->mMaxHeight = this->mDescriptionText->getHeight() - Utils::coord(250);
    this->mMaxHeight = this->mMaxHeight > 0 ? this->mMaxHeight : 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void BuyItemList::onEnter()
{
    this->mPreloaderSprite->runAction(CCRepeatForever::create(CCRotateTo::create(1.0, 720)));
    
    this->mIcon->setCurrentFrameIndex(Shop::CLICKED_ITEM_ID);
    
    this->mDescriptionText->setVisible(false);
    
    this->mPreloaderSprite->setVisible(true);
    this->mPreloaderSprite->setCenterPosition(this->mParent->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(100));

    this->mNameText->setString(Options::TEXT_SHOP_ITEMS[Shop::CLICKED_ITEM_ID].string);

    this->mPriceText->setString(Utils::intToString(Options::SHOP_ITEMS_PRICES[Shop::CLICKED_ITEM_ID]).c_str());
    this->mPriceGoldText->setString(Utils::intToString(Options::SHOP_ITEMS_PRICES_GOLD[Shop::CLICKED_ITEM_ID]).c_str());
    this->mPriceText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(40) + this->mPriceText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(170));

    if(Options::SHOP_ITEMS_PRICES_GOLD[Shop::CLICKED_ITEM_ID] > 0 && !AppDelegate::isItemBought(Shop::CLICKED_ITEM_ID))
    {
        this->mPriceGoldText->setVisible(true);
        this->mCoinsIcon->setVisible(true);

        this->mCoinsIcon->setCenterPosition(this->mPriceText->getCenterX() + this->mPriceText->getWidth() / 2 + Utils::coord(30), Options::CAMERA_CENTER_Y + Utils::coord(170));
        this->mPriceGoldText->setCenterPosition(this->mCoinsIcon->getCenterX() + Utils::coord(25) + this->mPriceGoldText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(170));
    }
    else
    {
        this->mPriceGoldText->setVisible(false);
        this->mCoinsIcon->setVisible(false);
    }
    
    this->mBoughtText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(0) + this->mBoughtText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(170));

    this->mPowerText->setString(Options::SHOP_ITEMS_PROPERTIES[Shop::CLICKED_ITEM_ID]);
    this->mPowerText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(40) + this->mPowerText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(110));

    this->mStars[1]->showPercentage(Options::SHOP_ITEMS_RATING_FACTOR[Shop::CLICKED_ITEM_ID]);
    this->mStars[1]->setCenterPosition(this->mParent->getWidth() / 2 - Utils::coord(5) + this->mStars[1]->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(50));

    if(Shop::CLICKED_ITEM_ID < Shop::ITEMS_COUNT[0] || Shop::CLICKED_ITEM_ID == 40)
    {
        this->mPropertiesIcon->setCurrentFrameIndex(1);
    }
    else if(Shop::CLICKED_ITEM_ID == 45 || Shop::CLICKED_ITEM_ID == 46)
    {
        this->mPropertiesIcon->setCurrentFrameIndex(2);
    }
    else
    {
        this->mPropertiesIcon->setCurrentFrameIndex(0);
    }

    if(AppDelegate::isItemBought(Shop::CLICKED_ITEM_ID))
    {
        this->mSilverCoinsIcon->setVisible(false);
        this->mPriceText->setVisible(false);

        this->mBoughtText->setVisible(true);
    }
    else
    {
        this->mSilverCoinsIcon->setVisible(true);
        this->mPriceText->setVisible(true);

        this->mBoughtText->setVisible(false);
    }
    
    List::onEnter();
}

#endif