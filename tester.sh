#!/bin/bash

# توليد 500 رقم عشوائي مميز
generate_numbers() {
  numbers=()
  used=()
  count=0

  while [ $count -lt 500 ]; do
    num=$((RANDOM % 1000)) # أرقام بين 0 و 999
    if [[ -z "${used[$num]}" ]]; then
      numbers+=($num)
      used[$num]=1
      ((count++))
    fi
  done

  echo "${numbers[@]}"
}

# تخزين الأرقام المولدة
numbers=$(generate_numbers)

# طباعة الأرقام
echo "Generated numbers:"
echo "$numbers"

# تشغيل push_swap مع الأرقام
echo "Running push_swap:"
output=$(./push_swap $numbers)
./push_swap $numbers | wc -l

# تشغيل checker_linux مع النتيجة
# echo "Running checker_linux:"
echo "$output" | ./checker_linux $numbers
