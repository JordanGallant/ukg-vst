#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyPluginAudioProcessorEditor::MyPluginAudioProcessorEditor (MyPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

MyPluginAudioProcessorEditor::~MyPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Fill the background with a dark color
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // Draw the plugin name
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("UKG Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void MyPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}