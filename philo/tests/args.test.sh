#!/bin/bash

. $(dirname $0)/utils/assert.sh

assert_stderr "./philo 1 1 1 1" ""
assert_stderr "./philo 1 1 1 1 1" ""
assert_stderr "./philo 2 8 2 2" ""
assert_stderr "./philo 5 8 2 2 7" ""

assert_stderr "./philo" "Error: Wrong number of arguments"
assert_stderr "./philo 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1 1 1 1 1" "Error: Wrong number of arguments"

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

assert_stderr "./philo 2147483648 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 2147483648 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 2147483648 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 2147483648" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 2147483648" "Error: Invalid arguments"

assert_stderr "./philo -2147483649 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 -2147483649 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 -2147483649 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 -2147483649" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 -2147483649" "Error: Invalid arguments"

assert_stderr "./philo 999999999999999 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 999999999999999 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 999999999999999 1" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 999999999999999" "Error: Invalid arguments"
assert_stderr "./philo 1 1 1 1 999999999999999" "Error: Invalid arguments"
