# TransactionSorter

#Project Background:

My girlfriend and I have a joint credit card. Each bill, we have to calculate who owes what. To do that, we used to go through the transactions one-by-one and add up which ones were just for her, which ones were just for me, and which ones were joint expenses. This app automates that.

##How to build:

The app can be built as follows:

 1. Get the source code from [https://github.com/sgryzko/TransactionSorter](https://github.com/sgryzko/TransactionSorter).
 2. Choose the appropriate subfolder (ex. DesktopInterface), then open the Builds folder and choose your favorite IDE. If your IDE isn't shown, open the .jucer file using Projucer from JUCE.com to generate a new Builds subfolder and use that.
 3. Build the solution.

##How to get your transactions:

American Express allows exporting of transactions into a simple csv file. Assuming you're an Amex cardholder, this can be done as follows:

 1. Log in to "Cards - My Account" at [americanexpress.co.uk](americanexpress.co.uk).
 2. Go to Your Statement -> Export Statement Data.
 3. Choose CSV, choose your card, then choose the date period(s) you'd like to sort.
 4. Click Download Now.
 5. To make things easier for later, copy the path of the downloaded CSV file to the clipboard.

##How to sort your transactions:

Once you have built the project and downloaded your transactions, you're ready for sorting:

 1. Run the executable built using the **How to build** instructions.
 2. Follow the instructions on-screen, sorting your transactions one-by-one.
 3. Note the totals for each category.
 4. Pay your bill!

##How to test the code:

The business logic of the app can be tested as follows:

 1. Follow the instructions in the **How to build** section to build the UnitTests project. 
 2. Run the executable that was built.
 3. View the test results in the console output. If any tests fail, an exception will be thrown. 
 
##Future development:

For upcoming fixes and features, see [github](https://github.com/sgryzko/TransactionSorter/issues).

##Acknowledgements:

A big thank you to the following people for their feedback on my code!

 - [Ryan Selk](http://ryanselk.com/)
 - [Konstantinos Stavrou](https://www.strava.com/athletes/3006669)
