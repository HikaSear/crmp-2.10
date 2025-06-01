package com.samp.mobile.launcher;

import android.app.Activity;
import android.view.View;
import android.widget.ImageView;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.samp.mobile.R;
import com.samp.mobile.launcher.other.Util;

public class MenuGame {
    public Activity activity;
    public ConstraintLayout menu_layout;

    public ImageView btn_play;

    public MenuGame(Activity aactivity) {
        activity = aactivity;
        menu_layout = aactivity.findViewById(R.id.menu_layout);
        btn_play = aactivity.findViewById(R.id.btn_play);

        Util.HideLayout(menu_layout, false);
    }




    public void ShowGMenu()
    {
        Util.ShowLayout(menu_layout, true);
    }

    public void HideGMenu()
    {
        Util.HideLayout(menu_layout, true);
    }
}

