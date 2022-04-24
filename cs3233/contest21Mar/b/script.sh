set -e
g++ -O2 -std=c++17 -Wall -Werror b2.cpp -o code
g++ -O2 -std=c++17 -Wall -Werror gen.cpp -o gen
g++ -O2 -std=c++17 -Wall -Werror brute.cpp -o brute
g++ -O2 -std=c++17 -Wall -Werror checker.cpp -o checker
echo "compiled."
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    ./checker > checker_log || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
echo "Checker message:"
cat checker_log