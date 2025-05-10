# 🎛️ My JUCE VST Plugin

This is a VST plugin project built using [JUCE](https://juce.com/) and CMake. It includes support for standard VST3 builds and uses [Pluginval](https://github.com/Tracktion/pluginval) to validate plugin stability.

#SET UP
1. create a build folder
  ```bash
  mkdir build
  ```
2. compile
   ```bash
   cmake ..
   ```
3. build
   ```bash
   cmake build
   ```
4 copy the binary to vst location
```bash
cp build/MyPlugin_artefacts/Debug/VST3/MyPlugin.vst3 ~/Library/Audio/Plug-Ins/VST3/
```
5.donwload pluginval binary - latest for your operating system 

