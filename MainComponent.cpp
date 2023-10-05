#include "MainComponent.h"
//==============================================================================
MainComponent::MainComponent()
{
    dial1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    setSize (400, 400);
    dial2.setSliderStyle(juce::Slider::Rotary);
    dial2.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider1.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    slider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible (dial1);
    addAndMakeVisible (dial2);
    addAndMakeVisible (slider1);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::aquamarine);
    juce::Rectangle<int> totalArea = getLocalBounds();
    juce::Rectangle<int> sectionArea = totalArea.removeFromTop(totalArea.getHeight() / 2);
    juce::Rectangle<int> sectionArea2 = sectionArea.removeFromLeft(sectionArea.getWidth() / 2);
    g.setColour(juce::Colours::red);
    g.drawRect(sectionArea2);

}

void MainComponent::resized()
{
    const int border = 10;
    juce::Rectangle<int> area = getLocalBounds();
    juce::Rectangle<int> dialArea = area.removeFromTop(area.getHeight()/2);
    dial1.setBounds(dialArea.removeFromLeft(area.getWidth() / 2).reduced(border));
    dial2.setBounds(dialArea.removeFromRight(area.getWidth()/2));
    slider1.setBounds(area);
}
