#!/bin/bash

. $(dirname $0)/utils/assert.sh

assert_stderr "./philo" "Error: Wrong number of arguments"
assert_stderr "./philo 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1 1 1 1 1" "Error: Wrong number of arguments"

assert_stderr "./philo 1 1 1 1" ""
assert_stderr "./philo 1 1 1 1 1" ""
assert_stderr "./philo 200 800 200 200" ""
assert_stderr "./philo 5 800 200 200 7" ""

assert_stderr "./philo 0 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 0 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 0 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 0" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 0" "Error: Invalid arguments"
assert_stderr "./philo 0 0 0 0" "Error: Invalid arguments"
assert_stderr "./philo 0 0 0 0 0" "Error: Invalid arguments"

assert_stderr "./philo -1 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 -1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 -1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 -1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 -1" "Error: Invalid arguments"

assert_stderr "./philo a 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 a 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 a 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 a" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 a" "Error: Invalid arguments"

assert_stderr "./philo 1a 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1a 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1a 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1a" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 1a" "Error: Invalid arguments"

assert_stderr "./philo 1.0 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1.0 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1.0 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1.0" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 1.0" "Error: Invalid arguments"

assert_stderr "./philo +1 1 1 1" ""
assert_stderr "./philo 1 +1 1 1" ""
assert_stderr "./philo 1 1 +1 1" ""
assert_stderr "./philo 1 1 1 +1" ""
assert_stderr "./philo 1 1 1 1 +1" ""

assert_stderr "./philo ++1 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo --1 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 --1 1 1" "Error: Invalid arguments"

# assert_stderr "./philo 2147483648 1 1 1" "Error: Invalid arguments" # INT_MAX + 1
# assert_stderr "./philo 1 2147483648 1 1" "Error: Invalid arguments"
# assert_stderr "./philo 1 1 2147483648 1" "Error: Invalid arguments"
# assert_stderr "./philo 1 1 1 2147483648" "Error: Invalid arguments"
# assert_stderr "./philo 1 1 1 1 2147483648" "Error: Invalid arguments"

# assert_stderr "./philo 9999999999 1 1 1" "Error: Invalid arguments" # Larger than int max
# assert_stderr "./philo 1 9999999999 1 1" "Error: Invalid arguments"
# assert_stderr "./philo 1 1 9999999999 1" "Error: Invalid arguments"
# assert_stderr "./philo 1 1 1 9999999999" "Error: Invalid arguments"
# assert_stderr "./philo 1 1 1 1 9999999999" "Error: Invalid arguments"
