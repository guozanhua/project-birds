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

cc.Achievements = cc.Popup.extend({
    init:function(p_Parent) {
        this._super(p_Parent);

        this.m_Background = cc.Entity.createWithFilename(s_PopupBackground, this);
        this.m_CloseButton = cc.Entity.createWithFilename(s_PopupClose, this);

        this.m_RateText1 = cc.Text.createWithText(cc.Languages.text_temp_achievements_1, this);
        this.m_RateText2 = cc.Text.createWithText(cc.Languages.text_temp_achievements_2, this);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_CloseButton.create().setCenterPosition(cc.Options.camera.center.x + this.m_Background.getWidth() / 2 - 32, cc.Options.camera.center.y + this.m_Background.getHeight() / 2 - 32);

         this.m_RateText1.setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 250);
         this.m_RateText2.setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 150);

        this.m_CloseButton.setTouchCallback(function() {
            this.getParent().hide();
        });
    },

    onShow:function() {
        this._super();
    },
    onHide:function() {
        this._super();
    },

    update:function(dt) {
        this._super(dt);
    },

    onEnter:function() {
        this._super();
    },
    onExit:function() {
        this._super();
    }
});

cc.Achievements.create = function(p_Parent) {
    var popup = new cc.Achievements();
    popup.init(p_Parent);
    
    return popup;
};