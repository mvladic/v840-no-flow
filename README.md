```
git submodule add -b release/v9.2 https://github.com/lvgl/lvgl lvgl
```

```
mkdir build
cd build
emcmake cmake ..
make -j8
```