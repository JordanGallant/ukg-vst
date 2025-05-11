#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyPluginAudioProcessorEditor::MyPluginAudioProcessorEditor (MyPluginAudioProcessor& p)//Constructor
    : AudioProcessorEditor (&p), audioProcessor (p),
    keyboardComponent (keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
    
{
    
setSize (1200, 800);
addAndMakeVisible(myButton);
addAndMakeVisible(keyboardComponent);  
myButton.setButtonText("Close");  

}


MyPluginAudioProcessorEditor::~MyPluginAudioProcessorEditor() //Destructor - closes UI
{
}

//==============================================================================

void MyPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour(30, 30, 30)); // Custom dark grey background

    g.setColour(juce::Colours::white);  // Text color
    g.setFont(15.0f);
    g.drawFittedText("UKG Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void MyPluginAudioProcessorEditor::resized() // visual components btn knobs
{
    int keyboardHeight = 100;

    keyboardComponent.setBounds(0, getHeight() - keyboardHeight, getWidth(), keyboardHeight);

    myButton.setBounds(550, 200, 120, 40); 


}