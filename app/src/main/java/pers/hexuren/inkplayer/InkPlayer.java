package pers.hexuren.inkplayer;

/**
 * Created by hexuren on 18-12-7.
 */

public class InkPlayer {

    public native static void open(String path);

    static {
        System.loadLibrary("inkplayer");
    }
}
