package com.example.ffmpegsample

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.arthenica.mobileffmpeg.FFmpeg

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var id = FFmpeg.execute("")

    }
}