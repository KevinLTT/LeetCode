#!/bin/bash
sed '/^#include.*/d' ~/Desktop/Project/LeetCode/main.cpp | sed '/^int\ main.*/,$d' | xsel -ib
