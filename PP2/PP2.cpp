#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Domain boundaries

const double a = -1.0;
const double b = 1.0;

// Calculates the sum of the power series for a given point and precision.
// Parameters:
// x - The real number in the domain [-1; 1] for which the series is evaluated.
// eps - The required precision (epsilon) to stop the calculation.
// Returns the calculated value of the series sum.

double s(double x, double eps) {
    double term = (x * x * x) / 6.0;
    double sum = term;
    int n = 1;

    while (term >= eps || term <= -eps) {
        term = term * (n + 1.0) * x / (n * (n + 3.0));
        sum += term;
        n++;
    }

    return sum;
}

// Prompts the user to input the value of x and validates it.
// Returns the validated real number x within the domain [-1; 1].
// Throws runtime_error if the input is not a valid number or falls outside the domain.

double get_x() {
    double x;
    cout << "Enter a real from [-1; 1]: ";
    cin >> x;

    if (cin.fail()) {
        throw runtime_error("('At time of getting x', 'Input error: not a valid number.')");
    }
    if (x < a || x > b) {
        throw runtime_error("('At time of getting x', 'Incorrect value: out of domain [-1; 1].')");
    }

    return x;
}
// Prompts the user to input the precision value (eps) and validates it.
// Returns the validated precision value which is strictly greater than 0.
// Throws runtime_error if the input is not a valid number or is not positive.

double get_eps() {
    double eps;
    cout << "Enter positive eps: ";
    cin >> eps;

    if (cin.fail()) {
        throw runtime_error("('At time of getting eps', 'Input error: not a valid number.')");
    }
    if (eps <= 0.0) {
        throw runtime_error("('At time of getting eps', 'Incorrect value: must be greater than 0.')");
    }

    return eps;
}

// The main entry point of the program.
// Handles user interaction, coordinates the input validation, calls the 
// series calculation function, and prints the formatted results or error messages.

int main() {
    cout << "The author of this program is Oleksiy Kozachenko ITK-11." << endl;
    cout << "Variant 167." << endl;
    cout << "This program calculates the value of the series." << endl;

    try {
        double x = get_x();
        double eps = get_eps();

        cout << endl << "***** do calculations ... ";
        double result = s(x, eps);
        cout << "done" << endl;

        cout << "for x = " << scientific << setprecision(7)
            << uppercase << x << endl;
        cout << "for eps = " << scientific << setprecision(9)
            << uppercase << eps << endl;
        cout << "result = " << fixed << setprecision(8)
            << result << endl;

    }
    catch (const runtime_error& e) {
        cout << endl << "***** error" << endl;
        cout << e.what() << endl;
    }

    return 0;
}