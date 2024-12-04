/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class ResolveJUCEAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ResolveJUCEAudioProcessorEditor (ResolveJUCEAudioProcessor&);
    ~ResolveJUCEAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void launchResolveApp();
    bool isResolveAppRunning() const;
    void handleAppCommunication();

    ResolveJUCEAudioProcessor& audioProcessor;
    juce::ChildProcess resolveApp;
    juce::TextButton launchButton;
    
    // For development/debugging
    juce::TextEditor logDisplay;
    void addToLog(const juce::String& message);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ResolveJUCEAudioProcessorEditor)
};
