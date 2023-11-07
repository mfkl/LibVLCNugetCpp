# A C++ LibVLC sample project using Visual Studio MSVC and NuGet

Gotcha: the libVLC headers are not (yet) 100% MSVC-friendly, so a tiny local patch is required to make this build for now. Hopefully it works out of the box soon.

Locate your Nuget-downloaded LibVLC headers at `C:\Your_Project_Path\LibVLCNugetCpp\packages\VideoLAN.LibVLC.Windows.3.0.20\build\x64\include\vlc\libvlc_media.h` and add the following line at the top of the file:

```diff
+ #if defined(_MSC_VER)
+ #include <BaseTsd.h>
+     typedef SSIZE_T ssize_t;
+ #endif
```

Press F5 and the video will play!