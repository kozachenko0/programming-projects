#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Evaluates the expression value for variant 167.
double f(double x) {
	double part1 = cos(6.0 / 67.0);
	double part2 = ((11 * numbers::e) / (66 * numbers::pi)) * (11 / ((x + 14) * (x - 15)));
	double part3 = 10.0 * (numbers::pi / 2.0 - atan(x + 5.0));
	double part4 = (13.0 - sqrt(x + 6.0)) / (x - 12.0);

	return part1 + part2 - part3 + part4;
}

// Checks whether x is within the domain of the function.
bool is_in_domain(double x) {
	return (x >= -6.0) && (x != 12.0) && (x != 15.0);
}

int main() {
	cout << "The author of this program is Oleksiy Kozachenko ITK-11." << endl;
	cout << "This program calculates the value of the expression. Variant 167." << endl;
	cout << "Enter x (x >= -6, x != 12, x != 15): " << endl;

	double x = 0.0;
	cin >> x;

	if (cin.fail()) {
		cout << endl << "wrong input";
		return 0;
	}

	cout << endl << "***** do calculations ... ";

	double result = 0.0;
	bool defined = true;

	try {
		if (!is_in_domain(x)) {
			throw domain_error("x is out of domain");
		}
		result = f(x);
	}
	catch (const domain_error&) {
		defined = false;
	}

	cout << "done" << endl;
	cout << fixed << setprecision(5) << "for x = " << x << endl;
	if (defined) {
		cout << setprecision(9) << "result = " << result << endl;
	}
	else {
		cout << "result = undefined" << endl;
	}

	return 0;
}