package com.samp.mobile.launcher;

import android.app.Activity;
import android.util.Log;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.nvidia.devtech.NvEventQueueActivity;
import com.samp.mobile.R;
import com.samp.mobile.launcher.other.Util;

import android.util.Log;

public class MenuGame {
    public Activity activity;
    public ConstraintLayout menu_layout;

    public ImageView btn_play;

    public MenuGame(Activity aactivity) {
        activity = aactivity;
        menu_layout = aactivity.findViewById(R.id.menu_layout);
        btn_play = aactivity.findViewById(R.id.btn_playYY);

        /*btn_play.setOnClickListener(view -> {
            try {
                NvEventQueueActivity instance = NvEventQueueActivity.getInstance();
                if (instance != null) {
                    instance.Penis();
                    instance.togglePlayer(0);
                }
            } catch (UnsatisfiedLinkError e) {
                Log.e("MenuGame", "PIZDAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", e);
            }
        });*/
        //PIZDA

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

