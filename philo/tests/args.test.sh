#!/bin/bash

. $(dirname $0)/utils/assert.sh

assert_stderr "./philo" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1 1" "Error: Wrong number of arguments"
assert_stderr "./philo 1 1 1 1" ""
assert_stderr "./philo 1 1 1 1 1" ""
assert_stderr "./philo 0 1 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 0.1 1 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 1 c 1 1 1" "Error: Invalid arguments"
assert_stderr "./philo 0 0 0 0 0" "Error: Invalid arguments"
