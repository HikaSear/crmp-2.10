if(NOT TARGET shadowhook::shadowhook)
add_library(shadowhook::shadowhook SHARED IMPORTED)
set_target_properties(shadowhook::shadowhook PROPERTIES
    IMPORTED_LOCATION "C:/Users/timil/.gradle/caches/8.9/transforms/1325c613e119b9eaf83b82fcbec84239/transformed/shadowhook-1.0.9/prefab/modules/shadowhook/libs/android.arm64-v8a/libshadowhook.so"
    INTERFACE_INCLUDE_DIRECTORIES "C:/Users/timil/.gradle/caches/8.9/transforms/1325c613e119b9eaf83b82fcbec84239/transformed/shadowhook-1.0.9/prefab/modules/shadowhook/include"
    INTERFACE_LINK_LIBRARIES ""
)
endif()

