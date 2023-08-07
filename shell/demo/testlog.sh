#!/bin/bash

retract="    "

_event() {
  # author is event's producer.
  # level is even's class.
  # message is event's title.
  # description is event's detail description.
  local author level message description
  author=${1:-unknown}; shift
  level=${1:-info}; shift
  message=${1}; shift
  description="$@"
  echo "`date  "+%Y-%m-%d %H:%M:%S(%z)"` $level ($author) $message"
  echo -e "$retract$description"
}

_event test debug "print message" "dedemdo
dededde
deded
dedededede"