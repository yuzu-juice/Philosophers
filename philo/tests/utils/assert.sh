#!/bin/bash

assert_stderr() {
    local cmd="$1"
    local expected="$2"
    local stderr_capture_file
    stderr_capture_file=$(mktemp)
    local actual

    eval "$cmd" >/dev/null 2>"$stderr_capture_file"

    actual=$(cat "$stderr_capture_file")
    rm -f "$stderr_capture_file"

    if [ "$expected" != "$actual" ]; then
        echo "stderr: $cmd"
        echo "  Expected: $expected"
        echo "  Got:      $actual"
        exit 1
    fi
	return 0
}
