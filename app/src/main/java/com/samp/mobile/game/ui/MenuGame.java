package com.samp.mobile.game.ui;

import android.app.Activity;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.nvidia.devtech.NvEventQueueActivity;
import com.samp.mobile.R;
import com.samp.mobile.launcher.other.Util;

import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Formatter;

public class MenuGame {
    public Activity activity;
    public ConstraintLayout menu_layout;
    public ImageView btn_playYY;


    public MenuGame(Activity aactivity) {
        activity = aactivity;
        menu_layout = aactivity.findViewById(R.id.menu_layout);
        btn_playYY = activity.findViewById(R.id.btn_playYY);

        Util.HideLayout(menu_layout, false);
    }

    public native void connectServer(int serverid);

    public void MenuGUpdate()
    {
        btn_playYY.setOnClickListener(view -> {
            connectServer(1);
        });
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

