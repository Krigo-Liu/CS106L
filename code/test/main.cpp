#include <iostream>
#include <sstream>

using namespace std;

void stringToIntegerTest();
void printStateBits(const istream& iss);
void bufferedExperiment(ostream& oss);
int mindlessWork();
int stringToInteger(const string& s);


int main(){
    // ostringstream oss("Ito-En Green Tea", ostringstream::ate);
    // cout << oss.str();

    // oss << " is my favorite drink!";
    // cout << oss.str() << endl;

    // istringstream iss("16.9 Ounces");

    // double amount;
    // double unit;

    // iss >> amount;
    // iss >> unit;

    // cout << "Amount / 2: " << amount / 2 << endl;

    // stringToIntegerTest();

    bufferedExperiment(cout);

    return 0;
}

// the purpose of this function is to
// experiment with cout vs. cerr
// which are both types of ostreams
// we covered this optional topic at the end of lecture
void bufferedExperiment(ostream& oss) {
    oss << "CS";
    mindlessWork();

    oss << "106";
    mindlessWork();

    // oss << flush;
    // mindlessWork();

    oss << "L";
    mindlessWork();

    oss << endl;
    // mindlessWork();
}

// This is how I feel about my classes this quarter
// This function acts as a pause so you can more clearly see the interesting
// parts around this call, such as the buffering above.
// This is probably a life lesson about mindless work.
int mindlessWork() {
    double sum = 0;
    for (int i = 0; i < 400000000; ++i) {
        sum += i/999959;
        // large prime number so compiler can't optimize :)
    }
    return sum;
}

int stringToInteger(const string& s) {
    istringstream iss(s);
    printStateBits(iss);
    
    int result;
    // iss >> result; // problem: what if this fails?
    if (!(iss >> result)) 
        throw std::domain_error("no valid int at the beginning!");

    char remain;
    // iss >> remain;
    if(iss >> remain) 
        throw std::domain_error("more than a single valid int");

    // printStateBits(iss);

    return result;
}

void stringToIntegerTest() {
    while (true) {
        cout << "Type in an integer: ";
        string s;
        if (!getline(cin, s)) throw std::domain_error("getline failed");
        cout << "You typed in: " << s << "\n";
        int result = stringToInteger(s);
        cout << "As an integer, this is: " << result << "\n";
        cout << "Half of that is: " << result/2 << "\n";
    }

}

void printStateBits(const istream& iss) {
    cout << "State bits: ";

    /*
     *
     * Quick syntax lesson (Keith will teach this too!)
     * TERNARY OPERATOR
     * The following are equivalent:
     * [boolean] ? [statement 1] : [statement 2]
     *
     * if (boolean) {
     *     statement1
     * } else {
     *     statement2
     * }
     *
     * Many people (understandably) hate it, but it makes some expressions super short.
     *
     * int i = 0;
     * if (x > 100) i = 3;
     * else i = 5
     *
     * can replaced by...
     *
     * int i = (x > 100) ? 3 : 5;
     *
     */

    cout << (iss.good() ? "G" : "-");
    cout << (iss.fail() ? "F" : "-");
    cout << (iss.eof() ? "E" : "-");
    cout << (iss.bad() ? "B" : "-");
    cout << '\n';
    cout << "-----------" << '\n';
    // automatically flushed! why?
}
