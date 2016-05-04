#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "c:\Users\Shane\documents\visual studio 2015\Projects\TransactionSorter\TransactionSorter\TransactionSorter.h"

class MainContentComponent   : public Component,
	public Button::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    {
		sorter = CTransactionSorter();
		sorter.AddTransaction(7.73, "2016-05-03", "Tesco Groceries");
		sorter.AddTransaction(1999.00, "2016-05-03", "ROLI Seabord GRAND");
		
		auto firstTransaction = sorter.GetNextUnsortedTransaction();

		addAndMakeVisible (amount);
		amount.setColour (Label::backgroundColourId, Colours::black);
		amount.setColour (Label::textColourId, Colours::white);
		amount.setJustificationType (Justification::left);
		amount.setText (std::to_string(firstTransaction->GetAmount()), dontSendNotification);

		addAndMakeVisible (date);
		date.setColour (Label::backgroundColourId, Colours::black);
		date.setColour (Label::textColourId, Colours::white);
		date.setJustificationType (Justification::left);
		date.setText (firstTransaction->GetDate(), dontSendNotification);

		addAndMakeVisible (description);
		description.setColour (Label::backgroundColourId, Colours::black);
		description.setColour (Label::textColourId, Colours::white);
		description.setJustificationType (Justification::left);
		description.setText(firstTransaction->GetDescription(), dontSendNotification);

		addAndMakeVisible (category1);
		category1.setButtonText ("Shane");
		category1.addListener (this);

		addAndMakeVisible(category2);
		category2.setButtonText("Joint");
		category2.addListener(this);

		addAndMakeVisible(category3);
		category3.setButtonText("Carolyn");
		category3.addListener(this);

        setSize (800, 600);
    }
    
    ~MainContentComponent()
    {
		category1.removeListener(this);
		category2.removeListener(this);
		category3.removeListener(this);
    }

    void resized() override
    {
		const int margin = 10;
		const int height = 40;
		const int width  = getWidth() - 2 * margin;
		const int x      = margin;
		int currentY     = margin;

		std::vector<Component*> items = { &amount, &date, &description, &category1, &category2, &category3 };

		for each (Component* item in items)
		{
			item->setBounds(x, currentY, width, height);
			currentY += height + margin;
		}
    }

	void buttonClicked(Button* button) override
	{
		if (button == &category1)
		{
			sorter.GetNextUnsortedTransaction()->SetGroup(category1.getButtonText().toStdString());
		}
		else if (button == &category2)
		{
			sorter.GetNextUnsortedTransaction()->SetGroup(category2.getButtonText().toStdString());
		}
		else if (button == &category3)
		{
			sorter.GetNextUnsortedTransaction()->SetGroup(category3.getButtonText().toStdString());
		}
	}

private:
	Label amount;
	Label date;
	Label description;

	TextButton category1;
	Label value1;
	TextButton category2;
	Label value2;
	TextButton category3;
	Label value3;

	CTransactionSorter sorter;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED