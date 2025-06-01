@echo off
"C:\\Program Files\\Android\\Android Studio1\\jbr\\bin\\java" ^
  --class-path ^
  "C:\\Users\\vadim\\.gradle\\caches\\modules-2\\files-2.1\\com.google.prefab\\cli\\2.1.0\\aa32fec809c44fa531f01dcfb739b5b3304d3050\\cli-2.1.0-all.jar" ^
  com.google.prefab.cli.AppKt ^
  --build-system ^
  cmake ^
  --platform ^
  android ^
  --abi ^
  armeabi-v7a ^
  --os-version ^
  26 ^
  --stl ^
  c++_static ^
  --ndk-version ^
  26 ^
  --output ^
  "C:\\Users\\vadim\\AppData\\Local\\Temp\\agp-prefab-staging4970924831582458106\\staged-cli-output" ^
  "C:\\Users\\vadim\\.gradle\\caches\\8.9\\transforms\\1325c613e119b9eaf83b82fcbec84239\\transformed\\shadowhook-1.0.9\\prefab"
