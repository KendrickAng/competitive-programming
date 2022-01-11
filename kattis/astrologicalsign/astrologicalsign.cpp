#include <iostream>

std::string JAN = "Jan";
std::string FEB = "Feb";
std::string MAR = "Mar";
std::string APR = "Apr";
std::string MAY = "May";
std::string JUN = "Jun";
std::string JUL = "Jul";
std::string AUG = "Aug";
std::string SEP = "Sep";
std::string OCT = "Oct";
std::string NOV = "Nov";
std::string DEC = "Dec";

std::string sign(int date, std::string month) {
    if (month == MAR && date >= 21 || month == APR && date <= 20) {
        return "Aries";
    }
    if (month == APR && date >= 21 || month == MAY && date <= 20) {
        return "Taurus";
    }
    if (month == MAY && date >= 21 || month == JUN && date <= 21) {
        return "Gemini";
    }
    if (month == JUN && date >= 22 || month == JUL && date <= 22) {
        return "Cancer";
    }
    if (month == JUL && date >= 23 || month == AUG && date <= 22) {
        return "Leo";
    }
    if (month == AUG && date >= 23 || month == SEP && date <= 21) {
        return "Virgo";
    }
    if (month == SEP && date >= 22 || month == OCT && date <= 22) {
        return "Libra";
    }
    if (month == OCT && date >= 23 || month == NOV && date <= 22) {
        return "Scorpio";
    }
    if (month == NOV && date >= 23 || month == DEC && date <= 21) {
        return "Sagittarius";
    }
    if (month == DEC && date >= 22 || month == JAN && date <= 20) {
        return "Capricorn";
    }
    if (month == JAN && date >= 21 || month == FEB && date <= 19) {
        return "Aquarius";
    }
    if (month == FEB && date >= 20 || month == MAR && date <= 20) {
        return "Pisces";
    }
}

int main() {
    int date, n;
    std::string month;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> date >> month;
        std::cout << sign(date, month) << std::endl;
    }
}