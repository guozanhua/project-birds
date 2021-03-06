/**
 * Tooflya Inc. Development
 *
 * @author Igor Mats from Tooflya Inc.
 * @copyright (c) 2013 by Igor Mats
 *
 * @license http://opensource.org/licenses/gpl-license.php GNU Public License v2
 * @all rights granted under this License are granted for the term of
 * copyright on the Program, and are irrevocable provided the stated
 * conditions are met. This License explicitly affirms your unlimited
 * permission to run the unmodified Program. The output from running a
 * covered work is covered by this License only if the output, given its
 * content, constitutes a covered work. This License acknowledges your
 * rights of fair use or other equivalent, as provided by copyright law.
 *
 * @version
 *
 */

 var cocos2dApp = cc.Application.extend({
  config:document['ccConfig'],

  ctor: function() {
    this._super();

    cc.COCOS2D_DEBUG = this.config['COCOS2D_DEBUG'];
    cc.initDebugSetting();
    cc.setup(this.config['tag']);
    cc.AppController.shareAppController().didFinishLaunchingWithOptions();
  },

  applicationDidFinishLaunching:function () {
    var director = cc.Director.getInstance();

    var screenSize = cc.EGLView.getInstance().getFrameSize();
    var resourceSize = cc.size(1920, 1080);
    var designSize = cc.size(1920, 1080);

    var searchPaths = [];

    searchPaths.push("Resources");
    cc.FileUtils.getInstance().setSearchResolutionsOrder(searchPaths);

    director.setContentScaleFactor(resourceSize.width / designSize.width);

    cc.EGLView.getInstance().setDesignResolutionSize(designSize.width, designSize.height, cc.RESOLUTION_POLICY.SHOW_ALL);

    director.setDisplayStats(this.config['showFPS']);
    director.setAnimationInterval(1.0 / this.config['frameRate']);

    director.runWithScene(cc.SplashScreen.create());

    return true;
  }
});

var app = new cocos2dApp();