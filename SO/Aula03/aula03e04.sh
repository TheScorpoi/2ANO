#!/bin/bash 
#This script does a very simple test for checking disk space.
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | tail -1 | cut -d "%" -f1 -)
echo "largest occupied space = $space%" 
case $space in
	[1-6]*)
       Message="All OK."       
	;;
     	[7-8]*)
       Message="Cleaning out. There's a partition that is $space % full."     
	;;
   	9[0-8]*)
       Message="Better buy a new disk...  One partition is $space % full."     
  	;;
     	99)
       Message="I'm drowning here!  There's a partition at $space %!"      
 	;; 
    	*)
       Message="I seem to be running with an nonexistent disk..."       
	;;
esac
echo $Message

size=$(df -h | awk '{print $2}' | grep G |grep -v Size | sort -n | tail -1 )
echo "largest occupied size = $size"


name2=$(df -h | awk '{print $2 $1}' | grep G |grep -v Size | sort -n | tail -1 | cut -d "G" -f2 -)
echo "name of largest occupied size = $name2"
