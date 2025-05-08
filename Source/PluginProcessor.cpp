#include "PluginProcessor.h"
#include "PluginEditor.cpp"

//==============================================================================
MyPluginAudioProcessor::MyPluginAudioProcessor()
    : AudioProcessor (BusesProperties()
                      .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                      )
{
}

MyPluginAudioProcessor::~MyPluginAudioProcessor()
{
}

//==============================================================================
const juce::String MyPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MyPluginAudioProcessor::acceptsMidi() const
{
    return false;
}

bool MyPluginAudioProcessor::producesMidi() const
{
    return false;
}

bool MyPluginAudioProcessor::isMidiEffect() const
{
    return false;
}

double MyPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyPluginAudioProcessor::getNumPrograms()
{
    return 1;
}

int MyPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String MyPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void MyPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void MyPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialization that you need..
}

void MyPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MyPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear any output channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the processing of the audio data
    // For this template, we'll just pass the input through to the output
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        // Process the channel data here
    }
}

//==============================================================================
bool MyPluginAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* MyPluginAudioProcessor::createEditor()
{
    return new MyPluginAudioProcessorEditor (*this);
}

//==============================================================================
void MyPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MyPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyPluginAudioProcessor();
}