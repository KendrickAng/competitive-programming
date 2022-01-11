#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if ((year % 100) == 0 && (year % 400) != 0) {
        return false;
    }
    else if ((year % 4) == 0 && (year % 100) != 0) {
        return true;
    }
    else if ((year % 4) != 0) {
        return false;
    }
    throw runtime_error("leap year error");
}

bool isValid(Date &d) {
    if (d.year >= 2000 && d.month >= 1 && d.month <= 12) {
        int m = d.month;
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return d.day >= 1 && d.day <= 30;
        }
        else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            return d.day >= 1 && d.day <= 31;
        }
        else if (m == 2 && isLeapYear(d.year)) {
            return d.day >= 1 && d.day <= 29;
        }
        else if (m == 2 && !isLeapYear(d.year)) {
            return d.day >= 1 && d.day <= 28;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        vector<Date> dates;
        int a, b, c; cin >> a >> b >> c;
        int arr[] = {a/10, a%10, b/10, b%10, c%10, (c/10)%10, (c/100)%10, (c/1000)};
        // for (auto a: arr) cout << a << " ";
        // cout << endl;

        sort(arr, arr+8);
        do {
            Date d{ arr[0]*10+arr[1], arr[2]*10+arr[3], arr[4]*1000+arr[5]*100+arr[6]*10+arr[7] };
            if(isValid(d)) {
                dates.push_back(d);
            }     
        } while (next_permutation(arr, arr+8));

        sort(dates.begin(), dates.end(), [](Date &a, Date &b) {
            if (a.year != b.year) return a.year < b.year;
            if (a.month != b.month) return a.month < b.month;
            if (a.day != b.day) return a.day < b.day;
            return false;
        });
        
        if (dates.size() > 0) {
            cout << dates.size();
            // cout << right << setfill('0') << setw(2); 
            cout << " " << setfill('0') << setw(2) << dates[0].day;
            cout << " " << setfill('0') << setw(2) << dates[0].month;;
            // cout << setfill('0') << setw(4); 
            cout << " " << setfill('0') << setw(4) << dates[0].year << endl;
            // cout << left << setfill(' ') << setw(0);
        }
        else {
            cout << "0" << endl;
        }
    }
}