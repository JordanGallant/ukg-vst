cmake_minimum_required(VERSION 3.15)

project(MyPlugin VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Support for Apple Silicon
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "")

set(JUCE_DIR "/Users/jordan/Desktop/2025/JUCE")
add_subdirectory(${JUCE_DIR} JUCE)

juce_add_plugin(MyPlugin
    COMPANY_NAME "revival records"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    PLUGIN_MANUFACTURER_CODE Revl
    PLUGIN_CODE UKGN
    FORMATS VST3
    PRODUCT_NAME "UKG"
)

# Add your source files
target_sources(MyPlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

# Link required JUCE modules
target_compile_definitions(MyPlugin
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(MyPlugin PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_audio_plugin_client
    juce::juce_dsp
    juce::juce_graphics
)

# MacOS bundle properties
juce_generate_juce_header(MyPlugin)