#include <stdio.h>

float milesToKilometers(float distanceInMiles);
float kilometersToMiles(float distanceInKilometers);
float hpToWatts(float workInHP);
float kmhToMps(float speedInKmh);
float fahrenheitToCelsius(float tempInfahrenheit);

int main() {
    printf("100 miles is %.3f kilometers\n", milesToKilometers(100));
    printf("100 kilometers is %.3f miles\n", kilometersToMiles(100));
    printf("100 HP (KM) is %.3f Watts\n", hpToWatts(100));
    printf("100 km/h is %.3f m/s\n", kmhToMps(100));
    printf("100 degrees Fahrenheit is %.3f degrees Celsius\n", fahrenheitToCelsius(100));

    return 0;
}

float milesToKilometers(float distanceInMiles) {
    return distanceInMiles * 0.625;
}

float kilometersToMiles(float distanceInKilometers) {
    return distanceInKilometers * 1.6;
}

float hpToWatts(float workInHP) {
    return workInHP * 735;
}

float kmhToMps(float speedInKmh) {
    float conversionFactor = 5.f / 18.f;
    return speedInKmh * conversionFactor;
}

float fahrenheitToCelsius(float tempInfahrenheit) {
    return tempInfahrenheit * 5.f / 9.f * (tempInfahrenheit - 32);
}