#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	double w = 0;
	double deg = 0;
	while (true) {
		using namespace std::this_thread;     // sleep_for, sleep_until

		deg = deg > 360 ? 0 : ++deg;
		w = (deg / 180) * M_PI;
		cout << "x: " << sin(w) * 5 << "     z:" << cos(w) * 5 << endl;
		sleep_for(100ms);
	}

}