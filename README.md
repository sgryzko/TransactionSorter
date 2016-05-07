# TransactionSorter

#Project Background:

My girlfriend and I have a joint credit card. Each bill, we have to calculate who owes what. To do that, we used to go through the transactions one-by-one and add up which ones were just for her, which ones were just for me, and which ones were joint expenses. This app automates that.

##How to build:

The app can be built as follows:

 1. Get the source code from [https://github.com/sgryzko/TransactionSorter](https://github.com/sgryzko/TransactionSorter).
 2. Open TransactionSorter.sln in Visual Studio 2015.
 3. Build the solution.
 4. Check that CommandLineInterface.exe now exists in the folder TransactionSorter\Debug or TransactionSorter\Release.

##How to get your transactions:

American Express allows exporting of transactions into a simple csv file. Assuming you're an Amex cardholder, this can be done as follows:

 1. Log in to "Cards - My Account" at [americanexpress.co.uk](americanexpress.co.uk).
 2. Go to Your Statement -> Export Statement Data.
 3. Choose CSV, choose your card, then choose the date period(s) you'd like to sort.
 4. Click Download Now.
 5. To make things easier for later, copy the path of the downloaded CSV file to the clipboard.

##How to sort your transactions:

Once you have built the project and downloaded your transactions, you're ready for sorting:

 1. Run CommandLineInterface.exe. If you can't find it, see the **How to build** section.
 2. Follow the instructions on-screen, pasting in the path of the CSV file then sorting your transactions one-by-one.
 3. Note the totals for each category.
 4. Pay your bill!

##How to test the code:

The business logic of the app can be tested as follows:

 1. Follow the instructions in the **How to build** section.
 2. All tests are contained in the UnitTests project. To run them from Visual Studio 2015, go to Test -> Run -> All Tests.
 3. All tests should pass. If not, I've done something terribly wrong and please [post an issue on github](https://github.com/sgryzko/TransactionSorter/issues)!
 
##Future development:

For upcoming fixes and features, see [github](https://github.com/sgryzko/TransactionSorter/issues).

##Acknowledgements:

A big thank you to the following people for their feedback on my code!

 - [Ryan Selk](http://ryanselk.com/)
 - [Konstantinos Stavrou](https://www.strava.com/athletes/3006669)
