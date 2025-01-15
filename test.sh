#!/bin/bash
generate_numbers() {
  numbers=()
  used=()
  count=0

  while [ $count -lt 500 ]; do
    num=$((RANDOM % 1000))
    if [[ -z "${used[$num]}" ]]; then
      numbers+=($num)
      used[$num]=1
      ((count++))
    fi
  done

  echo "${numbers[@]}"
}

numbers=$(generate_numbers)

echo "Generated numbers:"
echo "$numbers"

echo "Running push_swap:"
output=$(./push_swap $numbers)
./push_swap $numbers | wc -l

echo "Running checker:"
echo "$output" | ./checker $numbers
