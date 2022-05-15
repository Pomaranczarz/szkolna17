#! /bin/bash

# Check if process with given name exists.
is_process_running() {
    if [ -z "$(pgrep $1)" ]; then
        return 1
    else
        return 0
    fi
}

delimiter="----------------------------------------"

./main 1>/dev/null &

while is_process_running main; do
    ps -Fp `pgrep main`
    sleep 1
    echo $delimiter
done