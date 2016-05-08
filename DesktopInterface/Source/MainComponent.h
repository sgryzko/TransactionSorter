/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class CTransactionSorter;
class CFileReader;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component,
	public Button::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    //void paint (Graphics&);
    void resized();

	void buttonClicked(Button* button) override;

private:
	bool displayNextTransaction(NotificationType notificationType);
	String getFormattedCurrencyAmount(const double& value);

	std::shared_ptr<CTransactionSorter> _sorter;
	std::shared_ptr<CFileReader> _reader;

	int _transactionCount;

	Label countdown;

	Label amount;
	Label date;
	Label description;

	TextButton category1;
	Label value1;
	TextButton category2;
	Label value2;
	TextButton category3;
	Label value3;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
