#include <vlc/vlc.h>
#include <windows.h>

int main()
{
    libvlc_instance_t* inst;
    libvlc_media_player_t* mp;
    libvlc_media_t* m;

    /* Load the VLC engine */
    inst = libvlc_new(0, NULL);

    /* Create a new item */
    m = libvlc_media_new_location(inst, "http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4");

    /* Create a media player playing environement */
    mp = libvlc_media_player_new_from_media(m);

    /* No need to keep the media now */
    libvlc_media_release(m);

    /* play the media_player */
    libvlc_media_player_play(mp);

    Sleep(50000);

    /* Stop playing */
    libvlc_media_player_stop(mp);

    /* Free the media_player */
    libvlc_media_player_release(mp);

    libvlc_release(inst);

    return 0;
}