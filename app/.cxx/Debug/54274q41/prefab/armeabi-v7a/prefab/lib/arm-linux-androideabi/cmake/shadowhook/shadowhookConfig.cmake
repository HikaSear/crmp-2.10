if(NOT TARGET shadowhook::shadowhook)
add_library(shadowhook::shadowhook SHARED IMPORTED)
set_target_properties(shadowhook::shadowhook PROPERTIES
    IMPORTED_LOCATION "C:/Users/timil/.gradle/caches/8.9/transforms/37a142a3621b95862e6db4f3da09a3c2/transformed/shadowhook-1.0.9/prefab/modules/shadowhook/libs/android.armeabi-v7a/libshadowhook.so"
    INTERFACE_INCLUDE_DIRECTORIES "C:/Users/timil/.gradle/caches/8.9/transforms/37a142a3621b95862e6db4f3da09a3c2/transformed/shadowhook-1.0.9/prefab/modules/shadowhook/include"
    INTERFACE_LINK_LIBRARIES ""
)
endif()

