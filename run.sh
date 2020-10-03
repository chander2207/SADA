#! /bin/bash

dir="$HOME/SADA/build"
cd $dir
#ls
cmd1="make"
cmd2="make clean"
cmd3="make run"

$cmd2
$cmd1
$cmd3

