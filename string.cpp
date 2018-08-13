const string hexdigits = "0123456789ABCDEF";
cout << "Enter a series of numbers between 0 and 15 sepetated by spaces. Hit ENTER when finished: "<< endl;
string result;
string::size_type n;
while (cin >> n)
{
    if (n < hexdigits.size())
        result += hexdigits[n];
}
cout << "Your hex number is :" << result << endl;
