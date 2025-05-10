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

void MyPluginAudioProcessorEditor::paint (juce::Graphics& g) //text color - need to access graphics
{
    // Fill the background with a dark color
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId)); // same color

    g.setColour (juce::Colours::white); //text color white
    g.setFont (15.0f); //sets fonts
    g.drawFittedText ("UKG Plugin", getLocalBounds(), juce::Justification::centred, 1); //position of text
}

void MyPluginAudioProcessorEditor::resized() // visual components btn knobs
{
    int keyboardHeight = 100;

    keyboardComponent.setBounds(0, getHeight() - keyboardHeight, getWidth(), keyboardHeight);

    myButton.setBounds(550, 200, 120, 40); 


}