// language: Java, file: app/src/main/java/com/vanta/launcher/MainActivity.java, target: Android
package com.vanta.launcher;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.graphics.Color;
import android.view.Gravity;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setBackgroundColor(Color.parseColor("#121212"));
        layout.setGravity(Gravity.CENTER);

        TextView title = new TextView(this);
        title.setText("GLOBUS CLIENT");
        title.setTextColor(Color.parseColor("#00E5FF"));
        title.setTextSize(24);
        title.setGravity(Gravity.CENTER);
        layout.addView(title);

        Button btnInject = new Button(this);
        btnInject.setText("INJECT GLOBUS");
        btnInject.setBackgroundColor(Color.parseColor("#FF007F"));
        btnInject.setTextColor(Color.parseColor("#FFFFFF"));
        btnInject.setOnClickListener(v -> {
            OverlayBridge.RenderGlobusUI();
        });
        layout.addView(btnInject);

        setContentView(layout);
    }
}
