/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	std::string transactionFile = "C:\\Users\\Shane\\Documents\\Visual Studio 2015\\Projects\\TransactionSorter\\TransactionSorter.Test\\ExampleTransactionFile.csv";

	_sorter = std::make_shared<CTransactionSorter>();
	_reader = std::make_shared<CFileReader>(_sorter.get()); // TODO: Should the CFileReader take in a shared_ptr instead of a raw pointer?

	// TODO: Wrap this call and re-prompt if it doesn't work properly.
	_reader->Process(transactionFile);

	_transactionCount = _sorter->getTransactionCount();

	addAndMakeVisible(countdown);
	countdown.setJustificationType(Justification::centred);

	addAndMakeVisible(amount);
	amount.setColour(Label::backgroundColourId, Colours::black);
	amount.setColour(Label::textColourId, Colours::white);
	amount.setJustificationType(Justification::left);

	addAndMakeVisible(date);
	date.setColour(Label::backgroundColourId, Colours::black);
	date.setColour(Label::textColourId, Colours::white);
	date.setJustificationType(Justification::left);

	addAndMakeVisible(description);
	description.setColour(Label::backgroundColourId, Colours::black);
	description.setColour(Label::textColourId, Colours::white);
	description.setJustificationType(Justification::left);

	addAndMakeVisible(category1);
	category1.setButtonText("S");
	category1.setTooltip("Shane");
	category1.addListener(this);

	addAndMakeVisible(category2);
	category2.setButtonText("J");
	category2.setTooltip("Joint");
	category2.addListener(this);

	addAndMakeVisible(category3);
	category3.setButtonText("C");
	category3.setTooltip("Carolyn");
	category3.addListener(this);

	addAndMakeVisible(value1);
	addAndMakeVisible(value2);
	addAndMakeVisible(value3);

	setSize(800, 600);
	displayNextTransaction(dontSendNotification);
}

MainContentComponent::~MainContentComponent()
{
	category1.removeListener(this);
	category2.removeListener(this);
	category3.removeListener(this);
}

/*
void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText (std::to_string(_sorter->GetTotal()), getLocalBounds(), Justification::centred, true);
}*/

void MainContentComponent::resized()
{
	const int margin = 10;
	const int height = 40;
	const int totalWidth = getWidth() - 2 * margin;
	int x = margin;
	int y = margin;

	std::vector<Component*> items = { &countdown, &amount, &date, &description, &category1, &category2, &category3 };

	for each (Component* item in items)
	{
		item->setBounds(x, y, totalWidth, height);
		y += height + margin;
	}

	const int buttonWidth = height;

	std::vector<Component*> buttons = { &category1, &category2, &category3 };

	for each (Component* button in buttons)
	{
		auto buttonBounds = button->getBounds();
		button->setSize(buttonWidth, height);
	}

	y = category1.getY();
	int xOffset = buttonWidth + margin;
	x += xOffset;
	int labelWidth = totalWidth - xOffset;

	std::vector<Component*> buttonLabels = { &value1, &value2, &value3 };

	for each (Component* buttonLabel in buttonLabels)
	{
		buttonLabel->setBounds(x, y, labelWidth, height);
		y += height + margin;
	}
}


void MainContentComponent::buttonClicked(Button* button)
{
	if (button == &category1 || button == &category2 || button == &category3)
	{
		TextButton* currentButton = dynamic_cast<TextButton*>(button);
		auto group = currentButton->getTooltip().toStdString();
		_sorter->GetNextUnsortedTransaction()->SetGroup(group);

		if (button == &category1)
		{
			value1.setText(getFormattedCurrencyAmount(_sorter->GetTotal(group)), sendNotification);
		}
		else if (button == &category2)
		{
			value2.setText(getFormattedCurrencyAmount(_sorter->GetTotal(group)), sendNotification);
		}
		else if (button == &category3)
		{
			value3.setText(getFormattedCurrencyAmount(_sorter->GetTotal(group)), sendNotification);
		}
	}

	// If there are no more unsorted transactions...
	if (!displayNextTransaction(sendNotification))
	{
		// ...go into summary mode.
		category1.setEnabled(false);
		category2.setEnabled(false);
		category3.setEnabled(false);
	}
}


bool MainContentComponent::displayNextTransaction(NotificationType notificationType)
{
	int unsortedTransactionCount = _sorter->getUnsortedTransactionCount();
	bool transactionsLeftToSort = (unsortedTransactionCount > 0);

	if (transactionsLeftToSort)
	{
		int currentTransactionNumber = _transactionCount - unsortedTransactionCount + 1;
		String countdownText = "Transaction " + String(currentTransactionNumber) + " of " + String(_transactionCount);
		countdown.setText(countdownText, notificationType);

		auto nextUnsortedTransaction = _sorter->GetNextUnsortedTransaction();
		amount.setText(getFormattedCurrencyAmount(nextUnsortedTransaction->GetAmount()), notificationType);
		date.setText(nextUnsortedTransaction->GetDate(), notificationType);
		description.setText(nextUnsortedTransaction->GetDescription(), notificationType);
	}
	else
	{
		countdown.setText("All done!", sendNotification);

		const String blank = "";
		amount.setText(blank, notificationType);
		date.setText(blank, notificationType);
		description.setText(blank, notificationType);
	}

	return transactionsLeftToSort;
}

String MainContentComponent::getFormattedCurrencyAmount(const double& value)
{
	const int decimalPlaces = 2;
	String formattedAmount(value, decimalPlaces);

	return "GBP " + formattedAmount;
}
