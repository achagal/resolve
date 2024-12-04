#include "PluginEditor.h"
#include "PluginProcessor.h"

ResolveJUCEAudioProcessorEditor::ResolveJUCEAudioProcessorEditor(ResolveJUCEAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 300);

    // Setup logging for development
    logDisplay.setMultiLine(true);
    logDisplay.setReadOnly(true);
    logDisplay.setScrollbarsShown(true);
    addAndMakeVisible(logDisplay);
    addToLog("Plugin initialized - v31"); 

    // Automatically launch the app when the plugin is constructed
    launchResolveApp();
}

ResolveJUCEAudioProcessorEditor::~ResolveJUCEAudioProcessorEditor()
{
    if (resolveApp.isRunning())
    {
        resolveApp.kill();
    }
}

void ResolveJUCEAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void ResolveJUCEAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds().reduced(10);
    logDisplay.setBounds(bounds.reduced(0, 10));
}

void ResolveJUCEAudioProcessorEditor::launchResolveApp()
{
    // if (isResolveAppRunning())
    // {
    //     addToLog("Resolve app is already running");
    //     return;
    // }

    // // Placeholder for the path to the Tauri app
    // juce::File appFile("/path/to/your/resolve/binary"); // Update this path when you have the binary

    // if (!appFile.existsAsFile())
    // {
    //     addToLog("Resolve app not found at specified path");
    //     return;
    // }

    // // Pass relevant data to the app
    // juce::StringArray args;
    // args.add(appFile.getFullPathName()); // First argument is the executable path
    // args.add("--daw-id=" + audioProcessor.getDAWIdentifier());
    // args.add("--project-id=" + audioProcessor.getCurrentProjectId());
    // args.add("--plugin-port=" + juce::String(audioProcessor.getCommunicationPort()));

    // if (resolveApp.start(args))
    // {
    //     addToLog("Successfully launched Resolve app");
    //     handleAppCommunication();
    // }
    // else
    // {
    //     addToLog("Failed to launch Resolve app");
    // }
    return;
}

bool ResolveJUCEAudioProcessorEditor::isResolveAppRunning() const
{
    return resolveApp.isRunning();
}

void ResolveJUCEAudioProcessorEditor::handleAppCommunication()
{
    // Setup any necessary communication channels with the Tauri app
    // This could be via IPC, shared memory, or network socket
    addToLog("Setting up communication with Resolve app");
}

void ResolveJUCEAudioProcessorEditor::addToLog(const juce::String& message)
{
    auto time = juce::Time::getCurrentTime().toString(true, true, true, true);
    logDisplay.moveCaretToEnd();
    logDisplay.insertTextAtCaret(time + ": " + message + "\n");
}
